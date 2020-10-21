#include "dashwidget.h"
#include "ui_dashwidget.h"
#include "dialgauge.h"
#include "lineargauge.h"
#include "lcdgauge.h"
#include "labelgauge.h"
#include "widgetcontainer.h"
#include "histogramwidget.h"

#include <QMenu>
#include <QAction>
#include <QColorDialog>
#include <QPalette>
#include <QLCDNumber>
#include <QTabWidget>

namespace Dynamometer
{
DDashWidget::DDashWidget(QWidget *parent) : QWidget(parent), ui(new Ui::DDashWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
}

DDashWidget::~DDashWidget()
{
    delete ui;
}

void DDashWidget::undockFromTab()
{
    emit undock();
    d_docked = false;
}

void DDashWidget::dockToTab()
{
    emit dock();
    d_docked = true;
}

void DDashWidget::showContextMenu(const QPoint & point)
{
    d_context = point;

    QMenu contextMenu("Dash Menu", this);
    contextMenu.addAction("Add Dial Gauge...", this, SLOT(addDialGauge()));
    contextMenu.addAction("Add Linear Gauge...", this, SLOT(addLinearGauge()));
    contextMenu.addAction("Add LCD Segment...", this, SLOT(addLCDNumber()));
    contextMenu.addAction("Add Label...", this, SLOT(addLabel()));
    contextMenu.addAction("Add Histogram...", this, SLOT(addHistogram()));

    contextMenu.addAction("Background Color...", this, SLOT(changeBackground()));
    if (d_docked) contextMenu.addAction("Undock tab", this, SLOT(undockFromTab()));
    else contextMenu.addAction("Dock to tab", this, SLOT(dockToTab()));
    contextMenu.addSeparator();
    contextMenu.exec((mapToGlobal(point)));

    QObject::connect(&contextMenu, SIGNAL(triggered(QAction *)), this, SLOT(contextMenuChannelSelected(QAction *)));
}

void DDashWidget::contextMenuChannelSelected(QAction *)
{
}

void DDashWidget::addHistogram()
{
    DHistogramWidget *newHistogram = new DHistogramWidget(this);
    newHistogram->setContextEnabled(true);
    newHistogram->move(d_context);
    newHistogram->setGeometry(d_context.x(), d_context.y(), 100, 100);
    newHistogram->show();
}

void DDashWidget::addLabel()
{
    DLabelGauge *newLabel = new DLabelGauge(this);
    newLabel->setContextEnabled(true);
    newLabel->move(d_context);
    newLabel->setGeometry(d_context.x(), d_context.y(), 100, 100);
    newLabel->show();
}

void DDashWidget::addLCDNumber()
{
    DLCDGauge *newLCDNumber = new DLCDGauge(this);
    newLCDNumber->setContextEnabled(true);
    newLCDNumber->move(d_context);
    newLCDNumber->setGeometry(d_context.x(), d_context.y(), 100, 100);
    newLCDNumber->show();
}

void DDashWidget::changeBackground()
{
    QColorDialog *colorDialog = new QColorDialog(this);
    QPalette pal;

    QColor color = colorDialog->getColor();
    if (!color.isValid()) return;

    this->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, color);
    setPalette(pal);
}

void DDashWidget::addDialGauge()
{
    DDialGauge *newDialGauge = new DDialGauge(this);
    newDialGauge->setContextEnabled(true);
    newDialGauge->move(d_context);
    newDialGauge->setGeometry(d_context.x(), d_context.y(), 100, 100);
    newDialGauge->show();
}

void DDashWidget::addLinearGauge()
{
    DLinearGauge *newLinearGauge = new DLinearGauge(this);
    newLinearGauge->setContextEnabled(true);
    newLinearGauge->move(d_context);
    newLinearGauge->setGeometry(d_context.x(), d_context.y(), 100, 100);
    newLinearGauge->show();
}

}
