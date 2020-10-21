#include "dialgauge.h"
#include "channellist.h"

namespace Dynamometer
{
DDialGauge::DDialGauge(QWidget *parent) : DGauge (parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
    drawBase();
}

DDialGauge::~DDialGauge()
{
}

void DDialGauge::showContextMenu(const QPoint & point)
{
    if (!g_contextEnabled) return;
    QMenu contextMenu("Gauge Menu", this);

    // main menu structure
    contextMenu.addAction("Configure...", this, &DDialGauge::dialConfigure);
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

void DDialGauge::dialConfigure()
{
    gaugeConfigure(new DDialGauge());
    refresh();
}

void DDialGauge::bringToFront()
{
    raise();
}

void DDialGauge::sendToBack()
{
    lower();
}

void DDialGauge::contextMenuChannelSelected(QAction *action)
{
    // fetch the channel and set some basics from it to the gauge
    g_channelName = action->text().toUtf8();

    DChannel *channel = Channels->getChannel(g_channelName);

    setTitle(channel->getName());
    setChannelName(channel->getName());
    setMinimum(channel->getMinimum());
    setMaximum(channel->getMaximum());

    setLowerCriticalStart(channel->getLowerCriticalStart());
    setLowerCriticalEnd(channel->getLowerCriticalEnd());
    setLowerWarningStart(channel->getLowerWarningStart());
    setLowerWarningEnd(channel->getLowerWarningEnd());
    setValidStart(channel->getValidStart());
    setValidEnd(channel->getValidEnd());
    setUpperWarningStart(channel->getUpperWarningStart());
    setUpperWarningEnd(channel->getUpperWarningEnd());
    setUpperCriticalStart(channel->getUpperCriticalStart());
    setUpperCriticalEnd(channel->getUpperCriticalEnd());

    setAutoUpdateEnable(true);
    drawBase();
}

void DDialGauge::drawBase()
{
QPainter painter;

    g_tWidth = width();
    g_tHeight = height();

    if (g_lockAspect)
    {
        int side = qMin(width(), height());
        g_xscale = side / 1000.0;
        g_yscale = side / 1000.0;
    }
    else
    {
        g_xscale = g_tWidth / 1000.0;
        g_yscale = g_tHeight / 1000.0;
    }

    g_xTranslate = g_tWidth / 2;
    g_yTranslate = g_tHeight / 2;

    g_baseDrawing.fill(Qt::transparent);
    painter.begin(&g_baseDrawing);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.scale(1, 1);
    painter.translate(500.0, 500.0);

    // dial
    if (g_drawDialEnabled)
    {
        QRectF target(-500, -500, 1000.0, 1000.0);
        if (!g_dialImage.isNull())
        {
            QRectF source(0, 0, g_dialImage.width(), g_dialImage.height());
            painter.drawPixmap(target, g_dialImage, source);
        }
        else
        {
            painter.save();
            QBrush brush(g_dialColor);
            QPen p;
            p.setColor(QColor(0,0,0,0));
            painter.setPen(p);
            painter.setBrush(brush);
            painter.drawEllipse(-g_dialRadius, -g_dialRadius, g_dialRadius * 2, g_dialRadius * 2);
            painter.restore();
        }
    }

    // bezel
    if (g_drawBezelEnabled) drawBezel(&painter);

    if (g_lowerCriticalEnabled)
        drawArcWindow(&painter, g_lowerCriticalColor, g_lowerCriticalStart, g_lowerCriticalEnd, g_lowerCriticalRadius, g_lowerCriticalWidth);

    if (g_lowerWarningEnabled)
        drawArcWindow(&painter, g_lowerWarningColor, g_lowerWarningStart, g_lowerWarningEnd, g_lowerWarningRadius, g_lowerWarningWidth);

    if (g_validEnabled)
        drawArcWindow(&painter, g_validColor, g_validStart, g_validEnd, g_validRadius, g_validWidth);

    if (g_upperWarningEnabled)
        drawArcWindow(&painter, g_upperWarningColor, g_upperWarningStart, g_upperWarningEnd, g_upperWarningRadius, g_upperWarningWidth);

    if (g_upperCriticalEnabled)
        drawArcWindow(&painter, g_upperCriticalColor, g_upperCriticalStart, g_upperCriticalEnd, g_upperCriticalRadius, g_upperCriticalWidth);

    // minor ticks
    if (g_drawMinorTicksEnabled)
    {
        int totalMinorTicks = (g_majorTickCount-1) * g_minorTickCount + g_majorTickCount;
        drawTicks(&painter, g_minorTickColor, g_startAngle, g_endAngle, g_minorTickWidth,
                  g_minorTickLength, g_minorTickRadius, totalMinorTicks);
    }

    // major ticks
    if (g_drawMajorTicksEnabled) drawTicks(&painter, g_majorTickColor, g_startAngle, g_endAngle, g_majorTickWidth,
                                           g_majorTickLength, g_majorTickRadius, g_majorTickCount);

    //scale
    if (g_drawScaleEnabled) drawScale(&painter);

    // title
    if (g_drawTitleEnabled) drawText(&painter, g_title, g_titlePosition, g_titleFont, g_titleColor);

    // units
    if (g_drawUnitsEnabled) drawText(&painter, g_units, g_unitsPosition, g_unitsFont, g_unitsColor);

    painter.end();
    update();
}

void DDialGauge::drawBezel(QPainter *painter)
{
    painter->save();
    QRectF rectangle(-g_bezelRadius, -g_bezelRadius, g_bezelRadius * 2, g_bezelRadius * 2);
    int startAngle = 0 * 16;
    int spanAngle = 360 * 16;

    QLinearGradient linearGradient(-g_bezelRadius,-g_bezelRadius, g_bezelRadius, g_bezelRadius);
    linearGradient.setColorAt(0, g_bezelColor0);
    linearGradient.setColorAt(1, g_bezelColor1);

    QBrush brush = QBrush(linearGradient);
    QPen pen;

    pen.setColor(QColor(0,0,0,0));

    pen.setBrush(linearGradient);
    pen.setWidth(g_bezelWidth);

    painter->setPen(pen);
    painter->setBrush(linearGradient);
    painter->drawArc(rectangle, startAngle, spanAngle);
    painter->restore();
}

void DDialGauge::drawArcWindow(QPainter *painter, QColor color, qreal startValue, qreal endValue, int radius, int width)
{
    double beginAngle = g_startAngle - (g_startAngle - g_endAngle) * ((startValue - g_minimum) * (1/(g_maximum - g_minimum)));
    double endAngle = g_startAngle - (g_startAngle - g_endAngle) * ((endValue - g_minimum) * (1/(g_maximum - g_minimum)));

    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    painter->setPen(pen);

    if(beginAngle > endAngle)
        painter->drawArc(-radius, -radius, radius*2, radius*2, static_cast<int>(beginAngle * 16), static_cast<int>(endAngle - beginAngle) * 16);
    else
        painter->drawArc(-radius, -radius, radius*2, radius*2, static_cast<int>(beginAngle * 16), static_cast<int>(beginAngle - endAngle) * 16);
}

void DDialGauge::drawTicks(QPainter *painter, QColor color, qreal startAngle, qreal endAngle, int width, int length, int radius, int count)
{
    painter->save();

int top = -width / 2;
int bottom = top + width;

QPoint tick[4] = {
    QPoint(radius, top),
    QPoint(radius, bottom),
    QPoint(radius - length, bottom),
    QPoint(radius - length, top),
   };

    painter->setPen(color);
    painter->setBrush(color);
    painter->rotate(-startAngle);
    qreal deltaAngle = (static_cast<qreal>(startAngle - endAngle) / (count - 1));

    for(int i = 0; i < count; i++)
    {
        painter->drawConvexPolygon(tick, 4);
        painter->rotate(deltaAngle);
    }
    painter->restore();
}

void DDialGauge::drawScale(QPainter *painter)
{
    if (!g_drawScaleEnabled) return;

    painter->save();
    painter->setPen(g_scaleColor);
    painter->setFont(g_scaleFont);

    qreal startRad = g_startAngle * (M_PI / 180.0);
    startRad += M_PI / 2;
    qreal deltaRad = -(g_startAngle - g_endAngle) / (g_majorTickCount-1) * (M_PI / 180);
    qreal sina, cosa;

    for ( int i = 0; i < g_majorTickCount; i++ )
    {
        sina = sin(startRad + i * deltaRad);
        cosa = cos(startRad + i * deltaRad);

        qreal tickVal = g_minimum + (i * ((g_maximum - g_minimum) / (g_majorTickCount - 1)));
        QString text = QString("%1").arg(tickVal * g_scaleScale, g_scaleDigits, 'f', g_scalePrecision, g_scaleFiller);

        QFontMetricsF fm(painter->font());
        qreal w = fm.size(Qt::TextSingleLine, text).width();
        qreal h = fm.size(Qt::TextSingleLine, text).height();

        int x = static_cast<int>((g_scaleRadius * sina) - (w / 2));
        int y = static_cast<int>((g_scaleRadius * cosa) + (h / 4));
        painter->drawText(x, y, text);
    }
    painter->restore();
}

void DDialGauge::drawText(QPainter *painter, QString text, QRectF position, QFont font, QColor color)
{
   painter->save();
   painter->setFont(font);
   painter->setPen(color);
   painter->setBrush(color);
   painter->drawText(position, Qt::AlignCenter , text);
   painter->restore();
}

void DDialGauge::paintEvent(QPaintEvent *event)
{
QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(g_xTranslate, g_yTranslate);
    painter.scale(g_xscale, g_yscale);

    QRectF target(-500.0, -500.0, 1000.0, 1000.0);
    QRectF source(0, 0, 1000.0, 1000.0);

    painter.drawPixmap(target, g_baseDrawing, source);

    if (g_drawDigitalEnabled) drawDigital(&painter);
    if (g_drawNeedleEnabled) drawNeedle(&painter);
    if (g_drawNeedleHatEnabled) drawNeedleHat(&painter);
    DGauge::paintEvent(event);
}

void DDialGauge::drawDigital(QPainter *painter)
{
    if(!g_drawDigitalEnabled) return;
    QString text = QString( "%1" ).arg(g_value * g_digitalScale, g_digitalDigits, 'f', g_digitalPrecsion, g_digitalFiller);
    drawText(painter, text, g_digitalPosition, g_digitalFont, g_digitalColor);
}

void DDialGauge::drawNeedleHat(QPainter *painter)
{
    // draw needle hat
    QLinearGradient linearGrad(QPointF(-g_needleHatRadius, -g_needleHatRadius), QPointF(g_needleHatRadius * 2, g_needleHatRadius * 2));
    linearGrad.setColorAt(0, g_needleHatColor0);
    linearGrad.setColorAt(1, g_needleHatColor1);
    painter->setPen(Qt::NoPen);
    painter->setBrush(linearGrad);
    painter->drawEllipse(-g_needleHatRadius, -g_needleHatRadius, g_needleHatRadius * 2, g_needleHatRadius * 2);
}

void DDialGauge::drawNeedle(QPainter *painter)
{
    if (!g_drawNeedleEnabled) return;

    painter->save();
    double needleAngle = g_startAngle - (g_startAngle - g_endAngle) * ((g_value - g_minimum) * (1/(g_maximum - g_minimum)));
    painter->rotate(-needleAngle);
    QPolygon pts;
    pts.setPoints( 3, 0,-g_needleWidth,  0,g_needleWidth,  g_needleLength,0 );
    QPolygon shadow;
    shadow.setPoints(3, 0,-g_needleWidth/2, 0,g_needleWidth/2, g_needleLength,0);

    QRadialGradient haloGradient(0, 0, 400, 0, 0);
    haloGradient.setColorAt(0.0, g_needleColor0);
    haloGradient.setColorAt(1.0, g_needleColor1);
    QColor color = g_needleColor0;
    color.setAlpha(50);

    painter->setPen(color);
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon( pts );

    painter->setBrush(g_needleColor1);
    painter->drawConvexPolygon( shadow );

    if (g_drawNeedleHatEnabled)
    {
        // draw needle hat
        QLinearGradient linearGrad(QPointF(-g_needleHatRadius, -g_needleHatRadius), QPointF(g_needleHatRadius * 2, g_needleHatRadius * 2));
        linearGrad.setColorAt(0, g_needleHatColor0);
        linearGrad.setColorAt(1, g_needleHatColor1);
        painter->setPen(Qt::NoPen);
        painter->setBrush(linearGrad);
        painter->drawEllipse(-g_needleHatRadius, -g_needleHatRadius, g_needleHatRadius * 2, g_needleHatRadius * 2);
    }
    painter->restore();
}

void DDialGauge::resizeEvent(QResizeEvent *)
{
    drawBase();
}


}


