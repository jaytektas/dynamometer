#include "chartviewwidget.h"
#include "ui_chartviewwidget.h"
#include "channellist.h"

#include <QListWidgetItem>
#include <QtCharts>

using namespace QtCharts;

namespace Dynamometer
{
DChartViewWidget::DChartViewWidget(QWidget *parent) : QWidget(parent), ui(new Ui::DChartViewWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

DChartViewWidget::~DChartViewWidget()
{
    delete ui;
}

void DChartViewWidget::selectedRunsChanged()
{
    // notify each chart widget of changes
    ui->chart1->selectedRunsChanged();
}
}
