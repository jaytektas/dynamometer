#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include "run.h"

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

using namespace QtCharts;
using namespace std;

namespace Ui {
class DChartWidget;
}

namespace Dynamometer
{
class DChartWidget : public QChartView
{
    Q_OBJECT

protected:

    typedef struct
    {
        qreal min;
        qreal max;
        QLineSeries *runSeries;
    } DChannelRunData;

    typedef struct
    {
        QByteArray channelName;
        QValueAxis *axis = nullptr;
        QMap<QDateTime, DChannelRunData *> channelRunData;
    } DChannelData;


public:
    explicit DChartWidget(QWidget *parent = nullptr);
    ~DChartWidget() override;

    QMap<QByteArray, DChannelData *> c_ySeries;

    QByteArray c_xAxisChannelName = "TIME";
    QValueAxis *c_xAxis = nullptr;

public slots:
    void selectedRunsChanged();
    void changeBase();

protected slots:
    void customContextMenuRequested(const QPoint &);
    void resetChartView();
    void print();

private:
    Ui::DChartWidget *ui;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override { event->acceptProposedAction(); }
    void dragLeaveEvent(QDragLeaveEvent *event) override { event->ignore(); }
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void setCursorShape(const QPoint &e_pos);

    //    void mousePressEvent(QMouseEvent *event) override;
    QLineSeries *lineSeries(DRun *run, QByteArray xChannel, QByteArray yChannel);
    void deleteSeries();

    DChartWidget::DChannelData *constructChannel(QByteArray channelName);
    void hovered(QPointF, bool state);
    void autoScaleChannel(QByteArray channelName);

    QPoint c_position;
};
}

#endif // CHARTWIDGET_H
