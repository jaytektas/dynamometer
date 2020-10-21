#include "lcdgauge.h"
#include "channellist.h"

namespace Dynamometer
{
DLCDGauge::DLCDGauge(QWidget *parent) : DGauge(parent)
{
    g_lcdNumber.setContextMenuPolicy(Qt::CustomContextMenu);
    g_lcdNumber.setParent(this);
    g_lcdNumber.setMouseTracking(true);
    g_lcdNumber.setFrameStyle(0);
    g_lcdNumber.setGeometry(0,0,width(),height());
    g_lcdNumber.setVisible(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(&g_lcdNumber, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
}

DLCDGauge::~DLCDGauge()
{

}

void DLCDGauge::showContextMenu(const QPoint & point)
{
    if (!g_contextEnabled) return;
    QMenu contextMenu("Gauge Menu", this);

    // main menu structure
    contextMenu.addAction("Configure...", this, SLOT(LCDConfigure()));
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

void DLCDGauge::LCDConfigure()
{
    gaugeConfigure(new DLCDGauge());
    refresh();
}

void DLCDGauge::bringToFront()
{
    raise();
}

void DLCDGauge::sendToBack()
{
    lower();
}

void DLCDGauge::contextMenuChannelSelected(QAction *action)
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


void DLCDGauge::paintEvent(QPaintEvent *event)
{
    QColor c = g_validColor;

    if (g_value >= g_lowerCriticalStart && g_value < g_lowerCriticalEnd)
        c = g_lowerCriticalColor;

    if (g_value >= g_lowerWarningStart && g_value < g_lowerWarningEnd)
        c = g_lowerWarningColor;

    if (g_value >= g_upperWarningStart && g_value < g_upperWarningEnd)
        c = g_upperWarningColor;

    if (g_value >= g_upperCriticalStart && g_value < g_upperCriticalEnd)
        c = g_upperCriticalColor;

    QPalette p = g_lcdNumber.palette();
    p.setColor(QPalette::WindowText, c);
    g_lcdNumber.setPalette(p);
    g_lcdNumber.display(g_value);
    g_lcdNumber.setGeometry(0,0,width(),height());
    DGauge::paintEvent(event);
}

void DLCDGauge::resizeEvent(QResizeEvent *)
{
    g_lcdNumber.setGeometry(0,0,width(),height());
}

}
