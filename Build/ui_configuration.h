/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DConfiguration
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *configurationLineEdit;
    QLineEdit *workspaceLineEdit;
    QPushButton *workspacePushButton;
    QLabel *label_3;
    QPushButton *channelsPushButton;
    QLabel *label;
    QLineEdit *channelsLineEdit;
    QPushButton *configurationPushButton;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DConfiguration)
    {
        if (DConfiguration->objectName().isEmpty())
            DConfiguration->setObjectName(QString::fromUtf8("DConfiguration"));
        DConfiguration->resize(755, 483);
        verticalLayout = new QVBoxLayout(DConfiguration);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(DConfiguration);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 581, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        configurationLineEdit = new QLineEdit(gridLayoutWidget);
        configurationLineEdit->setObjectName(QString::fromUtf8("configurationLineEdit"));

        gridLayout->addWidget(configurationLineEdit, 1, 1, 1, 1);

        workspaceLineEdit = new QLineEdit(gridLayoutWidget);
        workspaceLineEdit->setObjectName(QString::fromUtf8("workspaceLineEdit"));

        gridLayout->addWidget(workspaceLineEdit, 0, 1, 1, 1);

        workspacePushButton = new QPushButton(gridLayoutWidget);
        workspacePushButton->setObjectName(QString::fromUtf8("workspacePushButton"));
        workspacePushButton->setMaximumSize(QSize(24, 24));

        gridLayout->addWidget(workspacePushButton, 0, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        channelsPushButton = new QPushButton(gridLayoutWidget);
        channelsPushButton->setObjectName(QString::fromUtf8("channelsPushButton"));
        channelsPushButton->setMaximumSize(QSize(24, 24));

        gridLayout->addWidget(channelsPushButton, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        channelsLineEdit = new QLineEdit(gridLayoutWidget);
        channelsLineEdit->setObjectName(QString::fromUtf8("channelsLineEdit"));

        gridLayout->addWidget(channelsLineEdit, 2, 1, 1, 1);

        configurationPushButton = new QPushButton(gridLayoutWidget);
        configurationPushButton->setObjectName(QString::fromUtf8("configurationPushButton"));
        configurationPushButton->setMaximumSize(QSize(24, 24));

        gridLayout->addWidget(configurationPushButton, 1, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(DConfiguration);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DConfiguration);
        QObject::connect(buttonBox, SIGNAL(accepted()), DConfiguration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DConfiguration, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DConfiguration);
    } // setupUi

    void retranslateUi(QDialog *DConfiguration)
    {
        DConfiguration->setWindowTitle(QApplication::translate("DConfiguration", "Dialog", nullptr));
        label_2->setText(QApplication::translate("DConfiguration", "Channels", nullptr));
#ifndef QT_NO_TOOLTIP
        configurationLineEdit->setToolTip(QApplication::translate("DConfiguration", "Default configuration file that is loaded upon program start", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        workspaceLineEdit->setToolTip(QApplication::translate("DConfiguration", "Root director of the workspace as displayed in the file tree", nullptr));
#endif // QT_NO_TOOLTIP
        workspacePushButton->setText(QApplication::translate("DConfiguration", "...", nullptr));
        label_3->setText(QApplication::translate("DConfiguration", "Configuration", nullptr));
        channelsPushButton->setText(QApplication::translate("DConfiguration", "...", nullptr));
        label->setText(QApplication::translate("DConfiguration", "workspace", nullptr));
#ifndef QT_NO_TOOLTIP
        channelsLineEdit->setToolTip(QApplication::translate("DConfiguration", "Default channel list that is loaded at program start up", nullptr));
#endif // QT_NO_TOOLTIP
        configurationPushButton->setText(QApplication::translate("DConfiguration", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DConfiguration", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DConfiguration", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DConfiguration: public Ui_DConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
