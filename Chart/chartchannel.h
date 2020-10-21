#ifndef CHARTCHANNEL_H
#define CHARTCHANNEL_H

#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

using namespace std;
using namespace QtCharts;

namespace Dynamometer
{
class DChartChannel
{
public:
    DChartChannel();
    DChartChannel(const DChartChannel &chartChannel);   // copy constructor

    void setChannelName(QByteArray channelName) { c_channelName = channelName; }
    QByteArray getChannelName() const { return c_channelName; }

    void setHistoricalMin(double historicalMin) { c_historicalMin = historicalMin; }
    double getHistoricalMin() const { return c_historicalMin; }

    void setHistoricalMax(double historicalMax) { c_historicalMax = historicalMax; }
    double getHistoricalMax() const { return c_historicalMax; }

    void setHintMin(double hintMin) { c_axisMin = hintMin; }
    double getHintMin() const { return c_axisMin; }

    void setHintMax(double hintMax) { c_axisMax = hintMax; }
    double getHintMax() const { return c_axisMax; }

    void setHorizontalAxis(QByteArray horizontalAxis) { c_horizontalAxis = horizontalAxis; }
    QByteArray getHorizontalAxis() const { return c_horizontalAxis; }

    void setVerticalAxis(QByteArray verticalAxis) { c_verticalAxis = verticalAxis; }
    QByteArray getVerticalAxis() const { return c_verticalAxis; }

    void setLineSeries(QLineSeries *lineSeries) { c_lineSeries = lineSeries; }
    QLineSeries *getLineSeries() const { return c_lineSeries; }

    void setAxis(QValueAxis *axis) { c_axis = axis; }
    QValueAxis *getAxis() const { return c_axis; }

    void setAutoScaleAxis(bool autoScaleAxis) { c_autoScaleAxis = autoScaleAxis; }
    bool getAutoScaleAxis() const { return c_autoScaleAxis; }

    void setAxisVisible(bool visible);
    bool isAxisVisible() const { return c_axisVisible; }

    void setAlignment(Qt::Alignment alignment) { c_alignment = alignment; }
    Qt::Alignment getAlignment() const { return c_alignment; }

    void setPlot(bool plot) { c_plot = plot; }
    bool getPlot() const { return c_plot; }

protected:
    QByteArray c_channelName;

    double c_historicalMin, c_historicalMax;
    double c_axisMin, c_axisMax;

    QByteArray c_horizontalAxis;
    QByteArray c_verticalAxis;

    QLineSeries *c_lineSeries;
    QValueAxis *c_axis;
    bool c_autoScaleAxis;
    bool c_axisVisible;
    Qt::Alignment c_alignment;
    bool c_plot = true;
};

}

#endif // CHARTCHANNEL_H
