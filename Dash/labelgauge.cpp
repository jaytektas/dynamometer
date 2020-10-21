#include "labelgauge.h"

#include "channellist.h"

namespace Dynamometer
{
DLabelGauge::DLabelGauge(QWidget *parent): DGauge(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setMouseTracking(true);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
    setMinimumSize(QSize(20,20));
}

DLabelGauge::~DLabelGauge()
{

}


void DLabelGauge::showContextMenu(const QPoint & point)
{
    if (!g_contextEnabled) return;
    QMenu contextMenu("Gauge Menu", this);

    // main menu structure
    contextMenu.addAction("Configure...", this, SLOT(labelConfigure()));
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

void DLabelGauge::labelConfigure()
{
    gaugeConfigure(new DLabelGauge());
    refresh();
}

void DLabelGauge::bringToFront()
{
    raise();
}

void DLabelGauge::sendToBack()
{
    lower();
}

void DLabelGauge::contextMenuChannelSelected(QAction *action)
{
    // fetch the channel and set some basics from it to the gauge
    g_channelName = action->text().toUtf8();

    DChannel *channel = Channels->getChannel(g_channelName);

    //setTitle(channel->getName());
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
}

void DLabelGauge::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(0, 0);

    painter.save();
    painter.setPen(g_validColor);

    if (g_lowerCriticalEnabled && g_value >= g_lowerCriticalStart && g_value < g_lowerCriticalEnd)
        painter.setPen(g_lowerCriticalColor);

    if (g_lowerWarningEnabled && g_value >= g_lowerWarningStart && g_value < g_lowerWarningEnd)
        painter.setPen(g_lowerWarningColor);

    if (g_upperWarningEnabled && g_value >= g_upperWarningStart && g_value < g_upperWarningEnd)
        painter.setPen(g_upperWarningColor);

    if (g_upperCriticalEnabled && g_value >= g_upperCriticalStart && g_value < g_upperCriticalEnd)
        painter.setPen(g_upperCriticalColor);

    painter.setFont(g_labelFont);

    if (!g_channelName.isEmpty())
        g_label.sprintf(g_format, g_value);

    QFontMetricsF fm(painter.font());
    qreal w = fm.size(Qt::TextSingleLine, g_label).width();
    qreal h = fm.size(Qt::TextSingleLine, g_label).height();
    painter.scale(width() / w, height() / h);
    painter.drawText(0, static_cast<int>(h * .8), g_label);
    painter.restore();
    painter.end();
    DGauge::paintEvent(event);
}

void DLabelGauge::resizeEvent(QResizeEvent *)
{
    update();
}




}
