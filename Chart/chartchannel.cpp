#include "chartchannel.h"

namespace Dynamometer
{
DChartChannel::DChartChannel()
{

}

DChartChannel::DChartChannel(const DChartChannel &chartChannel)   // copy constructor
{
    setChannelName(chartChannel.getChannelName());
    setHintMin(chartChannel.getHintMin());
    setHintMax(chartChannel.getHintMax());
    setHistoricalMin(chartChannel.getHistoricalMin());
    setHistoricalMax(chartChannel.getHistoricalMax());
    setHorizontalAxis(chartChannel.getHorizontalAxis());
    setVerticalAxis(chartChannel.getVerticalAxis());
    setLineSeries(chartChannel.getLineSeries());
    setAxis(nullptr);
    setAlignment(chartChannel.getAlignment());
    setAutoScaleAxis(chartChannel.getAutoScaleAxis());
    setPlot(chartChannel.getPlot());
}

void DChartChannel::setAxisVisible(bool visible)
{
    if (getAxis()) getAxis()->setVisible(visible);
}

}
