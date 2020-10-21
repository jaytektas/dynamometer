#include "channellist.h"
#include "filemagic.h"

#include <QFile>

using namespace  Dynamometer;

namespace Dynamometer
{
DChannelList::DChannelList(QObject *parent) : QObject (parent)
{
    factoryChannels();
}

DChannelList::~DChannelList()
{
    deleteAllChannels();
}

void DChannelList::statusUpdate(QByteArray statusPacket)
{
    c_statusPacket = statusPacket;
    if (!statusPacket.isNull())
        c_statusPacketTimeStamp = timeStamp(statusPacket);
    else
        c_statusPacketTimeStamp = 0;
}

void DChannelList::setEvaluationPacket(QByteArray evaluationPacket)
{
    c_evaluationPacket = evaluationPacket;
    if (!evaluationPacket.isNull())
        c_evaluationPacketTimeStamp = timeStamp(evaluationPacket);
    else
        c_evaluationPacketTimeStamp = 0;
}

quint32 DChannelList::timeStamp(QByteArray packet)
{
    return static_cast<uint32_t>(static_cast<uint8_t>(packet[8]) << 24 |
                                    static_cast<uint8_t>(packet[7]) << 16 |
                                        static_cast<uint8_t>(packet[6]) << 8 |
                                            static_cast<uint8_t>(packet[5]));
}

DChannel *DChannelList::addChannel(QByteArray name, DChannel::TYPE type, QByteArray expression, DChannel::DATA_TYPE dataType, quint16 offset, bool quiet)
{
    DChannel *channel;

    // does channel exist?
    if (c_channels.contains(name))
        channel = c_channels.value(name);
    else
    {
        channel = new DChannel(this);
        c_channels.insert(name, channel);
    }

    channel->setName(name);
    channel->setType(type);
    channel->setExpression(expression);
    channel->setDataType(dataType);
    channel->setOffset(offset);
    if (!quiet)
    {
        c_changed = true;
        emit channelsChanged();
    }
    return channel;
}

DChannel *DChannelList::addChannel(QByteArray name, qreal value, bool quiet)
{
    DChannel *channel = addChannel(name, DChannel::TYPE::CONSTANT, "", DChannel::DATA_TYPE::NaN, 0, quiet);
    channel->setValue(value);
    return channel;
}

DChannel *DChannelList::addChannel(DChannel *channel, bool quiet)
{
    channel->setParent(this);

    if (c_channels.contains(channel->getName()))
        c_channels.remove(channel->getName());

    c_channels.insert(channel->getName(), channel);
    if (!quiet)
    {
        emit channelsChanged();
        c_changed = true;
    }
    return channel;
}

DChannel *DChannelList::getChannel(QByteArray name)
{
    return c_channels.value(name);
}

DChannel *DChannelList::removeChannel(QByteArray name, bool quiet)
{
    DChannel *channel = nullptr;

    if (c_channels.contains(name))
    {
        channel = c_channels.value(name);
        c_channels.remove(name);
        if (!quiet)
        {
            c_changed = true;
            emit channelsChanged();
        }
    }

    return channel;
}

bool DChannelList::deleteChannel(QByteArray name, bool quiet)
{
    if (c_channels.contains(name))
    {
        DChannel *channel = c_channels.value(name);
        c_channels.remove(name);
        delete channel;
        if (!quiet)
        {
            c_changed = true;
            emit channelsChanged();
        }
        return true;
    }

    return false;
}

bool DChannelList::load(QString fileName)
{
    if (fileName.isEmpty())
    {
        setError("no file name");
        return false;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QDataStream in(&file);

    quint32 magic;
    in >> magic;

    if (magic != MAGIC::CHANNEL)
    {
        setError("invalid file format");
        file.close();
        return false;
    }

    quint32 version;
    in >> version;

    if (version != MAGIC::VERSION)
    {
        setError("wrong version");
        file.close();
        return false;
    }

    in.setVersion(QDataStream::Qt_5_12);

    deleteAllChannels();

    int channelCount;
    in >> channelCount;

    for (int i = 0; i < channelCount; i++)
    {
        DChannel *newChannel = new DChannel(this);
        in >> *newChannel;
        addChannel(newChannel, true);
    }

    emit channelsChanged();
    c_changed = false;
    c_filename = fileName;
    return true;
}

bool DChannelList::save(QString fileName)
{
    if (fileName.isEmpty())
    {
        setError("no file name");
        return false;
    }

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << static_cast<quint32>(MAGIC::CHANNEL);    // magic number
    out << static_cast<quint32>(MAGIC::VERSION);           // version

    out.setVersion(QDataStream::Qt_5_12);

    QMap<QByteArray, DChannel *>::iterator channel;

    out << c_channels.size();

    for (channel = c_channels.begin(); channel != c_channels.end(); channel++)
            out << *(*channel);

    file.close();
    c_changed = false;
    return true;
}

void DChannelList::deleteAllChannels()
{
    // delete any existing channels
    QMap<QByteArray, DChannel *>::iterator channel;

    for (channel = c_channels.begin(); channel != c_channels.end();)
    {
        DChannel *d = (*channel);
        channel = c_channels.erase(channel);
        delete d;
    }
}

// resets to default factory state
void DChannelList::factoryChannels()
{
    DChannel *channel;
    // add the factory channels back
    channel = addChannel("TIME", DChannel::TYPE::STATUS, nullptr,  DChannel::DATA_TYPE::UINT32, 5, true);
    channel->setMinimum(0);
    channel->setMaximum(0xffffffff);

    channel = addChannel("WST", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::INT32, 9, true);
    channel->setMinimum(-40);
    channel->setMaximum(60);
    channel->setUnits("°C");

    addChannel("WSP", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::INT32, 13, true);
    addChannel("WSH", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::INT32, 17, true);

    addChannel("H1INTERVAL", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT32, 21, true);
    addChannel("H1LOAD", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::INT32, 25, true);

    channel = addChannel("AN1", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 69, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN2", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 71, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN3", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 73, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN4", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 75, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN5", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 77, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN6", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 79, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN7", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 81, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN8", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 83, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN9", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 85, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN10", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 87, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN11", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 89, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    channel = addChannel("AN12", DChannel::TYPE::STATUS, nullptr, DChannel::DATA_TYPE::UINT16, 91, true);
    channel->setMinimum(0);
    channel->setMaximum(4095);

    addChannel("RPM1", DChannel::TYPE::APPLICATION, "60*10500000/(H1TEETH*H1INTERVAL)", DChannel::DATA_TYPE::NaN, 0, true);
    addChannel("H1TEETH", 2, true);

    emit channelsChanged();
}

}
