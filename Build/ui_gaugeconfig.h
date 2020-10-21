/********************************************************************************
** Form generated from reading UI file 'gaugeconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUGECONFIG_H
#define UI_GAUGECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DGaugeConfig
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DGaugeConfig)
    {
        if (DGaugeConfig->objectName().isEmpty())
            DGaugeConfig->setObjectName(QString::fromUtf8("DGaugeConfig"));
        DGaugeConfig->resize(699, 697);
        verticalLayout = new QVBoxLayout(DGaugeConfig);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DGaugeConfig);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableWidget = new QTableWidget(splitter);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        splitter->addWidget(tableWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        buttonBox = new QDialogButtonBox(DGaugeConfig);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DGaugeConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), DGaugeConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DGaugeConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(DGaugeConfig);
    } // setupUi

    void retranslateUi(QDialog *DGaugeConfig)
    {
        DGaugeConfig->setWindowTitle(QApplication::translate("DGaugeConfig", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DGaugeConfig: public Ui_DGaugeConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUGECONFIG_H
