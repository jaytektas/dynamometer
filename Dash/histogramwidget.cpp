#include "histogramwidget.h"
#include "channellist.h"
#include "widgetconfig.h"
#include "communications.h"
#include "histogramconfig.h"

#include <QChartView>

namespace Dynamometer
{
DHistogramWidget::DHistogramWidget(QWidget *parent) : QChartView (parent)
{
    setParent(parent);

    setMinimumSize(QSize(80,80));
    setAcceptDrops(true);

    setContextMenuPolicy(Qt::CustomContextMenu);
    setMouseTracking(false);

    chart()->layout()->setContentsMargins(0, 0, 0, 0);
    chart()->setBackgroundRoundness(0);

    QObject::connect(this, &QWidget::customContextMenuRequested, this, &DHistogramWidget::showContextMenu);
    QObject::connect(&h_autoUpdateTimer, &QTimer::timeout, this, &DHistogramWidget::autoUpdate);

    chart()->legend()->hide();
    chart()->setBackgroundVisible(false);
}

DHistogramWidget& DHistogramWidget::operator= (const DHistogramWidget &histogramWidget)
{
    QMap<QByteArray, DChartChannel *>::iterator chartChannel = h_chartChannels.begin();

    // reset this chart
    // detach axis / remove chartChannel

    while (chartChannel != h_chartChannels.end())
    {
        chart()->removeAxis(detachAxis((*chartChannel)->getChannelName()));
        chart()->removeSeries((*chartChannel)->getLineSeries());
        delete (*chartChannel);
        chartChannel = h_chartChannels.erase(chartChannel);
    }

    h_points = histogramWidget.h_points;
    setTitle(histogramWidget.getTitle());

    // copy chart settings
    // copy all the chart channels

    QMap<QByteArray, DChartChannel *>::const_iterator constChartChannel;

    for (constChartChannel = histogramWidget.h_chartChannels.begin(); constChartChannel != histogramWidget.h_chartChannels.end(); constChartChannel++)
    {
        DChartChannel *newChartChannel = new DChartChannel(*(*constChartChannel));
        QValueAxis *newValueAxis = new QValueAxis(this);

        newValueAxis->setTitleText((*constChartChannel)->getAxis()->titleText());
        newValueAxis->setMinorTickCount((*constChartChannel)->getAxis()->minorTickCount());
        newValueAxis->setTickCount((*constChartChannel)->getAxis()->tickCount());
        newValueAxis->setMin((*constChartChannel)->getAxis()->min());
        newValueAxis->setMax((*constChartChannel)->getAxis()->max());
        newValueAxis->setVisible((*constChartChannel)->getAxis()->isVisible());
        newValueAxis->setGridLineColor((*constChartChannel)->getAxis()->gridLineColor());
        newValueAxis->setMinorGridLineColor((*constChartChannel)->getAxis()->minorGridLineColor());
        newValueAxis->setLabelsColor((*constChartChannel)->getAxis()->labelsColor());
        newValueAxis->setLabelFormat((*constChartChannel)->getAxis()->labelFormat());
        chart()->addAxis(newValueAxis, (*constChartChannel)->getAlignment());
        newChartChannel->setAxis(newValueAxis);

        // line series
        QLineSeries *newLineSeries = new QLineSeries(this);
        newChartChannel->setLineSeries(newLineSeries);
        newLineSeries->setColor((*constChartChannel)->getLineSeries()->color());
        newLineSeries->setVisible((*constChartChannel)->getLineSeries()->isVisible());

        for (int i = 0; i != (*constChartChannel)->getLineSeries()->count(); i++)
            newLineSeries->insert(i, (*constChartChannel)->getLineSeries()->at(i));

        chart()->addSeries(newLineSeries);
        h_chartChannels.insert(constChartChannel.key(), newChartChannel);
        emit channelAdded(newChartChannel->getChannelName());
    }

    // attach horizontal / vertical axis to lineseries
    for (chartChannel = h_chartChannels.begin(); chartChannel != h_chartChannels.end(); chartChannel++)
    {
        QByteArray channelName = (*chartChannel)->getVerticalAxis();

        if (!channelName.isEmpty())
        {
            DChartChannel *verticalAxisChannel = h_chartChannels.value(channelName);
            if (verticalAxisChannel) (*chartChannel)->getLineSeries()->attachAxis(verticalAxisChannel->getAxis());
        }

        channelName = (*chartChannel)->getHorizontalAxis();

        if (!channelName.isEmpty())
        {
            DChartChannel *horizontalAxisChannel = h_chartChannels.value(channelName);
            if (horizontalAxisChannel) (*chartChannel)->getLineSeries()->attachAxis(horizontalAxisChannel->getAxis());
        }
    }
    return *this;
}

void DHistogramWidget::autoUpdateToggle()
{
    if (h_autoUpdateEnabled)
        setAutoUpdateEnable(false);
    else
        setAutoUpdateEnable(true);
}

void DHistogramWidget::showContextMenu(const QPoint & point)
{
    QMenu contextMenu("Chart Menu", this);

    QAction *action = contextMenu.addAction("Auto Update", this, &DHistogramWidget::autoUpdateToggle);

    if (h_autoUpdateEnabled)
        action->setIcon(QIcon(":/icons/stop-24.png"));
    else
        action->setIcon(QIcon(":/icons/play-24.png"));

    // channel sub menu
    QMap<QByteArray, DChartChannel *>::iterator cd;
    for (cd = h_chartChannels.begin(); cd != h_chartChannels.end(); cd++)
    {
        QAction *action = contextMenu.addAction(cd.key(), this, &DHistogramWidget::deleteChannel);
        action->setIcon(QIcon(":/icons/cross.png"));
    }

    contextMenu.addSeparator();
    if (h_contextEnabled) contextMenu.addAction("Configure...", this, &DHistogramWidget::configure);
    if (h_contextEnabled) contextMenu.addSeparator();
    if (h_contextEnabled) contextMenu.addAction("Bring to front", this, SLOT(bringToFront()));
    if (h_contextEnabled) contextMenu.addAction("Send to back", this, SLOT(sendToBack()));

    // main menu structure
    if (h_contextEnabled) contextMenu.addSeparator();
    if (h_contextEnabled) contextMenu.addAction("Delete Chart");
    if (h_contextEnabled) contextMenu.addSeparator();
    contextMenu.addAction("Clear", this, &DHistogramWidget::reset);
//    contextMenu.addAction("print", this, &DChartWidget::print);

    contextMenu.exec((mapToGlobal(point)));
}

void DHistogramWidget::reset()
{
    QMap<QByteArray, DChartChannel *>::iterator chartChannel;

    for (chartChannel = h_chartChannels.begin(); chartChannel != h_chartChannels.end(); chartChannel++)
        (*chartChannel)->getLineSeries()->removePoints(0, (*chartChannel)->getLineSeries()->count());
}

void DHistogramWidget::configure()
{
    if (!h_configureDialog)
    {
        h_configureDialog = new DHistogramConfig(this);
        h_configureDialog->exec();
        delete h_configureDialog;
        h_configureDialog = nullptr;
    }
}

void DHistogramWidget::deleteChannel()
{
    QAction *action = dynamic_cast<QAction *>(sender());

    if (action)
    {
        QByteArray channelName = action->text().toUtf8();
        DChartChannel *chartChannel = h_chartChannels.value(channelName);

        if(chartChannel)
        {
            detachAxis(chartChannel->getChannelName());
            chart()->removeSeries(chartChannel->getLineSeries());
            chart()->removeAxis(chartChannel->getAxis());
            h_chartChannels.remove(channelName);
            delete chartChannel;
            emit channelRemoved(channelName);
        }
    }
}

void DHistogramWidget::bringToFront()
{
    raise();
}

void DHistogramWidget::sendToBack()
{
    lower();
}

void DHistogramWidget::setAutoUpdateEnable(bool autoUpdateEnable)
{
    if (autoUpdateEnable)
    {
        if (!h_autoUpdateEnabled)
            h_autoUpdateTimer.start(h_autoUpdateRateMs);
    }
    else
    {
        if (h_autoUpdateEnabled)
            h_autoUpdateTimer.stop();
    }
    h_autoUpdateEnabled = autoUpdateEnable;
}

void DHistogramWidget::setAutoUpdateRateMs(int autoUpdateRateMs)
{
    h_autoUpdateRateMs = autoUpdateRateMs;
    if (h_autoUpdateEnabled) h_autoUpdateTimer.start(h_autoUpdateRateMs);
}

void DHistogramWidget::autoUpdate()
{
double x = 0;
double y = 0;

    if (!Comms->isConnected()) return;

    QMap<QByteArray, DChartChannel *>::iterator chartChannel;

    // iterate through every channel to update its value
    for (chartChannel = h_chartChannels.begin(); chartChannel != h_chartChannels.end(); chartChannel++)
    {
        if ((*chartChannel)->getPlot())
        {
            // collect the new x and y value
            DChannel *xChannel = Channels->getChannel((*chartChannel)->getHorizontalAxis());
            DChannel *yChannel = Channels->getChannel((*chartChannel)->getChannelName());

            // trim line series
            if ((*chartChannel)->getLineSeries()->count() >= h_points)
                (*chartChannel)->getLineSeries()->removePoints(0, (*chartChannel)->getLineSeries()->count() - h_points);

            if (yChannel) y = yChannel->getValue();
            if (xChannel) x = xChannel->getValue();

            if (yChannel && xChannel) (*chartChannel)->getLineSeries()->setVisible(true);
            else (*chartChannel)->getLineSeries()->setVisible(false);

            // if we have both x and y plot the point
            (*chartChannel)->getLineSeries()->append(x, y);

            // record the min and max values
            if (yChannel)
            {
                // is this the first point to be added...
                if ((*chartChannel)->getLineSeries()->count() == 1 || 1)
                {
                    (*chartChannel)->setHistoricalMin(y);
                    (*chartChannel)->setHistoricalMax(y);
                }
            }

            // auto scale
            if ((*chartChannel)->getAutoScaleAxis())
            {
                // iterate current series points for min max
                for (int i = 0; i != (*chartChannel)->getLineSeries()->count(); i ++)
                {
                    (*chartChannel)->setHistoricalMin(qMin((*chartChannel)->getHistoricalMin(), (*chartChannel)->getLineSeries()->at(i).y()));
                    (*chartChannel)->setHistoricalMax(qMax((*chartChannel)->getHistoricalMax(), (*chartChannel)->getLineSeries()->at(i).y()));
                }

                (*chartChannel)->getAxis()->setMin((*chartChannel)->getHistoricalMin());
                (*chartChannel)->getAxis()->setMax((*chartChannel)->getHistoricalMax());
            }
            else
            {
                (*chartChannel)->getAxis()->setMin((*chartChannel)->getHintMin());
                (*chartChannel)->getAxis()->setMax((*chartChannel)->getHintMax());
            }
        }
    }
}

void DHistogramWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
        event->acceptProposedAction();
    else
        event->ignore();
}

