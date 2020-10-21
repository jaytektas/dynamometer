#include "configuration.h"
#include "ui_configuration.h"

#include "filemagic.h"

#include <QFileDialog>
#include <QDataStream>
#include <QFile>
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDebug>

namespace Dynamometer
{
DConfiguration::DConfiguration(QWidget *parent) : QDialog(parent), ui(new Ui::DConfiguration)
{
    ui->setupUi(this);
    QSettings s;
    s.beginGroup("configuration");
    QString cfg = s.value("filename").toString();
    s.endGroup();

    if (!cfg.isEmpty() && !load(cfg))
    {
        QMessageBox::warning(nullptr, "Configuration", QString("Unable to open configuration %1 %2").arg(cfg, getError()));
        cfg = "";
    }

    if (cfg.isEmpty())
    {
        QMessageBox::information(nullptr, "Configuration", "No preset configuration file was found. Please choose an existing or new file");

        QDir d;
        QFileDialog fd;
        QString path = QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)[0];
        d.mkpath(path);

        fd.setWindowTitle("configuration");
        fd.setFileMode(QFileDialog::FileMode::AnyFile);
        fd.setAcceptMode(QFileDialog::AcceptMode::AcceptSave);
        fd.setOption(QFileDialog::DontConfirmOverwrite);
        fd.setDirectory(path);

        if(fd.exec())
        {
            QStringList filenames = fd.selectedFiles();
            if (filenames.count() > 0)
            {
                QString fn = filenames.value(0);
                if (d.exists(fn))
                {
                    if (!load(fn))
                    {
                        QMessageBox::warning(nullptr, "Configuration", "Unable to open configuration : " + getError());
                    }
                }
                else
                {
                    if (!save(fn))
                    {
                        QMessageBox::warning(nullptr, "Configuration", "There was an error trying to save configuration : " + getError());
                    }
                }

                s.beginGroup("configuration");
                s.setValue("filename", fn);
                s.endGroup();
            }
        }
    }
}

DConfiguration::~DConfiguration()
{
    delete ui;
}

void DConfiguration::showEvent(QShowEvent *event)
{
    ui->workspaceLineEdit->setText(c_workspacePath);
    ui->channelsLineEdit->setText(c_channelFilename);
    QSettings s;
    s.beginGroup("configuration");
    ui->configurationLineEdit->setText(s.value("filename").toString());
    s.endGroup();
    QDialog::showEvent(event);
}

void DConfiguration::on_workspacePushButton_clicked()
{
    QFileDialog fd(this);
    fd.setFileMode(QFileDialog::FileMode::DirectoryOnly);
    fd.setDirectory(c_workspacePath);
    if (fd.exec()) ui->workspaceLineEdit->setText(fd.selectedFiles()[0]);
}

void DConfiguration::setChannelFilename(QString channelFilename)
{
    if (channelFilename != c_channelFilename)
    {
        c_channelFilename = channelFilename;
        c_changed = true;
    }
}

void DConfiguration::setWorkSpacePath(QString workspacePath)
{
    if (workspacePath != c_workspacePath)
    {
        c_workspacePath = workspacePath;
        c_changed = true;
    }
}

void DConfiguration::on_buttonBox_accepted()
{
    // copy from controls
    setWorkSpacePath(ui->workspaceLineEdit->text());
    setChannelFilename(ui->channelsLineEdit->text());
    if (c_changed) emit configurationChanged();
}

bool DConfiguration::load(QString fileName)
{
    if (fileName.isEmpty())
    {
        setError("no file name");
        return false;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        c_error = "unable to open file : " + file.errorString();
        return false;
    }

    QDataStream in(&file);

    quint32 magic;
    in >> magic;

    if (magic != MAGIC::CONFIGURATION )
    {
        c_error = "invalid file bad magic number";
        file.close();
        return false;
    }

    quint32 version;
    in >> version;

    if (version != MAGIC::VERSION)
    {
        c_error = "file is wrong version";
        file.close();
        return false;
    }

    in.setVersion(QDataStream::Qt_5_12);

    in >> *this;
    file.close();
    c_filename = fileName;
    c_changed = false;
    return true;
}

bool DConfiguration::save(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        c_error = "unable to open file for writing";
        return false;
    }

    QDataStream out(&file);

    out << static_cast<quint32>(MAGIC::CONFIGURATION);          // magic number
    out << static_cast<quint32>(MAGIC::VERSION);        // version

    out.setVersion(QDataStream::Qt_5_12);

    out << *this;
    file.close();
    c_changed = false;
    return true;
}

QDataStream& operator<< (QDataStream& out, const DConfiguration& configuration)
{
    out << configuration.c_workspacePath
        << configuration.c_channelFilename;

    return out;
}

QDataStream& operator>> (QDataStream& in, DConfiguration& configuration)
{
    in >> configuration.c_workspacePath
       >> configuration.c_channelFilename;

    return in;
}

void DConfiguration::on_channelsPushButton_clicked()
{
    QStringList fn = fileDialog(ui->channelsLineEdit->text(), QFileDialog::ExistingFile, QFileDialog::AcceptOpen);
    if (fn.count()) ui->channelsLineEdit->setText(fn.value(0));
}

void Dynamometer::DConfiguration::on_configurationPushButton_clicked()
{
}

QStringList DConfiguration::fileDialog(QString filename, QFileDialog::FileMode fileMode, QFileDialog::AcceptMode acceptMode)
{
    QFileDialog fd;
    fd.setWindowTitle("Open file");
    fd.setFileMode(fileMode);
    fd.setAcceptMode(acceptMode);
    if (!filename.isEmpty())
        fd.setDirectory(filename);
    else
        fd.setDirectory(QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)[0]);

    if (fd.exec())
        return fd.selectedFiles();

    return QStringList();
}

}
