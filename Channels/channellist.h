#ifndef DCHANNELLIST_H
#define DCHANNELLIST_H

#include "channel.h"

#include <QtCore>

using namespace std;

namespace Dynamometer
{
class DChannelList : public QObject
{
    Q_OBJECT
    friend DChannel;

public:
    DChannelList(QObject *parent = nullptr);
    ~DChannelList();

    DChannel *addChannel(QByteArray name, DChannel::TYPE type, QByteArray expression, DChannel::DATA_TYPE dataType, quint16 offset, bool quiet);
    DChannel *addChannel(QByteArray name, qreal value, bool quiet);
    DChannel *addChannel(DChannel *channel, bool quiet);

    // non destructive remove from list
    DChannel *removeChannel(QByteArray name, bool quiet = false);

    // destructive removal
    bool deleteChannel(QByteArray name, bool quiet);
    void deleteAllChannels();

    void factoryChannels();

    DChannel *getChannel(QByteArray name);

    QByteArray getStatusPacket() const { return c_statusPacket; }
    quint32 getStatusPacketTimeStamp() { return c_statusPacketTimeStamp; }

    QByteArray getEvaluationPacket() const { return c_evaluationPacket; }
    quint32 getEvaluationPacketTimeStamp() { return c_evaluationPacketTimeStamp; }

    void setError(QString error) { c_error = error; }
    QString getError() const { return c_error; }

    bool getChanged() const { return c_changed; }
    void setChanged(bool changed) { c_changed = changed; }

    QMap<QByteArray, DChannel *> c_channels;

public slots:
    void statusUpdate(QByteArray statusPacket);
    void setEvaluationPacket(QByteArray evaluationPacket);

    bool save(QString fileName);
    bool load(QString fileName);

signals:
    void error(QString description);
    void channelsChanged();

protected:
    void deleteChannels();
    QDataStream *c_dataStream = nullptr;

    // real time status packet
    QByteArray c_statusPacket = nullptr;
    quint32 c_statusPacketTimeStamp = 0;

    // packets for evaluation
    QByteArray c_evaluationPacket = nullptr;
    quint32 c_evaluationPacketTimeStamp = 0;

    quint32 timeStamp(QByteArray packet);
    QString c_error;

    QString c_filename;
    bool c_changed = false;
};

extern DChannelList *Channels;
}

#endif // DCHANNELLIST_H
