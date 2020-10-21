#include "chartwidget.h"
#include "ui_chartwidget.h"

#include "channellist.h"
#include "chartlegend.h"

#include <QtWidgets>
#include <QPdfWriter>

namespace Dynamometer
{
DChartWidget::DChartWidget(QWidget *parent) : QChartView(parent), ui(new Ui::DChartWidget)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    chart()->layout()->setContentsMargins(0, 0, 0, 0);
    chart()->setBackgroundRoundness(0);

    DChannel *channel = Channels->getChannel(c_xAxisChannelName);
    if (channel)
    {
        c_xAxis = new QValueAxis;
        c_xAxis->setTitleText(c_xAxisChannelName);
        c_xAxis->setTickCount(channel->getMajorTicks());
        c_xAxis->setMinorTickCount(channel->getMinorTicks());
        //c_xAxis->setRange(channel->getMinimum(), channel->getMaximum());
        chart()->addAxis(c_xAxis, Qt::AlignBottom);
        chart()->legend()->hide();
    }
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, this, &DChartWidget::customContextMenuRequested);
    DChartLegend *dg = new DChartLegend;
    chart()->scene()->addWidget(dg);
    dg->setGeometry(0,0,100,100);
    dg->setParent(this);
}

DChartWidget::~DChartWidget()
{
    delete ui;
}

void DChartWidget::customContextMenuRequested(const QPoint &point)
{
    QMenu contextMenu("Chart Menu", this);

    QMenu *channelMenu = contextMenu.addMenu("Base");
    QActionGroup channelActionGroup(this);
    channelActionGroup.setExclusive(true);
    {
        QMap<QByteArray, DChannel *>::iterator channel;
        for (channel = Channels->c_channels.begin(); channel != Channels->c_channels.end(); channel++)
        {
            QAction *action = channelMenu->addAction((*channel)->getName(), this, &DChartWidget::changeBase);
            action->setCheckable(true);
            if ((*channel)->getName() == c_xAxisChannelName)
                action->setChecked(true);
            channelActionGroup.addAction(action);
        }
    }

    // channel sub menu
    QMap<QByteArray, DChannelData *>::iterator cd;
    for (cd = c_ySeries.begin(); cd != c_ySeries.end(); cd++)
    {
        QAction *action = contextMenu.addAction(cd.key(), this, &DChartWidget::deleteSeries);
        action->setIcon(QIcon(":/icons/cross.png"));
    }

    // main menu structure
    contextMenu.addSeparator();
    contextMenu.addAction("Configure...");
    contextMenu.addSeparator();
    contextMenu.addAction("Delete Chart");
    contextMenu.addSeparator();
    contextMenu.addAction("Reset", this, &DChartWidget::resetChartView);
    contextMenu.addAction("print", this, &DChartWidget::print);

    contextMenu.exec((mapToGlobal(point)));
}

void DChartWidget::print()
{
    QPdfWriter writer("out.pdf");
    writer.setCreator("JayTek");
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageOrientation(QPageLayout::Landscape);
    QPainter painter(&writer);
    render(&painter);
    painter.end();
}

void DChartWidget::deleteSeries()
{
    QAction *action = dynamic_cast<QAction *>(sender());
    DChannelData *cd = c_ySeries.value(action->text().toUtf8());

    if (cd)
    {
        // remove all run series
        for (QMap<QDateTime, DChannelRunData *>::iterator i = cd->channelRunData.begin(); i != cd->channelRunData.end(); i++)
            chart()->removeSeries((*i)->runSeries);

        chart()->removeAxis(cd->axis);
        if (cd->axis->alignment() == Qt::AlignLeft && chart()->axes(Qt::Vertical).count())
        {
            QValueAxis *tmp = dynamic_cast<QValueAxis *>(chart()->axes(Qt::Vertical).value(0));
            chart()->removeAxis(tmp);
            chart()->addAxis(tmp, Qt::AlignLeft);
        }
        // remove us
        c_ySeries.remove(cd->channelName);
        delete cd;
    }
}

void DChartWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
        event->acceptProposedAction();
    else
        event->ignore();
}

void DChartWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        QByteArray encodedData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
        QDataStream stream(&encodedData, QIODevice::ReadOnly);

        QMap<int,  QVariant> roleDataMap;
        while (!stream.atEnd())
        {
            int row, col;
            stream >> row >> col >> roleDataMap;
        }

        QMap<int, QVariant>::iterator i;
        for (i = roleDataMap.begin(); i != roleDataMap.end(); i++)
        {
            QByteArray channelName = (*i).toString().toUtf8().constData();
            if (!c_ySeries.contains(channelName))
                c_ySeries.insert(channelName, constructChannel(channelName));
        }
        event->acceptProposedAction();
    }
    else event->ignore();
}

