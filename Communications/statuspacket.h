#ifndef DSTATUS_H
#define DSTATUS_H

#include "communications.h"

#include <QtCore>

using namespace std;

namespace Dynamometer
{
class DStatusPacket: public QObject
{
    Q_OBJECT

public:
    DStatusPacket(DCommunications *communications, QObject * parent = nullptr);

    int getAutoUpdateRateMs() const { return  s_autoUpdateRateMs; }

    bool getAutoUpdateEnabled() const { return s_autoUpdateEnabled; }
    QByteArray getStatusPacket() const { return s_statusPacket; }

public slots:
    void setAutoUpdateEnabled(bool autoUpdateEnabled);
    void setAutoUpdateRateMs(int autoUpdateRateMs);
    void connected(bool connected);

private slots:
    void autoUpdate();

signals:
    void statusUpdate(QByteArray s_status);

private:
    QTimer s_autoUpdateTimer;
    DCommunications *s_comms;

    QByteArray s_statusPacket;

    int s_autoUpdateRateMs = 10;
    bool s_autoUpdateEnabled = true;
    bool s_connected = false;
};

extern DStatusPacket *Status;
}

#endif // DSTATUS_H
