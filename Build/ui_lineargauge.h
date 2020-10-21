/********************************************************************************
** Form generated from reading UI file 'lineargauge.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARGAUGE_H
#define UI_LINEARGAUGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DLinearGauge
{
public:

    void setupUi(QWidget *DLinearGauge)
    {
        if (DLinearGauge->objectName().isEmpty())
            DLinearGauge->setObjectName(QString::fromUtf8("DLinearGauge"));
        DLinearGauge->resize(232, 280);
        DLinearGauge->setMouseTracking(true);
        DLinearGauge->setFocusPolicy(Qt::ClickFocus);
        DLinearGauge->setContextMenuPolicy(Qt::CustomContextMenu);

        retranslateUi(DLinearGauge);

        QMetaObject::connectSlotsByName(DLinearGauge);
    } // setupUi

    void retranslateUi(QWidget *DLinearGauge)
    {
        DLinearGauge->setWindowTitle(QApplication::translate("DLinearGauge", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DLinearGauge: public Ui_DLinearGauge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARGAUGE_H
