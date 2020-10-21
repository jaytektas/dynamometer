#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <qsettings.h>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    void closeEvent(QCloseEvent *event);
    void saveState(QWidget* window);
    void loadState(QWidget* window);
    void saveSettingsTraverse(QSettings& settings, QObject* currentObject);
    void loadSettingsTraverse(QSettings& settings, QObject* currentObject);
    Ui::ConnectionDialog *ui;
    int c_counter;
};

#endif // CONNECTIONDIALOG_H
