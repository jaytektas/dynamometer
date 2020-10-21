#ifndef SESSIONWIDGET_H
#define SESSIONWIDGET_H

#include "run.h"

#include <QWidget>
#include <QListWidgetItem>
#include <QChart>
#include <QLineSeries>

using namespace Dynamometer;
using namespace  QtCharts;
using namespace std;

namespace Ui {
class DChartViewWidget;
}

namespace Dynamometer
{
class DChartViewWidget : public QWidget
{
    Q_OBJECT

public:
    DChartViewWidget(QWidget *parent = nullptr);
    ~DChartViewWidget();

    void setDocked(bool docked) { s_docked = docked; }
    bool getDocked() const { return s_docked; }
    int getTabIndex() const { return s_tabIndex; }
    void setTabIndex(int tabIndex) { s_tabIndex = tabIndex; }

public slots:
    void selectedRunsChanged();

protected:
    Ui::DChartViewWidget *ui;

    bool s_docked = true;
    int s_tabIndex = 0;
    QLineSeries *lineSeries(DRun *run, QByteArray, QByteArray);
};

}
#endif // SESSIONWIDGET_H
