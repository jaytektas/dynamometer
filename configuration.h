#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class DConfiguration;
}

using namespace std;

namespace Dynamometer
{
class DConfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit DConfiguration(QWidget *parent = nullptr);
    ~DConfiguration() override;

    bool save(QString fileName);
    bool load(QString fileName);

    QString getWorkspacePath() const { return c_workspacePath; }
    void setWorkSpacePath(QString workspacePath);

    bool getChanged() const { return c_changed; }
    void setChanged(bool changed) { c_changed = changed; }

    QString getError() const { return c_error; }
    void setError(QString error) { c_error = error; }

    QString getChannelFilename() const { return c_channelFilename; }
    void setChannelFilename(QString channelFilename);

signals:
    void configurationChanged();

protected:
    QStringList fileDialog(QString filename, QFileDialog::FileMode fileMode, QFileDialog::AcceptMode acceptMode);

private slots:
    void on_workspacePushButton_clicked();

    void on_buttonBox_accepted();

    void on_channelsPushButton_clicked();

    void on_configurationPushButton_clicked();

private:
    void showEvent(QShowEvent *event) override;
    friend QDataStream& operator<< (QDataStream& out, const DConfiguration& configuration);
    friend QDataStream& operator>> (QDataStream& in, DConfiguration& configuration);

    Ui::DConfiguration *ui;

    QString c_filename;
    bool c_changed = false;

    QString c_workspacePath;
    QString c_channelFilename;
    QString c_error = "no error";

    int c_hub1teeth = 2;
    int c_hub2teeth = 2;
    int c_hub3teeth = 2;
    int c_hub4teeth = 2;
};

QDataStream& operator<< (QDataStream& out, const DConfiguration& configuration);
QDataStream& operator>> (QDataStream& in, DConfiguration& configuration);

extern DConfiguration *Configuration;
}

#endif // CONFIGURATION_H
