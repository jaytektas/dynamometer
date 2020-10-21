#include "channeleditdialog.h"
#include "ui_channeleditdialog.h"

#include "channellist.h"

namespace Dynamometer
{
DChannelEditDialog::DChannelEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DChannelEditDialog)
{
    ui->setupUi(this);
    setWindowTitle("Channel Editor");
}

DChannelEditDialog::~DChannelEditDialog()
{
    delete ui;
}

bool DChannelEditDialog::setChannelName(QByteArray channelName)
{
    DChannel *channel = Channels->getChannel(channelName);
    if (!channel) return false;

    ui->name->setText(channel->getName());
    ui->type->setCurrentIndex(channel->getType());
    ui->expression->setText(channel->getExpression());
    ui->dataType->setCurrentIndex(channel->getDataType());
    ui->offset->setText(QString::number(channel->getOffset()));
    ui->minimum->setText(QString::number(channel->getMinimum()));
    ui->maximum->setText(QString::number(channel->getMaximum()));
    ui->lowerCriticalStart->setText(QString::number(channel->getLowerCriticalStart()));
    ui->lowerCriticalEnd->setText(QString::number(channel->getLowerCriticalEnd()));
    ui->lowerWarningStart->setText(QString::number(channel->getLowerWarningStart()));
    ui->lowerWarningEnd->setText(QString::number(channel->getLowerWarningEnd()));
    ui->validStart->setText(QString::number(channel->getValidStart()));
    ui->validEnd->setText(QString::number(channel->getValidEnd()));
    ui->upperWarningStart->setText(QString::number(channel->getUpperWarningStart()));
    ui->upperWarningEnd->setText(QString::number(channel->getUpperWarningEnd()));
    ui->upperCriticalStart->setText(QString::number(channel->getUpperCriticalStart()));
    ui->upperCriticalEnd->setText(QString::number(channel->getUpperCriticalEnd()));
    ui->digits->setText(QString::number(channel->getDigits()));
    ui->units->setText(channel->getUnits());
    ui->filler->setText(QString(channel->getFiller()));
    ui->scale->setText(QString::number(channel->getScale()));
    ui->majorTicks->setText(QString::number(channel->getMajorTicks()));
    ui->minorTicks->setText(QString::number(channel->getMinorTicks()));
    ui->labelFormat->setText(channel->getLabelFormat());
    ui->autoScaleAxis->setCheckState(channel->getAutoScaleAxis() ? Qt::Checked : Qt::Unchecked);

    if (channel->getType() == DChannel::TYPE::CONSTANT)
        ui->value->setText(QString::number(channel->getValue()));

    return true;
}


void Dynamometer::DChannelEditDialog::on_buttonBox_accepted()
{
    DChannel *channel = new DChannel();

    channel->setName(ui->name->text().toUtf8().data());
    channel->setType(static_cast<DChannel::TYPE>(ui->type->currentIndex()));
    channel->setExpression(ui->expression->text().toUtf8().data());
    channel->setDataType(static_cast<DChannel::DATA_TYPE>(ui->dataType->currentIndex()));
    channel->setOffset(static_cast<quint16>(ui->offset->text().toUInt()));
    channel->setMinimum(ui->minimum->text().toDouble());
    channel->setMaximum(ui->maximum->text().toDouble());
    channel->setLowerCriticalStart(ui->lowerCriticalStart->text().toDouble());
    channel->setLowerCriticalEnd(ui->lowerCriticalEnd->text().toDouble());
    channel->setLowerWarningStart(ui->lowerWarningStart->text().toDouble());
    channel->setLowerWarningEnd(ui->lowerWarningEnd->text().toDouble());
    channel->setValidStart(ui->validStart->text().toDouble());
    channel->setValidEnd(ui->validEnd->text().toDouble());
    channel->setUpperWarningStart(ui->upperWarningStart->text().toDouble());
    channel->setUpperWarningEnd(ui->upperWarningEnd->text().toDouble());
    channel->setUpperCriticalStart(ui->upperCriticalStart->text().toDouble());
    channel->setUpperCriticalEnd(ui->upperCriticalEnd->text().toDouble());
    channel->setDigits(ui->digits->text().toInt());
    channel->setUnits(ui->units->text());
    channel->setFiller(ui->filler->text().toUtf8().data()[0]);
    channel->setScale(ui->scale->text().toDouble());
    channel->setMajorTicks(ui->majorTicks->text().toInt());
    channel->setMinorTicks(ui->minorTicks->text().toInt());
    channel->setLabelFormat(ui->labelFormat->text());
    channel->setAutoScaleAxis(ui->autoScaleAxis->checkState() == Qt::Checked ? true : false);

    if (channel->getType() == DChannel::TYPE::CONSTANT)
        channel->setValue(ui->value->text().toDouble());

    Channels->addChannel(channel, false);
}

}