void DHistogramWidget::dropEvent(QDropEvent *event)
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

            if (!h_chartChannels.contains(channelName))
            {
                DChartChannel *chartChannel = new DChartChannel;

                chartChannel->setChannelName(channelName);

                // attach to first found horizontal axis if there is one?
                QMap<QByteArray, DChartChannel *>::iterator ii;
                QByteArray horizontalAxis;

                for (ii = h_chartChannels.begin(); ii != h_chartChannels.end(); ii++)
                {
                    if ((*ii)->getAxis()->orientation() == Qt::Horizontal)
                    {
                        horizontalAxis = (*ii)->getChannelName();
                        break;
                    }
                }

                DChannel *channel = Channels->getChannel(channelName);
                chartChannel->setAxis(new QValueAxis);

                chartChannel->getAxis()->setTitleText(channelName);

                if (channel)
                {
                    chartChannel->getAxis()->setMin(channel->getMinimum());
                    chartChannel->getAxis()->setMax(channel->getMaximum());
                    chartChannel->setHintMin(channel->getMinimum());
                    chartChannel->setHintMax(channel->getMaximum());
                    chartChannel->getAxis()->setMin(channel->getMinimum());
                    chartChannel->getAxis()->setMax(channel->getMaximum());
                    chartChannel->getAxis()->setTickCount(channel->getMajorTicks());
                    chartChannel->getAxis()->setMinorTickCount(channel->getMinorTicks());
                    chartChannel->setAutoScaleAxis(channel->getAutoScaleAxis());
                }

                h_chartChannels.insert(channelName, chartChannel);
                chartChannel->setVerticalAxis(channelName);

                // attach axis to chart
                if (horizontalAxis.isEmpty()) // no horizontal axis found so we're it
                {
                    chart()->addAxis(chartChannel->getAxis(), Qt::AlignBottom);
                    chartChannel->setAlignment(Qt::AlignBottom);
                }
                else
                {
                    chartChannel->setHorizontalAxis(horizontalAxis);
                    chart()->addAxis(chartChannel->getAxis(), Qt::AlignLeft);
                    chartChannel->setAlignment(Qt::AlignLeft);
                }

                chartChannel->setLineSeries(new QLineSeries);
                chart()->addSeries(chartChannel->getLineSeries());

                chartChannel->getLineSeries()->attachAxis(chartChannel->getAxis());

                if (!horizontalAxis.isEmpty())
                    chartChannel->getLineSeries()->attachAxis(h_chartChannels.find(horizontalAxis).value()->getAxis());
                emit channelAdded(channelName);
            }
        }
        event->acceptProposedAction();
    }
    else event->ignore();
}

