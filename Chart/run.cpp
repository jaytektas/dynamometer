#include "run.h"
#include "filemagic.h"

#include <QFile>

namespace Dynamometer
{

DRun::DRun(QObject *parent) : QObject(parent)
{

}

DRun::DRun(QDateTime dateTime, QString name, QString comment, QObject *parent) : QObject(parent)
{
    r_dateTime = dateTime;
    r_name = name;
    r_comment = comment;
}

void DRun::addStatusPacket(QByteArray statusPacket)
{
    if (statusPacket.isNull()) return;
    r_statusPackets.push_back(statusPacket);
}

bool DRun::load(QString fileName)
{
    if (fileName.isEmpty())
    {
        setError("no file name");
        return false;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        r_error = "unable to open file : " + file.errorString();
        return false;
    }

    QDataStream in(&file);

    quint32 magic;
    in >> magic;

    if (magic != MAGIC::RUN)
    {
        r_error = "invalid file bad magic number";
        file.close();
        return false;
    }

    quint32 version;
    in >> version;

    if (version != MAGIC::VERSION)
    {
        r_error = "file is wrong version";
        file.close();
        return false;
    }

    in.setVersion(QDataStream::Qt_5_12);

    in >> *this;
    file.close();
    r_filename = fileName;
    r_changed = false;
    return true;
}

bool DRun::save(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        r_error = "unable to open file for writing";
        return false;
    }

    QDataStream out(&file);

    out << static_cast<quint32>(MAGIC::RUN);          // magic number
    out << static_cast<quint32>(MAGIC::VERSION);        // version

    out.setVersion(QDataStream::Qt_5_12);

    out << *this;
    file.close();
    r_changed = false;
    return true;
}

QDataStream & operator<< (QDataStream & out, const DRun & run)
{
    out << run.r_name
        << run.r_dateTime
        << run.r_comment;

    // save the raw status packets
    out << static_cast<quint32>(run.r_statusPackets.size());

    vector<QByteArray>::const_iterator i;

    for (i = run.r_statusPackets.begin(); i != run.r_statusPackets.end(); i++)
        out << (*i);

    return out;
}

QDataStream & operator>> (QDataStream & in, DRun & run)
{
quint32 relTime = 0;
bool first = true;;

    run.r_statusPackets.clear();

    in >> run.r_name
        >> run.r_dateTime
        >> run.r_comment;

    quint32 i;
    in >> i;

    while(i--)
    {
        QByteArray statusPacket;
        quint32 newTime;

        in >> statusPacket;

        if (first)
        {
            relTime = static_cast<uint32_t>(static_cast<quint8>(statusPacket[8]) << 24 |
                                                      static_cast<quint8>(statusPacket[7]) << 16 |
                                                          static_cast<quint8>(statusPacket[6]) << 8 |
                                                              static_cast<quint8>(statusPacket[5]));
            first = false;
        }

        // change packet time
        newTime = static_cast<uint32_t>(static_cast<quint8>(statusPacket[8]) << 24 |
                                                  static_cast<quint8>(statusPacket[7]) << 16 |
                                                      static_cast<quint8>(statusPacket[6]) << 8 |
                                                          static_cast<quint8>(statusPacket[5]));
        newTime -= relTime;
        // reinsert time
        statusPacket[8] = static_cast<qint8>(newTime >> 24);
        statusPacket[7] = static_cast<qint8>(newTime >> 16);
        statusPacket[6] = static_cast<qint8>(newTime >> 8);
        statusPacket[5] = static_cast<qint8>(newTime);
        run.r_statusPackets.push_back(statusPacket);
    }

    return in;
}

}
