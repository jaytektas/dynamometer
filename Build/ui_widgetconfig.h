/********************************************************************************
** Form generated from reading UI file 'widgetconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCONFIG_H
#define UI_WIDGETCONFIG_H

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

class Ui_DWidgetConfig
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DWidgetConfig)
    {
        if (DWidgetConfig->objectName().isEmpty())
            DWidgetConfig->setObjectName(QString::fromUtf8("DWidgetConfig"));
        DWidgetConfig->resize(699, 697);
        verticalLayout = new QVBoxLayout(DWidgetConfig);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DWidgetConfig);
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

        buttonBox = new QDialogButtonBox(DWidgetConfig);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DWidgetConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), DWidgetConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DWidgetConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(DWidgetConfig);
    } // setupUi

    void retranslateUi(QDialog *DWidgetConfig)
    {
        DWidgetConfig->setWindowTitle(QApplication::translate("DWidgetConfig", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DWidgetConfig: public Ui_DWidgetConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCONFIG_H