void DHistogramWidget::paintEvent(QPaintEvent *event)
{
    QChartView::paintEvent(event);
    if (event->type() == QEvent::Paint)
    {
        QPainter painter(viewport());

        if (h_infocus)
        {
            QColor handleColor;
            QColor pbc = parentWidget()->palette().color(QPalette::Background);
            int g = static_cast<int>(pbc.red() * .299 + pbc.green() * .587 + pbc.blue() * .114);
            if (g > 128) handleColor = QColor(Qt::black);
            else handleColor = QColor(Qt::white);

            // Draw container selection
            painter.fillRect(0, 0, HANDLESIZE, HANDLESIZE, handleColor);
            painter.fillRect(width() - HANDLESIZE, 0, HANDLESIZE, HANDLESIZE, handleColor);
            painter.fillRect(width() - HANDLESIZE, height() - HANDLESIZE, HANDLESIZE, HANDLESIZE, handleColor);
            painter.fillRect(0, height() - HANDLESIZE, HANDLESIZE, HANDLESIZE, handleColor);
        }
    }
}

void DHistogramWidget::mousePressEvent(QMouseEvent *event)
{
    if (!h_editingEnabled) return;

    if (event->buttons() & Qt::LeftButton)
    {
        h_infocus = true;
        h_position = QPoint(event->globalX()-geometry().x(), event->globalY()-geometry().y());
        h_relativeGeometry = geometry();
        viewport()->repaint();
    }
}

