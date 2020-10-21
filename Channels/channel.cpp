#include "channel.h"
#include "../Expressions/parser.h"

namespace Dynamometer
{
DChannel::DChannel(QObject *parent) : QObject (parent)
{
}

void DChannel::setValue(qreal value)
{
        c_value = value;
}

qreal DChannel::getValue(bool evaluation)
{
//    DChannelList *channelList = dynamic_cast<DChannelList*>(parent());

    if (c_type == CONSTANT) return c_value;

    if (!evaluation && c_lastTimeStamp == Channels->getStatusPacketTimeStamp()) return c_value;

    if (c_type == STATUS)
    {
        QByteArray packet;

        if (!evaluation) packet = Channels->getStatusPacket();
        else packet = Channels->getEvaluationPacket();

        if (packet.isNull()) return 0;

        switch(c_dataType)
        {
            case NaN:
            break;

            case INT32:
                {
                    qint32 vv;
                    vv = static_cast<qint32>(static_cast<uint8_t>(packet[c_offset + 3]) << 24 |
                                static_cast<uint8_t>(packet[c_offset + 2]) << 16 |
                                static_cast<uint8_t>(packet[c_offset + 1]) << 8 |
                                static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;

            case UINT32:
                {
                    quint32 vv;
                    vv = static_cast<quint32>(static_cast<uint8_t>(packet[c_offset + 3]) << 24 |
                                static_cast<uint8_t>(packet[c_offset + 2]) << 16 |
                                static_cast<uint8_t>(packet[c_offset + 1]) << 8 |
                                static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;

            case INT16:
                {
                    qint16 vv;
                    vv = static_cast<qint16>(static_cast<uint8_t>(packet[c_offset + 1]) << 8 |
                                static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;

            case UINT16:
                {
                    quint16 vv;
                    vv = static_cast<quint16>(static_cast<uint8_t>(packet[c_offset + 1]) << 8 |
                                static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;

            case INT8:
                {
                    qint8 vv;
                    vv = static_cast<qint8>(static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;

            case UINT8:
                {
                    quint8 vv;
                    vv = static_cast<quint8>(static_cast<uint8_t>(packet[c_offset]));
                    c_value = vv;
                }
                break;
        }
    }

   if (!c_expression.isEmpty())
    {
       // *non destructive* remove ourself from the equation so to speak
       Channels->removeChannel(c_name, true);

       // status value?
       if (c_type == TYPE::STATUS) Channels->addChannel("X", c_value, true);

       // parse us
       Parser np;
       c_value = np.parse(c_expression, evaluation);

       if (c_type == TYPE::STATUS) Channels->deleteChannel("X", true);

       Channels->addChannel(this, true); // insert us and our maybe new value
   }

   if (!evaluation) c_lastTimeStamp = Channels->getStatusPacketTimeStamp();

   return c_value;
}


QDataStream& operator<< (QDataStream& out, const DChannel& channel)
{
    out << channel.c_name
        << (qint8)channel.c_type
        << channel.c_expression
        << (qint8)channel.c_dataType
        << channel.c_offset
        << channel.c_minimum
        << channel.c_maximum
        // hints
        << channel.c_lowerCriticalStart
        << channel.c_lowerCriticalEnd
        << channel.c_lowerWarningStart
        << channel.c_lowerWarningEnd
        << channel.c_validStart
        << channel.c_validEnd
        << channel.c_upperWarningStart
        << channel.c_upperWarningStart
        << channel.c_upperCriticalStart
        << channel.c_upperCriticalEnd
        << channel.c_majorTicks
        << channel.c_minorTicks
        << channel.c_labelFormat
        << channel.c_autoScaleAxis;

    if (channel.c_type == DChannel::TYPE::CONSTANT)
        out << channel.c_value;

    return out;
}

QDataStream& operator>> (QDataStream& in, DChannel& channel)
{
    in >> channel.c_name
        >> (qint8&)channel.c_type
        >> channel.c_expression
        >> (qint8&)channel.c_dataType
        >> channel.c_offset

        // hints
        >> channel.c_minimum
        >> channel.c_maximum
        >> channel.c_lowerCriticalStart
        >> channel.c_lowerCriticalEnd
        >> channel.c_lowerWarningStart
        >> channel.c_lowerWarningEnd
        >> channel.c_validStart
        >> channel.c_validEnd
        >> channel.c_upperWarningStart
        >> channel.c_upperWarningStart
        >> channel.c_upperCriticalStart
        >> channel.c_upperCriticalEnd
        >> channel.c_majorTicks
        >> channel.c_minorTicks
        >> channel.c_labelFormat
        >> channel.c_autoScaleAxis;

    if (channel.c_type == DChannel::TYPE::CONSTANT)
        in >> channel.c_value;

    return in;
}
}

