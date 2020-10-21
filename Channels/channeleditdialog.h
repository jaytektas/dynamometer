#ifndef CHANNELEDITDIALOG_H
#define CHANNELEDITDIALOG_H

#include "channel.h"

#include <QDialog>

namespace Ui {
class DChannelEditDialog;
}

using namespace std;

namespace Dynamometer
{
class DChannelEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DChannelEditDialog(QWidget *parent = nullptr);
    ~DChannelEditDialog();

    bool setChannelName(QByteArray channelName);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DChannelEditDialog *ui;
};
}

#endif // CHANNELEDITDIALOG_H