void DHistogramWidget::mouseMoveEvent(QMouseEvent *event) {

    if (!h_editingEnabled) return;
    if (!h_infocus) return;

    if (!event->buttons() && Qt::LeftButton)
    {
        setCursorShape(event->pos());
        return;
    }

    QPoint toMove = event->globalPos() - h_position;

    if (event->buttons() & Qt::LeftButton)
    {
        switch (h_mode)
        {
            case MOVE:
            case NONE:
                if (toMove.x() < 0) toMove.setX(0);
                if (toMove.y() < 0) toMove.setY(0);
                if (toMove.x() > this->parentWidget()->width() - this->width())
                    toMove.setX(this->parentWidget()->width() - this->width());
                if (toMove.y() > this->parentWidget()->height() - this->height())
                    toMove.setY(this->parentWidget()->height() - this->height());

                move(toMove);
                h_relativeGeometry = geometry();
                h_parentRelativeGeometry = this->parentWidget()->geometry();
//                emit newGeometry(this->geometry());
                break;

            case RESIZETL:
            {    //Left-Top
                int newwidth = event->globalX() - h_position.x() - geometry().x();
                int newheight = event->globalY() - h_position.y() - geometry().y();
                QPoint toMove = event->globalPos() - h_position;

                if (toMove.x() < 0 || width() - newwidth < minimumWidth())
                {
                    newwidth = 0;
                    toMove.setX(x());
                }

                if (toMove.y() < 0 || height()- newheight < minimumHeight())
                {
                    newheight = 0;
                    toMove.setY(y());
                }

                resize(width() - newwidth, height() - newheight);
                move(toMove.x(), toMove.y());
                break;
            }

            case RESIZETR:
            {    //Right-Top
                int newHeight = event->globalY() - h_position.y() - y();
                int newWidth = event->x();

                QPoint toMove = event->globalPos() - h_position;

                if (toMove.y() < 0 || height() - newHeight < minimumHeight())
                {
                    newHeight = 0;
                    toMove.setY(y());
                }

                if (x() + event->x() > parentWidget()->width())
                {
                    newWidth = width();
                }

                resize(newWidth, height() - newHeight);
                move(x(), toMove.y());
                break;
            }

            case RESIZEBL:
            {    //Left-Bottom
                int newWidth = event->globalX() - h_position.x() - geometry().x();
                int newHeight = event->y();

                QPoint toMove = event->globalPos() - h_position;

                if (toMove.x() < 0 || width() - newWidth < minimumWidth())
                {
                    newWidth = 0;
                    toMove.setX(x());
                }

                if (y() + event->y() > parentWidget()->height())
                {
                    newHeight = height();
                }

                resize(width() - newWidth, newHeight);
                move(toMove.x(), y());
                break;
            }

            case RESIZEBR:
            {    //Right-Bottom
                int newWidth = event->x();
                int newHeight = event->y();

                if (x() + newWidth > parentWidget()->width())
                    newWidth = width();

                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();

                resize(newWidth, newHeight);
                break;
            }

        case RESIZEL:
        {     //Left
            int newWidth = event->globalX() - h_position.x() - geometry().x();
            QPoint toMove = event->globalPos() - h_position;

            if (toMove.x() < 0 || width() - newWidth < minimumWidth())
            {
                newWidth = 0;
                toMove.setX(x());
            }

            resize(width() - newWidth, height());
            move(toMove.x(), this->y());
            break;
        }

        case RESIZET:
        {     //Top
            int newHeight = event->globalY() - h_position.y() - geometry().y();
            QPoint toMove = event->globalPos() - h_position;

            if (toMove.y() < 0 || height()- newHeight < minimumHeight())
            {
                newHeight = 0;
                toMove.setY(geometry().y());
            }

            resize(width(), height() - newHeight);
            move(x(), toMove.y());
            break;
        }

        case RESIZER:
        {     //Right
            int newWidth = event->x();

            if (x() + newWidth > parentWidget()->width())
                newWidth = width();

            resize(newWidth, height());
            break;
        }

        case RESIZEB:
            {     //Bottom
                int newHeight = event->y();
                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();
                resize(width(), newHeight);
                break;
            }
        }
    }

    h_relativeGeometry = geometry();
    h_parentRelativeGeometry = this->parentWidget()->geometry();
//    emit newGeometry(this->geometry());
}

