#ifndef HISTOGRAMCONFIG_H
#define HISTOGRAMCONFIG_H

#include "histogramwidget.h"

#include <QDialog>

namespace Ui {
class DHistogramConfig;
}

using namespace std;
using namespace QtCharts;

namespace Dynamometer
{
class DHistogramConfig : public QDialog
{
    Q_OBJECT

public:
    explicit DHistogramConfig(DHistogramWidget *parent);
    ~DHistogramConfig();

private:
    Ui::DHistogramConfig *ui;
    DHistogramWidget *h_display = nullptr;

protected slots:
    void channelAdded(QByteArray channelName);
    void channelRemoved(QByteArray channelName);
    void currentChannelChanged(QString currentChannelName);
    void lineEdit(const QString& edit);
    void checkBox();
    void colorButton();
    void fontButton();

private slots:
    void on_autoScale_stateChanged(int arg1);
    void on_title_textEdited(const QString &arg1);
    void on_majorTicks_textEdited(const QString &arg1);
    void on_minorTicks_textEdited(const QString &arg1);
    void on_alignment_currentIndexChanged(const QString &arg1);
    void on_visible_stateChanged(int arg1);
    void on_minimum_textEdited(const QString &arg1);
    void on_maximum_textEdited(const QString &arg1);
    void on_seriesColor_clicked();
    void on_buttonBox_accepted();

    void on_verticalAxis_currentIndexChanged(const QString &arg1);

    void on_majorGridLineColor_clicked();

    void on_minorGridLineColor_clicked();

    void on_labelColor_clicked();

    void on_labelFormat_textEdited(const QString &arg1);

    void on_horizontalAxis_currentIndexChanged(const QString &arg1);

    void on_deleteVerticalAxis_clicked();

protected:
    DHistogramWidget *h_parent = nullptr;
};
}

#endif // HISTOGRAMCONFIG_H
