#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <QFileDialog>
#include <QSettings>
#include <QDebug>

DConfigurationDialog::DConfigurationDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DConfigurationDialog)
{
    ui->setupUi(this);
}

DConfigurationDialog::~DConfigurationDialog()
{
    delete ui;
}

void DConfigurationDialog::on_workspacePushButton_clicked()
{
    QFileDialog fd(this);
    fd.setDirectory(ui->workspaceLineEdit->text());
    fd.setFileMode(QFileDialog::DirectoryOnly);
    if (fd.exec())
    {
        QStringList sl = fd.selectedFiles();
        if (sl.count() > 0)
            ui->workspaceLineEdit->setText(sl.value(0));
    }
}

void DConfigurationDialog::on_buttonBox_accepted()
{
    // save settings
    QSettings qs;
    qs.beginGroup("workspace");
    qs.setValue("workspace", ui->workspaceLineEdit->text());
    qs.endGroup();
}