void DHistogramWidget::setCursorShape(const QPoint &pos)
{
    const int diff = 5;
    QRect topLeft = { 0, 0, diff, diff };
    QRect topRight = { width() - diff, 0, diff, diff };
    QRect bottomRight = { width() - diff, height() - diff, diff, diff };
    QRect bottomLeft = { 0, height() - diff, diff, diff };
    QRect top = { 0, 0, width(), diff };
    QRect right = { width() - diff, 0, diff, height() };
    QRect bottom = { 0, height() - diff, width(), diff };
    QRect left = { 0, 0, diff, height() };

    // top-left
    if (topLeft.contains(pos))
    {
        h_mode = RESIZETL;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (topRight.contains(pos))
    {
        h_mode = RESIZETR;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (bottomRight.contains(pos))
    {
        h_mode = RESIZEBR;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (bottomLeft.contains(pos))
    {
        h_mode = RESIZEBL;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (top.contains(pos))
    {
        h_mode = RESIZET;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (right.contains(pos))
    {
        h_mode = RESIZER;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (bottom.contains(pos))
    {
        h_mode = RESIZEB;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (left.contains(pos))
    {
        h_mode = RESIZEL;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else
    {
        setCursor(QCursor(Qt::ArrowCursor));
        h_mode = MOVE;
    }
}

void DHistogramWidget::focusOutEvent(QFocusEvent *)
{
    if (!h_editingEnabled) return;

    h_mode = NONE;

    h_infocus = false;
    setCursor(QCursor(Qt::ArrowCursor));
    viewport()->repaint();
}

void DHistogramWidget::keyPressEvent(QKeyEvent *e)
{
    if (!h_editingEnabled) return;
    if (e->key() == Qt::Key_Delete)
    {
        this->deleteLater();
    }

    // Moving container with arrows
    if (!QApplication::keyboardModifiers())
    {
        QPoint newPos(x(),y());

        if (e->key() == Qt::Key_Up)
        {
            newPos.setY(newPos.y() - 1);
            if (newPos.y() < 0) return;
        }

        if (e->key() == Qt::Key_Down)
        {
            newPos.setY(newPos.y() + 1);
            if (newPos.y() > parentWidget()->height() - height()) return;
        }

        if (e->key() == Qt::Key_Left)
        {
            newPos.setX(newPos.x() - 1);
            if (newPos.x() < 0) return;
        }

        if (e->key() == Qt::Key_Right)
        {
            newPos.setX(newPos.x() + 1);
            if (newPos.x() > parentWidget()->width() - width()) return;
        }

        move(newPos);
    }

    if (QApplication::keyboardModifiers() == Qt::ControlModifier) {
        if (e->key() == Qt::Key_Up)
        {
            if (height() <= minimumHeight()) return;
            resize(width(), height() - 1);
        }

        if (e->key() == Qt::Key_Down)
        {
            if (height() >= maximumHeight()) return;
            if (geometry().y() + height() >= parentWidget()->height()) return;
            resize(width(), height() + 1);
        }

        if (e->key() == Qt::Key_Left)
        {
            resize(width() - 1, height());
        }

        if (e->key() == Qt::Key_Right)
        {
            if (width() >= maximumWidth()) return;
            if (geometry().x() + width() >= parentWidget()->width()) return;
            resize(width() + 1, height());
        }
    }
}

bool DHistogramWidget::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::Show:
        h_relativeGeometry = geometry();
        if (dynamic_cast<QWidget *>(parent()))
        {
            h_parentRelativeGeometry = parentWidget()->geometry();
            h_scaleValid = true;
        }
        break;

    default:
        break;

    }

    return QChartView::event(event);
}

bool DHistogramWidget::eventFilter(QObject *obj, QEvent *evt)
{
    if (evt->type() == QEvent::Resize)
    {
        // scale geometry as parent is resized
        if (evt->type() == QEvent::Resize && obj == this->parentWidget() && h_scalingEnabled && h_scaleValid)
        {
            qreal xscale = static_cast<qreal>(parentWidget()->geometry().width()) / h_parentRelativeGeometry.width();
            qreal yscale = static_cast<qreal>(parentWidget()->geometry().height()) / h_parentRelativeGeometry.height();

            setGeometry(static_cast<int>(h_relativeGeometry.left() * xscale), static_cast<int>(h_relativeGeometry.top() * yscale),
                        static_cast<int>(h_relativeGeometry.width() * xscale), static_cast<int>(h_relativeGeometry.height() * yscale));
        }
    }
    return QChartView::eventFilter(obj, evt);
}

void DHistogramWidget::setParent(QWidget *parent)
{
    if (dynamic_cast<QWidget *>(parentWidget()))
    {
        parentWidget()->removeEventFilter(this);
        h_scaleValid = false;
    }

    QChartView::setParent(parent);

    if (dynamic_cast<QWidget *>(parentWidget()))
    {
        parentWidget()->installEventFilter(this);
        h_parentRelativeGeometry = parentWidget()->geometry();
        h_relativeGeometry = geometry();
        h_scaleValid = true;
    }
}

QValueAxis *DHistogramWidget::attachAxis(QByteArray channelName)
{
    DChartChannel *chartChannel = getChartChannels().value(channelName);
    QValueAxis *axis = chartChannel->getAxis();

    if (axis)
    {
        QMap<QByteArray, DChartChannel *>::iterator i;

        for (i = h_chartChannels.begin(); i != h_chartChannels.end(); i++)
        {
            if (axis->orientation() == Qt::Horizontal)
            {
                if ((*i)->getHorizontalAxis() == channelName)
                    (*i)->getLineSeries()->attachAxis(axis);
            }
            else
            {
                if ((*i)->getVerticalAxis() == channelName)
                    (*i)->getLineSeries()->attachAxis(axis);
            }
        }
    }
    return axis;
}

QValueAxis *DHistogramWidget::detachAxis(QByteArray channelName)
{
    DChartChannel *chartChannel = h_chartChannels.value(channelName);
    QValueAxis *axis = nullptr;

    if (chartChannel)
    {
        axis = chartChannel->getAxis();
        if (axis)
        {
            QMap<QByteArray, DChartChannel *>::iterator i;

            for (i = h_chartChannels.begin(); i != h_chartChannels.end(); i++)
                if ((*i)->getVerticalAxis() == channelName || (*i)->getHorizontalAxis() == channelName)
                    (*i)->getLineSeries()->detachAxis(axis);
        }
    }
    return axis;
}

}
