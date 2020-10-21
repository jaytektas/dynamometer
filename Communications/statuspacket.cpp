#include "statuspacket.h"

namespace Dynamometer
{
DStatusPacket::DStatusPacket(DCommunications *communications, QObject * parent) : QObject (parent)
{
    s_comms = communications;
    QObject::connect(&s_autoUpdateTimer, SIGNAL(timeout()), this, SLOT(autoUpdate()));
}

void DStatusPacket::autoUpdate()
{
//static DRun *run;
//static DSession *session;
//static int i = 0;
//static int r = 0;

    if (s_connected && s_autoUpdateEnabled)
    {
        s_statusPacket = s_comms->transmit('?', nullptr);
        emit statusUpdate(s_statusPacket);

//        if(r <= 5)
//        {
//            if (!i)
//            {
//                run = new DRun();
//                run->setName("Jay's test");
//                run->setDateTime(QDateTime::currentDateTime());
//                run->setComment("test file for shits and giggles");
//            }

//            if (i++ < 1000)
//            {
//                run->addStatusPacket(s_statusPacket);
//            }
//            else // save the run
//            {
//                run->save(QString("run %1").arg(r));
//                delete run;
//                i = 0; // new run
//                r++;
//            }
//        }
    }
}

void DStatusPacket::setAutoUpdateRateMs(int updateRateMS)
{
    s_autoUpdateRateMs = updateRateMS;

    if (s_autoUpdateTimer.isActive())
        s_autoUpdateTimer.start(updateRateMS);
}

void DStatusPacket::connected(bool connected)
{
    if (connected)
    {
        if (!s_connected)
        {
            if (s_autoUpdateEnabled)
                s_autoUpdateTimer.start(s_autoUpdateRateMs);
        }
    }
    else
    {
        s_autoUpdateTimer.stop();
    }

    s_connected = connected;
}

void DStatusPacket::setAutoUpdateEnabled(bool autoUpdateEnabled)
{
    if (autoUpdateEnabled)
    {
        if (!s_autoUpdateEnabled)
        {
            if (s_connected)
                s_autoUpdateTimer.start(s_autoUpdateRateMs);
        }
    }
    else // being disabled
    {
        s_autoUpdateTimer.stop();
    }
    s_autoUpdateEnabled = autoUpdateEnabled;
}
}
