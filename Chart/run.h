#ifndef RUN_H
#define RUN_H

#include <QtCore>

using namespace std;


namespace Dynamometer
{


class DRun : public QObject
{
    Q_OBJECT
public:
    enum COLUMNS
    {
        DELETE,
        SELECT,
        DATETIME,
        NAME,
        COMMENT
    };

    DRun(QObject *parent = nullptr);
    explicit DRun(QDateTime dateTime, QString name, QString comment, QObject *parent = nullptr);

    void setName(QString name) { r_name = name; }
    QString getName() const { return r_name; }

    void setDateTime(QDateTime dateTime) { r_dateTime = dateTime; }
    QDateTime getDateTime() const { return r_dateTime; }

    void setComment(QString comment) { r_comment = comment; }
    QString getComment() const { return r_comment; }

    void setSelected(bool selected) { r_selected = selected; }
    bool getSelected() const { return r_selected; }

    bool load(QString filename);
    bool save(QString filename);

    QString getError() const { return r_error; }
    void setError(QString error) { r_error = error; }

    vector<QByteArray> r_statusPackets;

public slots:
    void addStatusPacket(QByteArray statusPacket);

private:
    friend QDataStream & operator<< (QDataStream & out, const DRun & run);
    friend QDataStream & operator>> (QDataStream & in, DRun & run);

    QString r_name;
    QDateTime r_dateTime;
    QString r_comment;
    bool r_selected = false;
    QString r_error;
    QString r_filename;
    bool r_changed = false;
};

extern QMap<QDateTime, DRun *> Runs;

QDataStream & operator<< (QDataStream & out, const DRun & run);
QDataStream & operator>> (QDataStream & in, DRun & run);

}

#endif // RUN_H
