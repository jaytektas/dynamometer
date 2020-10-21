/********************************************************************************
** Form generated from reading UI file 'chartviewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTVIEWWIDGET_H
#define UI_CHARTVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chartwidget.h"

QT_BEGIN_NAMESPACE

class Ui_DChartViewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    DChartWidget *chart1;

    void setupUi(QWidget *DChartViewWidget)
    {
        if (DChartViewWidget->objectName().isEmpty())
            DChartViewWidget->setObjectName(QString::fromUtf8("DChartViewWidget"));
        DChartViewWidget->resize(568, 519);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DChartViewWidget->sizePolicy().hasHeightForWidth());
        DChartViewWidget->setSizePolicy(sizePolicy);
        DChartViewWidget->setFocusPolicy(Qt::StrongFocus);
        verticalLayout = new QVBoxLayout(DChartViewWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DChartViewWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chart1 = new DChartWidget(splitter);
        chart1->setObjectName(QString::fromUtf8("chart1"));
        chart1->setMinimumSize(QSize(0, 0));
        splitter->addWidget(chart1);

        verticalLayout->addWidget(splitter);


        retranslateUi(DChartViewWidget);

        QMetaObject::connectSlotsByName(DChartViewWidget);
    } // setupUi

    void retranslateUi(QWidget *DChartViewWidget)
    {
        DChartViewWidget->setWindowTitle(QApplication::translate("DChartViewWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChartViewWidget: public Ui_DChartViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTVIEWWIDGET_H