DChartWidget::DChannelData *DChartWidget::constructChannel(QByteArray channelName)
{
    DChannelData *channelData = nullptr;
    DChannel *channel = Channels->getChannel(channelName);

    if (channel) // TODO: notify
    {
        // remove runs?
        if (c_ySeries.contains(channelName))
        {
            channelData = c_ySeries.value(channelName);
            for (QMap<QDateTime, DChannelRunData *>::iterator channelRunData = channelData->channelRunData.begin(); channelRunData != channelData->channelRunData.end();)
            {
                if (!Runs.contains(channelRunData.key()))
                {
                    chart()->removeSeries((*channelRunData)->runSeries);
                    delete (*channelRunData);
                    channelRunData = channelData->channelRunData.erase(channelRunData);
                }
                else channelRunData++;
            }
        }
        else
        {
            channelData = new DChannelData;
            channelData->channelName = channelName;
        }

        if (!channelData->axis)
        {
            channelData->axis = new QValueAxis;
            QByteArray axisTitle = channelName;
            if (!channel->getUnits().isEmpty())
                axisTitle += "(" + channel->getUnits() + ")";

            channelData->axis->setTitleText(axisTitle);
            channelData->axis->setTickCount(channel->getMajorTicks());
            channelData->axis->setMinorTickCount(channel->getMinorTicks());
            channelData->axis->setRange(channel->getMinimum(), channel->getMaximum());
            channelData->axis->setLabelFormat(channel->getLabelFormat());

            if (c_xAxis)
                if (chart()->axes().count() >= 2)
                    chart()->addAxis(channelData->axis, Qt::AlignRight);
                else
                    chart()->addAxis(channelData->axis, Qt::AlignLeft);
            else
                chart()->addAxis(channelData->axis, Qt::AlignLeft);
        }

        // add visible runs for now
        int runCount = 0;
        qreal yMinimum = 0;
        qreal yMaximum = 0;
        for (QMap<QDateTime, DRun *>::iterator run = Runs.begin(); run != Runs.end(); run++)
        {
            // is run check marked for display?
            if ((*run)->getSelected())
            {
                // if run series exists then make it visible
                if (channelData->channelRunData.contains((*run)->getDateTime()))
                {
                    channelData->channelRunData.value((*run)->getDateTime())->runSeries->setVisible(true);
                    if (!runCount)
                    {
                        yMinimum = (channelData->channelRunData.value((*run)->getDateTime())->min);
                        yMaximum = (channelData->channelRunData.value((*run)->getDateTime())->max);
                    }
                    else
                    {
                        yMinimum = qMin(yMinimum, (channelData->channelRunData.value((*run)->getDateTime())->min));
                        yMaximum = qMax(yMaximum, (channelData->channelRunData.value((*run)->getDateTime())->max));
                    }
                    if (channel->getAutoScaleAxis())
                    {
                        channelData->axis->setMin(yMinimum);
                        channelData->axis->setMax(yMaximum);
                    }
                    else
                    {
                       channelData->axis->setMin(channel->getMinimum());
                       channelData->axis->setMax(channel->getMaximum());
                    }
                }
                else
                {
                    QLineSeries *lineSeries = new QLineSeries;
                    channelData->channelRunData.insert((*run)->getDateTime(), new DChannelRunData);

                    for (size_t i = 0; i < (*run)->r_statusPackets.size(); i++)
                    {
                        Channels->setEvaluationPacket((*run)->r_statusPackets[i]);
                        qreal x = Channels->getChannel(c_xAxisChannelName)->getValue(true);
                        qreal y = Channels->getChannel(channelName)->getValue(true);

                        if (!i)
                        {
                            channelData->channelRunData.value((*run)->getDateTime())->min = y;
                            channelData->channelRunData.value((*run)->getDateTime())->max = y;
                        }
                        else
                        {
                            channelData->channelRunData.value((*run)->getDateTime())->min = qMin(y, channelData->channelRunData.value((*run)->getDateTime())->min);
                            channelData->channelRunData.value((*run)->getDateTime())->max = qMax(y, channelData->channelRunData.value((*run)->getDateTime())->max);
                        }
                        lineSeries->append(x, y);
                    }

                    if (!runCount)
                    {
                        yMinimum = channelData->channelRunData.value((*run)->getDateTime())->min;
                        yMaximum = channelData->channelRunData.value((*run)->getDateTime())->max;
                    }
                    else
                    {
                        yMinimum = qMin(yMinimum, channelData->channelRunData.value((*run)->getDateTime())->min);
                        yMaximum = qMax(yMaximum, channelData->channelRunData.value((*run)->getDateTime())->max);
                    }

                    channelData->channelRunData.value((*run)->getDateTime())->runSeries = lineSeries;
                    lineSeries->setName((*run)->getDateTime().toString("dd.MM.yy hh:mm:ss.zzz ") + channelName);
                    chart()->addSeries(lineSeries);
                    connect(lineSeries, &QLineSeries::hovered, this, &DChartWidget::hovered);
                    lineSeries->attachAxis(channelData->axis);
                    lineSeries->attachAxis(c_xAxis);

                    if (channel->getAutoScaleAxis())
                    {
                        channelData->axis->setMin(yMinimum);
                        channelData->axis->setMax(yMaximum);
                    }
                    else
                    {
                       channelData->axis->setMin(channel->getMinimum());
                       channelData->axis->setMax(channel->getMaximum());
                    }
                }
            }
            else
            {
                // if run exists then hide it
                if (channelData->channelRunData.contains((*run)->getDateTime()))
                    channelData->channelRunData.value((*run)->getDateTime())->runSeries->setVisible(false);
            }
            runCount++;
        }
    }
    // else channel is lost... what to do about axis / series...
    return channelData;
}

