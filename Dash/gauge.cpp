#include "gauge.h"
#include <QVariant>
#include <QMetaObject>
#include <QMetaProperty>

#include "channellist.h"
#include "widgetconfig.h"

namespace Dynamometer
{
DGauge::DGauge(QWidget *parent) : DWidgetContainer(parent)
{
    setScalingEnabled(true);
    setMinimumSize(QSize(80,80));
    QObject::connect(&g_autoUpdateTimer, &QTimer::timeout, this, &DGauge::autoUpdate);
}

void DGauge::gaugeConfigure(DGauge *display)
{
    DWidgetConfig gc(this, display);
    gc.exec();
}

void DGauge::setValue(qreal value)
{
    if (value > g_maximum) value = g_maximum;
    if (value < g_minimum) value = g_minimum;

    // have we changed?
    if(value < g_value || value > g_value)
    {
        g_value = value;
        update();
    }
}

void DGauge::setAutoUpdateEnable(bool autoUpdateEnable)
{
    if (autoUpdateEnable)
    {
        if (!g_autoUpdateEnabled)
            g_autoUpdateTimer.start(g_autoUpdateRateMs);
    }
    else
    {
        if (g_autoUpdateEnabled)
            g_autoUpdateTimer.stop();
    }
    g_autoUpdateEnabled = autoUpdateEnable;
}

void DGauge::autoUpdate()
{
    if (!g_channelName.isEmpty())
    {
        DChannel *channel = Channels->getChannel(g_channelName);
        if (channel) setValue(channel->getValue());
    }
}

void DGauge::save(QDataStream &out) const
{
    const QMetaObject *mo = metaObject();

    int count = 0;
    for (int i = 0; i < mo->propertyCount(); i++)
    {
        QMetaProperty mp = mo->property(i);
        if (mp.isUser())
            count++;
    }

    out << count;

    for (int i = 0; i < mo->propertyCount(); i++)
    {
        QMetaProperty mp = mo->property(i);
        if (mp.isUser())
            out << mp.name() << mp.read(this);
    }
}

void DGauge::load(QDataStream &in)
{
    int count = 0;
    in >> count;

    for (int i = 0; i < count; i++)
    {
        QByteArray name;
        QVariant value;
        in >> name;
        in >> value;
        setProperty(name, value);
    }
}

QDataStream & operator<< (QDataStream & out, const DGauge & gauge)
{
    gauge.save(out);
    return out;
}

QDataStream & operator>> (QDataStream & in, DGauge & gauge)
{
    gauge.load(in);
    return in;
}


}
