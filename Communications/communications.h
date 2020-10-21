#ifndef DCOMMUNICATIONS_H
#define DCOMMUNICATIONS_H

#include <QSerialPort>

using namespace std;

namespace Dynamometer
{
#define PACKET_HEADER		5							// 01 01 CM SZ SZ
#define PACKET_CRC			4							// CR CR CR CR
#define PACKET_PAYLOAD		1024						// D0...Dx
#define MAX_PACKET_SIZE		(PACKET_HEADER+PACKET_PAYLOAD+PACKET_CRC)

#define PACKET_COMMAND		3
#define PACKET_SIZE			5

class DCommunications : public QObject
{
    Q_OBJECT
    typedef enum SerialState
    {
        START,
        HEADER,
        PACKET,
        CRC
    } SerialState_t;

    typedef enum PacketFlags{
        OK,
        REALTIME_DATA,
        PAGE_DATA,
        CONFIG_ERROR,
        BURN_OK,
        PAGE10_OK,
        CAN_DATA,
        UNDER_RUN = 0x80,
        OVER_RUN,
        CRC_ERROR,
        UNKNOWN_COMMAND,
        OUT_OF_RANGE,
        BUSY,
        FLASH_LOCKED,
        SEQUENCE_FAILURE_1,
        SEQUENCE_FAILURE_2,
        CAN_QUEUE_FULL,
        CAN_TIMEOUT,
        CAN_FAILURE,
        PARITY_ERROR,
        FRAMING_ERROR,
        SERIAL_NOISE,
        TXMODE_RANGE,
        UNKNOWN
    } PacketFlags_t;


public:
    DCommunications(QObject *parent = nullptr);
    ~DCommunications();

    // properties
    QString getPortName() const { return c_portName; }
    void setPortName(QString portName) { c_portName = portName; }

    QSerialPort::BaudRate getBaudRate() const { return c_baudRate; }
    void setBaud(QSerialPort::BaudRate baudRate) { c_baudRate = baudRate; }

    QSerialPort::DataBits getDataBits() const { return c_dataBits; }
    void setDataBits(QSerialPort::DataBits dataBits) { c_dataBits = dataBits; }

    QSerialPort::Parity getParity() const { return c_parity; }
    void setParity(QSerialPort::Parity parity) { c_parity = parity; }

    QSerialPort::StopBits getStopBits() const { return c_stopBits; }
    void setStopBits(QSerialPort::StopBits stopBits) { c_stopBits = stopBits; }

    QSerialPort::FlowControl getFlowControl() const { return c_flowControl; }
    void setFlowControl(QSerialPort::FlowControl flowControl) { c_flowControl = flowControl;}

    int getTimeout() const { return c_timeout; }
    void setTimeout(int timeout) { c_timeout = timeout; }

    bool isConnected() const { return c_connected; }

signals:
    void connected(bool connected);

public slots:
    bool openSerial();
    void closeSerial();
    QByteArray transmit(char command, QByteArray transmit);

private:
    QByteArray receiveEnvelope(QSerialPort* sp);
    QByteArray envelopePacket(char command, QByteArray packet);
    QByteArray crc32(QByteArray data, int len);

    int c_timeout = 500;
    bool c_connected = false;

    QSerialPort *c_serialPort = nullptr;

    QString c_portName = "";
    QSerialPort::BaudRate c_baudRate = QSerialPort::Baud115200;
    QSerialPort::DataBits c_dataBits = QSerialPort::DataBits::Data8;
    QSerialPort::Parity c_parity = QSerialPort::Parity::NoParity;
    QSerialPort::StopBits c_stopBits = QSerialPort::StopBits::OneStop;
    QSerialPort::FlowControl c_flowControl = QSerialPort::FlowControl::NoFlowControl;

    QByteArray c_packet = "";
    QByteArray c_transmit = "";
    char c_command = '\0';

    // raw data logging to file
    QString c_dataLogFileName = "";
    bool c_dataLogEnable = false;

};

extern DCommunications *Comms;
}

#endif // DCOMMUNICATIONS_H
