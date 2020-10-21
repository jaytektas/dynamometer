#ifndef WIDGETCONFIG_H
#define WIDGETCONFIG_H

#include "gauge.h"

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class DWidgetConfig;
}

namespace Dynamometer
{
class DWidgetConfig : public QDialog
{
    Q_OBJECT

public:
    explicit DWidgetConfig(QWidget *parent, QWidget *display);
    ~DWidgetConfig();

private slots:
    void lineEdit(const QString& edit);
    void checkBox();
    void colorButton();
    void fontButton();

    void on_buttonBox_accepted();

private:
    Ui::DWidgetConfig *ui;
    QWidget *g_display = nullptr;
};
}

#endif // WIDGETCONFIG_H
