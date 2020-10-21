/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboPortName;
    QLabel *label_3;
    QComboBox *comboBaudRate;
    QLabel *label_6;
    QComboBox *comboDataBits;
    QLabel *label_8;
    QComboBox *comboParity;
    QLabel *label_7;
    QComboBox *comboStopBits;
    QLabel *label_2;
    QComboBox *comboFlowControl;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->resize(224, 275);
        verticalLayout_2 = new QVBoxLayout(ConnectionDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(ConnectionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboPortName = new QComboBox(groupBox);
        comboPortName->setObjectName(QString::fromUtf8("comboPortName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboPortName);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        comboBaudRate = new QComboBox(groupBox);
        comboBaudRate->setObjectName(QString::fromUtf8("comboBaudRate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBaudRate);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        comboDataBits = new QComboBox(groupBox);
        comboDataBits->setObjectName(QString::fromUtf8("comboDataBits"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboDataBits);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        comboParity = new QComboBox(groupBox);
        comboParity->setObjectName(QString::fromUtf8("comboParity"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboParity);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        comboStopBits = new QComboBox(groupBox);
        comboStopBits->setObjectName(QString::fromUtf8("comboStopBits"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboStopBits);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        comboFlowControl = new QComboBox(groupBox);
        comboFlowControl->setObjectName(QString::fromUtf8("comboFlowControl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboFlowControl);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(ConnectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(comboPortName);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboPortName, comboBaudRate);
        QWidget::setTabOrder(comboBaudRate, comboDataBits);
        QWidget::setTabOrder(comboDataBits, comboParity);
        QWidget::setTabOrder(comboParity, comboStopBits);
        QWidget::setTabOrder(comboStopBits, comboFlowControl);

        retranslateUi(ConnectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QApplication::translate("ConnectionDialog", "Connection Settings", nullptr));
        groupBox->setTitle(QApplication::translate("ConnectionDialog", "Port Settings", nullptr));
        label->setText(QApplication::translate("ConnectionDialog", "Port", nullptr));
        label_3->setText(QApplication::translate("ConnectionDialog", "Baud Rate", nullptr));
        label_6->setText(QApplication::translate("ConnectionDialog", "Data Bits", nullptr));
        label_8->setText(QApplication::translate("ConnectionDialog", "Parity", nullptr));
        label_7->setText(QApplication::translate("ConnectionDialog", "Stop Bits", nullptr));
        label_2->setText(QApplication::translate("ConnectionDialog", "Flow Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
