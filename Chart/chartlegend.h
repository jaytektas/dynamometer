#ifndef CHARTLEGEND_H
#define CHARTLEGEND_H

#include "widgetcontainer.h"

#include <QChartView>

using namespace std;
using namespace QtCharts;

namespace Dynamometer
{
class DChartLegend : public DWidgetContainer
{
public:
    DChartLegend(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    QPixmap c_baseDrawing;

    int c_tWidth;
    int c_tHeight;
    int c_xTranslate;
    int c_yTranslate;
    qreal c_xscale;
    qreal c_yscale;
    bool c_lockAspect = false;

    bool c_drawBackgroundEnabled = true;
    QColor c_backGroundColor = QColor(123, 123, 123, 50);
    int c_backgroundCornerRadius = 0;

    QFont c_legendFont = QFont("ubuntu", 6);
    QColor c_legendColor = QColor(Qt::blue);
    int c_padding = 6;
};

}

#endif // CHARTLEGEND_H
