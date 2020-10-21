#include "lineargauge.h"
#include "channellist.h"

#include <QPainter>

namespace Dynamometer
{
DLinearGauge::DLinearGauge(QWidget *parent) : DGauge(parent)
{
    setMinimumSize(QSize(80,80));
    setMouseTracking(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
    QObject::connect(&g_autoUpdateTimer, SIGNAL(timeout()), this, SLOT(autoUpdate()));
}

DLinearGauge::~DLinearGauge()
{
}

void DLinearGauge::linearConfigure()
{
    gaugeConfigure(new DLinearGauge());
    refresh();
}

void DLinearGauge::showContextMenu(const QPoint & point)
{
    if (!g_contextEnabled) return;
    QMenu contextMenu("Gauge Menu", this);

    // main menu structure
    contextMenu.addAction("Configure...", this, SLOT(linearConfigure()));
    contextMenu.addSeparator();
    QMenu *channelMenu = contextMenu.addMenu("Channels");
    contextMenu.addAction("Bring to front", this, SLOT(bringToFront()));
    contextMenu.addAction("Send to back", this, SLOT(sendToBack()));
    contextMenu.addSeparator();
    contextMenu.addAction("Delete");

    // channel sub menu
    QActionGroup channelActionGroup(this);
    channelActionGroup.setExclusive(true);
    {
        QMap<QByteArray, DChannel *>::iterator channel;
        for (channel = Channels->c_channels.begin(); channel != Channels->c_channels.end(); channel++)
        {
            QAction *action = channelMenu->addAction((*channel)->getName());
            action->setCheckable(true);
            if ((*channel)->getName() == g_channelName)
                action->setChecked(true);
            channelActionGroup.addAction(action);
        }
    }

    QObject::connect(channelMenu, SIGNAL(triggered(QAction *)), this, SLOT(contextMenuChannelSelected(QAction *)));
    contextMenu.exec((mapToGlobal(point)));
}

void DLinearGauge::bringToFront()
{
    raise();
}

void DLinearGauge::sendToBack()
{
    lower();
}

void DLinearGauge::contextMenuChannelSelected(QAction *action)
{
    // fetch the channel and set some basics from it to the gauge
    g_channelName = action->text().toUtf8();

    DChannel *channel = Channels->getChannel(g_channelName);

    setChannelName(channel->getName());
    setMinimum(channel->getMinimum());
    setMaximum(channel->getMaximum());

    setScaleScale((channel->getScale()));
    setScaleDigits(channel->getDigits());
    setScaleFiller(channel->getFiller());
    setScalePrecision(channel->getPrecision());

    setLowerCriticalStart(channel->getLowerCriticalStart());
    setLowerCriticalEnd(channel->getLowerCriticalEnd());
    setLowerWarningStart(channel->getLowerWarningStart());
    setLowerWarningEnd(channel->getLowerWarningEnd());
    setUpperWarningStart(channel->getUpperWarningStart());
    setUpperWarningEnd(channel->getUpperWarningEnd());
    setUpperCriticalStart(channel->getUpperCriticalStart());
    setUpperCriticalEnd(channel->getUpperCriticalEnd());

    setAutoUpdateEnable(true);
    drawBase();
}

void DLinearGauge::paintEvent(QPaintEvent *event)
{
QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.translate(g_xTranslate, g_yTranslate);
    painter.scale(g_xscale, g_yscale);

    QRectF target(0, 0, 300.0, 1000.0);
    QRectF source(0, 0, 300.0, 1000.0);

    painter.drawPixmap(target, g_baseDrawing, source);
    painter.save();

    painter.setBrush(g_validColor);

    if (g_lowerCriticalEnabled && g_value >= g_lowerCriticalStart && g_value < g_lowerCriticalEnd)
        painter.setBrush(g_lowerCriticalColor);

    if (g_lowerWarningEnabled && g_value >= g_lowerWarningStart && g_value < g_lowerWarningEnd)
        painter.setBrush(g_lowerWarningColor);

    if (g_upperWarningEnabled && g_value >= g_upperWarningStart && g_value < g_upperWarningEnd)
        painter.setBrush(g_upperWarningColor);

    if (g_upperCriticalEnabled && g_value >= g_upperCriticalStart && g_value < g_upperCriticalEnd)
        painter.setBrush(g_upperCriticalColor);

    // draw bar
    qreal barLength = (1000.0 - (g_padding * 2)) * ((g_value - g_minimum) / (g_maximum - g_minimum));
    painter.drawRect(150 - (g_barWidth / 2), 1000 - static_cast<int>(barLength) - g_padding, g_barWidth, static_cast<int>(barLength));
    painter.restore();
    DGauge::paintEvent(event);
}

void DLinearGauge::resizeEvent(QResizeEvent *)
{
    drawBase();
}

void DLinearGauge::drawBase()
{
QPainter painter;

    g_tWidth = width();
    g_tHeight = height();

    if (g_lockAspect)
    {
        qreal side = qMin(width() / 300.0, height() / 1000.0);
        g_xscale = side;
        g_yscale = side;
    }
    else
    {
        g_xscale = g_tWidth / 300.0;
        g_yscale = g_tHeight / 1000.0;
    }

    g_xTranslate = g_tWidth / 2;
    g_yTranslate = g_tHeight / 2;

    g_baseDrawing.fill(Qt::transparent);
    painter.begin(&g_baseDrawing);
    painter.save();

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.scale(1, 1);
//    painter.translate(150.0, 500.0);

    painter.setRenderHint(QPainter::Antialiasing);

    if (g_dialEnabled)
    {
        QPainterPath path;
        if (g_bezelEnabled)
            path.addRoundedRect(QRectF(0 + (g_bezelWidth / 2), 0 + (g_bezelWidth / 2), 300 - g_bezelWidth, 1000 - g_bezelWidth), g_bezelRadius, g_bezelRadius);
        else
            path.addRoundedRect(QRectF(0, 0, 300, 1000), 80, 80);

        QPen pen(QColor(0,0,0,0));
        //painter.setPen(pen);
        painter.fillPath(path, g_dialColor);
    }

    if (g_bezelEnabled) drawBezel(&painter);

    if (g_minorTicksEnabled)
    {
        int totalMinorTicks = (g_majorTickCount-1) * g_minorTickCount + g_majorTickCount;

        painter.setPen(g_minorTickColor);
        painter.setBrush(g_minorTickColor);

        for (int i = 0; i < totalMinorTicks; i++)
        {
            qreal top = (i * (1000.0 - (g_padding * 2)) / (totalMinorTicks - 1)) + g_padding - (g_minorTickWidth / 2);
            qreal bottom = top + g_minorTickWidth;
            {
                QPoint tick[4] = {
                QPoint(150 - g_minorTickOffset, static_cast<int>(top)),
                QPoint(150 - g_minorTickOffset, static_cast<int>(bottom)),
                QPoint(150 - g_minorTickOffset - g_minorTickLength, static_cast<int>(bottom)),
                QPoint(150 - g_minorTickOffset - g_minorTickLength, static_cast<int>(top))
                };
                painter.drawConvexPolygon(tick, 4);
            }
            {
                QPoint tick[4] = {
                QPoint(150 + g_minorTickOffset, static_cast<int>(top)),
                QPoint(150 + g_minorTickOffset, static_cast<int>(bottom)),
                QPoint(150 + g_minorTickOffset + g_minorTickLength, static_cast<int>(bottom)),
                QPoint(150 + g_minorTickOffset + g_minorTickLength, static_cast<int>(top))
                };
                painter.drawConvexPolygon(tick, 4);
            }
        }
    }

    qreal segment = (1000.0 - (g_padding * 2)) / (g_majorTickCount - 1);

    for (int m = 0; m < g_majorTickCount; m++)
    {
        qreal top = (m * segment) + g_padding - (g_majorTickWidth / 2);
        qreal bottom = top + g_majorTickWidth;

        painter.setPen(g_majorTickColor);
        painter.setBrush(g_majorTickColor);

        if (g_majorTicksEnabled)
        {
            QPoint tick[4] = {
            QPoint(150 - g_majorTickOffset, static_cast<int>(top)),
            QPoint(150 - g_majorTickOffset, static_cast<int>(bottom)),
            QPoint(150 - g_majorTickOffset - g_majorTickLength, static_cast<int>(bottom)),
            QPoint(150 - g_majorTickOffset - g_majorTickLength, static_cast<int>(top))
            };
            painter.drawConvexPolygon(tick, 4);
        }

        if (g_majorTicksEnabled)
        {
            QPoint tick[4] = {
            QPoint(150 + g_majorTickOffset, static_cast<int>(top)),
            QPoint(150 + g_majorTickOffset, static_cast<int>(bottom)),
            QPoint(150 + g_majorTickOffset + g_majorTickLength, static_cast<int>(bottom)),
            QPoint(150 + g_majorTickOffset + g_majorTickLength, static_cast<int>(top))
            };
            painter.drawConvexPolygon(tick, 4);
        }

        if (g_scaleEnabled)
        {
            qreal tickVal = g_maximum - (m * ((g_maximum - g_minimum) / (g_majorTickCount - 1)));
            QString text = QString("%1").arg(tickVal * g_scaleScale, g_scaleDigits, 'f', g_scalePrecision, g_scaleFiller);

            painter.setPen(g_scaleColor);
            painter.setFont(g_scaleFont);

            QFontMetricsF fm(painter.font());
            qreal w = fm.size(Qt::TextSingleLine, text).width();
            qreal h = fm.size(Qt::TextSingleLine, text).height();

            int x1 = static_cast<int>(150 - g_majorTickOffset - g_majorTickLength - w - g_scaleOffset);
            int x2 = 150 + g_majorTickOffset + g_majorTickLength + g_scaleOffset;
            int y = static_cast<int>(top + (h/3));
            painter.drawText(x1, y, text);
            painter.drawText(x2, y, text);
        }
    }

    painter.restore();
    painter.end();
}

void DLinearGauge::drawBezel(QPainter *painter)
{
    painter->save();

    QLinearGradient linearGradient(0, 0, 300, 1000);
    linearGradient.setColorAt(0, g_bezelColor0);
    linearGradient.setColorAt(1, g_bezelColor1);

    QBrush brush = QBrush(linearGradient);
    QPen pen;

    pen.setColor(QColor(0,0,0,0));

    pen.setBrush(linearGradient);
    pen.setWidth(g_bezelWidth);

    painter->setPen(pen);
    // painter->setBrush();

    QPainterPath path;
    path.addRoundedRect(QRectF(0 + (g_bezelWidth/2), 0 + (g_bezelWidth/2), 300 - g_bezelWidth, 1000 - g_bezelWidth), g_bezelRadius, g_bezelRadius);
    painter->drawPath(path);
    painter->restore();
}

}
