#ifndef DCHANNEL_H
#define DCHANNEL_H

#include <QObject>
#include <QTimer>
#include <QDataStream>

using namespace std;

namespace Dynamometer
{
class DChannelList;

class DChannel : public QObject
{
    Q_OBJECT

public:
    DChannel(QObject *parent = nullptr);

    typedef enum
    {
        STATUS,
        APPLICATION,
        CONSTANT,
        USER
    } TYPE;

    typedef enum
    {
        NaN,
        UINT8,
        INT8,
        UINT16,
        INT16,
        UINT32,
        INT32,
    } DATA_TYPE;

    void setName(QByteArray name) { c_name = name; }
    QByteArray getName() const { return c_name; }
    void setType(TYPE type) { c_type = type; }
    TYPE getType() const { return c_type; }
    void setExpression(QByteArray expression) { c_expression = expression; }
    QByteArray getExpression() const { return c_expression; }
    void setDataType(DATA_TYPE dataType) { c_dataType = dataType; }
    DATA_TYPE getDataType() const { return c_dataType; }
    void setOffset(quint16 offset) { c_offset = offset; }
    quint16 getOffset() const { return c_offset; }

    void setMinimum(qreal minimum) { c_minimum = minimum; }
    qreal getMinimum() const { return c_minimum; }
    void setMaximum(qreal maximum) { c_maximum = maximum; }
    qreal getMaximum() const { return c_maximum; }

    void setTimeStamp(quint32 timeStamp) { c_lastTimeStamp = timeStamp; }
    quint32 getTimeStamp() const { return c_lastTimeStamp; }

    qreal getValue(bool evaluation = false);

    // hints
    void setLowerCriticalStart(qreal lowerCriticalStart) { c_lowerCriticalStart = lowerCriticalStart; }
    qreal getLowerCriticalStart() const { return c_lowerCriticalStart; }
    void setLowerCriticalEnd(qreal lowerCriticalEnd) { c_lowerCriticalEnd = lowerCriticalEnd; }
    qreal getLowerCriticalEnd() const { return c_lowerCriticalEnd; }
    void setLowerWarningStart(qreal lowerWarningStart) { c_lowerWarningStart = lowerWarningStart; }
    qreal getLowerWarningStart() const { return c_lowerWarningStart; }
    void setLowerWarningEnd(qreal lowerWarningEnd) { c_lowerWarningEnd = lowerWarningEnd;}
    qreal getLowerWarningEnd() const { return c_lowerWarningEnd; }
    void setValidStart(qreal validStart) { c_validStart = validStart; }
    qreal getValidStart() const { return c_validStart; }
    void setValidEnd(qreal validEnd) { c_validEnd = validEnd; }
    qreal getValidEnd() const { return c_validEnd; }
    void setUpperWarningStart(qreal upperWarningStart) { c_upperWarningStart = upperWarningStart; }
    qreal getUpperWarningStart() const { return c_upperWarningStart; }
    void setUpperWarningEnd(qreal upperWarningEnd) { c_upperWarningEnd = upperWarningEnd; }
    qreal getUpperWarningEnd() const { return c_upperWarningEnd; }
    void setUpperCriticalStart(qreal upperCriticalStart) { c_upperCriticalStart = upperCriticalStart; }
    qreal getUpperCriticalStart() const { return c_upperCriticalStart; }
    void setUpperCriticalEnd(qreal upperCriticalEnd) { c_upperCriticalEnd = upperCriticalEnd; }
    qreal getUpperCriticalEnd() const { return c_upperCriticalEnd; }
    void setMajorTicks(int majorTicks) { c_majorTicks = majorTicks; }
    int getMajorTicks() const { return c_majorTicks; }
    void setMinorTicks(int minorTicks) { c_minorTicks = minorTicks; }
    int getMinorTicks() const { return c_minorTicks; }
    void setLabelFormat(QString labelFormat) { c_labelFormat = labelFormat; }
    QString getLabelFormat() const { return c_labelFormat; }
    void setAutoScaleAxis(bool autoScaleAxis) { c_autoScaleAxis = autoScaleAxis; }
    bool getAutoScaleAxis() const { return c_autoScaleAxis; }

    void setDigits(int digits) { c_digits = digits; }
    int getDigits() const { return c_digits; }
    void setFiller(char filler) { c_filler = filler; }
    char getFiller() const { return c_filler; }
    void setPrecision(int precision) { c_precision = precision; }
    int getPrecision() const { return c_precision; }
    void setUnits(QString units) { c_units = units; }
    QString getUnits() const { return c_units; }
    void setScale(qreal scale) { c_scale = scale; }
    qreal getScale() const { return c_scale; }

    void setDisabled(bool disabled) { c_disabled = disabled; }
    bool getDisabled() const { return c_disabled; }

public slots:
    void setValue(qreal value);

protected:
    friend QDataStream& operator<< (QDataStream& in, const DChannel& channel);
    friend QDataStream& operator>> (QDataStream& out, DChannel& channel);

    QByteArray c_name;
    TYPE c_type = USER;
    QByteArray c_expression;

    // status
    DATA_TYPE c_dataType = NaN;
    quint16 c_offset = 0;

    qreal c_value = 0;
    quint32 c_lastTimeStamp = 0;

    // hints
    qreal c_minimum = 0;
    qreal c_maximum = 10000;
    qreal c_lowerCriticalStart = 0;
    qreal c_lowerCriticalEnd = 0;
    qreal c_lowerWarningStart = 0;
    qreal c_lowerWarningEnd = 0;
    qreal c_validStart = 0;
    qreal c_validEnd = 0;
    qreal c_upperWarningStart = 0;
    qreal c_upperWarningEnd = 0;
    qreal c_upperCriticalStart = 0;
    qreal c_upperCriticalEnd = 0;
    int c_majorTicks = 11;
    int c_minorTicks = 4;
    QString c_labelFormat;
    bool c_autoScaleAxis = true;

    QString c_units;
    int c_digits = 0;
    char c_filler = '0';
    int c_precision = 0;
    qreal c_scale = 1;

    bool c_disabled = false;
};

QDataStream& operator<< (QDataStream& out, const DChannel& channel);
QDataStream& operator>> (QDataStream& in, DChannel& channel);
}

#endif // DCHANNEL_H
