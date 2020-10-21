#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include <QList>
#include <qdebug.h>
#include <qsettings.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qradiobutton.h>
#include <communications.h>
#include <qserialport.h>

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
QList<QSerialPortInfo> ports;
QSerialPortInfo port;
QSettings settings;

    ui->setupUi(this);

    settings.beginGroup("Connection");

    ui->comboBaudRate->addItem("1200");
    ui->comboBaudRate->addItem("2400");
    ui->comboBaudRate->addItem("4800");
    ui->comboBaudRate->addItem("9600");
    ui->comboBaudRate->addItem("19200");
    ui->comboBaudRate->addItem("38400");
    ui->comboBaudRate->addItem("57600");
    ui->comboBaudRate->addItem("115200");
    ui->comboBaudRate->addItem("Custom");
    ui->comboBaudRate->setCurrentIndex(settings.value("BaudRate", 7).toInt());

    ui->comboDataBits->addItem("5");
    ui->comboDataBits->addItem("6");
    ui->comboDataBits->addItem("7");
    ui->comboDataBits->addItem("8");
    ui->comboDataBits->setCurrentIndex(settings.value("DataBits", 3).toInt());

    ui->comboParity->addItem("None");
    ui->comboParity->addItem("Odd");
    ui->comboParity->addItem("Even");
    ui->comboParity->addItem("Mark");
    ui->comboParity->addItem("Space");
    ui->comboParity->setCurrentIndex(settings.value("Parity", 0).toInt());

    ui->comboStopBits->addItem("1", QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->comboStopBits->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->comboStopBits->addItem("2", QSerialPort::TwoStop);
    ui->comboStopBits->setCurrentIndex(settings.value("StopBits", 0).toInt());

    ui->comboFlowControl->addItem("None");
    ui->comboFlowControl->addItem("Hardware (RTS/CTS)");
    ui->comboFlowControl->addItem("Software (XON/XOFF)");
    ui->comboFlowControl->setCurrentIndex(settings.value("FlowControl", 0).toInt());

    ui->comboPortName->addItem("");
    ports = QSerialPortInfo::availablePorts();
    foreach (port, ports) {
        ui->comboPortName->addItem(port.portName(), port.portName());
        if (port.portName() == settings.value("PortName"))
            ui->comboPortName->setCurrentIndex(ui->comboPortName->count()-1);
    }
    settings.endGroup();
    loadState(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_buttonBox_accepted()
{
QSettings settings;

    settings.beginGroup("Connection");
    settings.setValue("PortName", ui->comboPortName->currentText());
    settings.setValue("BaudRate", ui->comboBaudRate->currentIndex());
    settings.setValue("DataBits", ui->comboDataBits->currentIndex());
    settings.setValue("Parity", ui->comboParity->currentIndex());
    settings.setValue("StopBits", ui->comboStopBits->currentIndex());
    settings.setValue("FlowControl", ui->comboFlowControl->currentIndex());
    settings.endGroup();
    saveState(this);
}

void ConnectionDialog::loadState(QWidget* window)
{
    QSettings settings;

    settings.beginGroup(window->objectName());
    QVariant value = settings.value("pos");
    if (!value.isNull())
    {
        window->move(settings.value("pos").toPoint());
        window->resize(settings.value("size").toSize());
//        loadSettingsTraverse(settings, window);
    }
    settings.endGroup();
}

void ConnectionDialog::saveState(QWidget* window)
{
    QSettings settings;

    settings.beginGroup(window->objectName());
    settings.setValue("pos", window->pos());
    settings.setValue("size", window->size());
//    saveSettingsTraverse(settings, window);
    settings.endGroup();
}

void ConnectionDialog::loadSettingsTraverse(QSettings &settings, QObject *currentObject)
{
    QCheckBox* checkbox = dynamic_cast<QCheckBox*>(currentObject);
    if (checkbox != nullptr)
    {
        checkbox->setChecked(settings.value(checkbox->objectName()).toBool());
    }

    QComboBox* combobox = dynamic_cast<QComboBox*>(currentObject);
    if (combobox != nullptr)
    {
        combobox->setCurrentIndex(settings.value(combobox->objectName()).toInt());
    }

    QRadioButton* radiobutton = dynamic_cast<QRadioButton*>(currentObject);
    if (radiobutton != nullptr)
    {
        radiobutton->setChecked(settings.value(radiobutton->objectName()).toBool());
    }

    foreach(QObject* child, currentObject->children())
    {
        loadSettingsTraverse(settings, child);
    }
}

void ConnectionDialog::saveSettingsTraverse(QSettings &settings, QObject *currentObject)
{
    QCheckBox* checkbox = dynamic_cast<QCheckBox*>(currentObject);
    if (checkbox != nullptr)
    {
        settings.setValue(checkbox->objectName(), checkbox->isChecked());
    }

    QComboBox* combobox = dynamic_cast<QComboBox*>(currentObject);
    if (combobox != nullptr)
    {
        settings.setValue(combobox->objectName(), combobox->currentIndex());
    }

    QRadioButton* radiobutton = dynamic_cast<QRadioButton*>(currentObject);
    if (radiobutton != nullptr)
    {
        settings.setValue(radiobutton->objectName(), radiobutton->isChecked());
    }

    foreach(QObject* child, currentObject->children())
    {
        saveSettingsTraverse(settings, child);
    }
}

void ConnectionDialog::closeEvent(QCloseEvent *event)
{
    saveState(this);
    QDialog::closeEvent(event);
}

void ConnectionDialog::on_buttonBox_rejected()
{
    saveState(this);
}
