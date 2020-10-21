/********************************************************************************
** Form generated from reading UI file 'dashwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHWIDGET_H
#define UI_DASHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDashWidget
{
public:

    void setupUi(QWidget *DDashWidget)
    {
        if (DDashWidget->objectName().isEmpty())
            DDashWidget->setObjectName(QString::fromUtf8("DDashWidget"));
        DDashWidget->resize(344, 336);
        DDashWidget->setFocusPolicy(Qt::ClickFocus);
        DDashWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        retranslateUi(DDashWidget);

        QMetaObject::connectSlotsByName(DDashWidget);
    } // setupUi

    void retranslateUi(QWidget *DDashWidget)
    {
        DDashWidget->setWindowTitle(QApplication::translate("DDashWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDashWidget: public Ui_DDashWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHWIDGET_H
