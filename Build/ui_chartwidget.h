/********************************************************************************
** Form generated from reading UI file 'chartwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWIDGET_H
#define UI_CHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DChartWidget
{
public:

    void setupUi(QWidget *DChartWidget)
    {
        if (DChartWidget->objectName().isEmpty())
            DChartWidget->setObjectName(QString::fromUtf8("DChartWidget"));
        DChartWidget->setEnabled(true);
        DChartWidget->resize(598, 493);
        DChartWidget->setFocusPolicy(Qt::NoFocus);
        DChartWidget->setAcceptDrops(true);

        retranslateUi(DChartWidget);

        QMetaObject::connectSlotsByName(DChartWidget);
    } // setupUi

    void retranslateUi(QWidget *DChartWidget)
    {
        DChartWidget->setWindowTitle(QApplication::translate("DChartWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChartWidget: public Ui_DChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWIDGET_H