void DChartWidget::selectedRunsChanged()
{
    for (QMap<QByteArray, DChannelData *>::iterator i = c_ySeries.begin(); i != c_ySeries.end(); i++)
        constructChannel((*i)->channelName);
}

// pretty much destroys everything apart from vertical axes
void DChartWidget::changeBase()
{
    QAction *action = dynamic_cast<QAction *>(sender());

    if (action)
    {
        DChannel *channel = Channels->getChannel(action->text().toUtf8());
        if (channel)
        {
            c_xAxisChannelName = channel->getName();
            // change the bottom axis settings without deleting it?
            //c_xAxis->setRange(channel->getMinimum(), channel->getMaximum());
            c_xAxis->setTitleText(channel->getName());

            // reprocess all the series to change the base..
            for (QMap<QByteArray, DChannelData *>::iterator channelData = c_ySeries.begin(); channelData != c_ySeries.end(); channelData++)
               for (QMap<QDateTime, DChannelRunData *>::iterator channelRunData = (*channelData)->channelRunData.begin(); channelRunData != (*channelData)->channelRunData.end(); )
               {
                   chart()->removeSeries((*channelRunData)->runSeries);
                   channelRunData = (*channelData)->channelRunData.erase(channelRunData);
               }

            // smash the base
            chart()->removeAxis(c_xAxis);
            c_xAxis = new QValueAxis;
            c_xAxis->setTitleText(c_xAxisChannelName);
            c_xAxis->setTickCount(channel->getMajorTicks());
            c_xAxis->setMinorTickCount(channel->getMinorTicks());
            //c_xAxis->setRange(channel->getMinimum(), channel->getMaximum());
            chart()->addAxis(c_xAxis, Qt::AlignBottom);
        }


        // rebuild the chart with new base
        for (QMap<QByteArray, DChannelData *>::iterator channelData = c_ySeries.begin(); channelData != c_ySeries.end(); channelData++)
            constructChannel((*channelData)->channelName);
    }
}

void DChartWidget::hovered(QPointF point, bool state)
{
    qDebug() << point << state;
}

// auto scale all vertical axes

// auto scale a single channelName
void DChartWidget::autoScaleChannel(QByteArray channelName)
{
    // iterate through every line series for this channel and find the min max of all series
    qreal min = 0;
    qreal max = 0;
    bool valid = false;

    DChannelData *channelData = c_ySeries.value(channelName);

    if (channelData)
    {
        // iterate the visible runs and update the minmax
        for (QMap<QDateTime, DChannelRunData *>::iterator channelRunData = channelData->channelRunData.begin(); channelRunData != channelData->channelRunData.end(); channelRunData++)
        {
            if (!valid)
            {
                min = (*channelRunData)->min;
                max = (*channelRunData)->max;
                valid = true;
            }
            else
            {
                min = qMin(min, (*channelRunData)->min);
                max = qMax(max, (*channelRunData)->max);
            }
        }

        // save to the axis
        channelData->axis->setMin(min);
        channelData->axis->setMax(max);
    }
}


void DChartWidget::wheelEvent(QWheelEvent *event)
{
    qreal factor = event->angleDelta().y() > 0 ? 0.9 : 1.1;
    QRectF r = QRectF(chart()->plotArea().left(),chart()->plotArea().top(),
                                        chart()->plotArea().width()/factor,chart()->plotArea().height()/factor);
    QPointF mousePos = mapFromGlobal(QCursor::pos());
    r.moveCenter(mousePos);
    chart()->zoomIn(r);
    QPointF delta = chart()->plotArea().center() -mousePos;
    chart()->scroll(delta.x(),-delta.y());
}

void DChartWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::MouseButton::LeftButton)
    {
        chart()->zoomIn();
        chart()->zoomOut();
        int deltaX = event->x() - c_position.x();
        int deltaY = event->y() - c_position.y();
        chart()->scroll(-deltaX, deltaY);
    }
    c_position = event->pos();
}

void DChartWidget::mousePressEvent(QMouseEvent *event)
{
    c_position = event->pos();
}

void DChartWidget::resetChartView()
{
    chart()->zoomReset();
}

// we draw a custom legend cause the defautl chart legend is crap


}
