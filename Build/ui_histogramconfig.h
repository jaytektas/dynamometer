/********************************************************************************
** Form generated from reading UI file 'histogramconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMCONFIG_H
#define UI_HISTOGRAMCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DHistogramConfig
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *seriesColor;
    QComboBox *currentChannel;
    QComboBox *horizontalAxis;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_7;
    QComboBox *verticalAxis;
    QPushButton *deleteVerticalAxis;
    QPushButton *pushButton_2;
    QPushButton *deleteHorizontalAxis;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QComboBox *alignment;
    QLabel *label_9;
    QPushButton *minorGridLineColor;
    QLabel *label_10;
    QPushButton *labelColor;
    QLabel *label_5;
    QLineEdit *minorTicks;
    QLabel *label_6;
    QCheckBox *autoScale;
    QLineEdit *minimum;
    QLineEdit *maximum;
    QLabel *label_15;
    QLabel *label_4;
    QLabel *label_16;
    QLineEdit *title;
    QCheckBox *visible;
    QLabel *label_11;
    QLineEdit *majorTicks;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_13;
    QPushButton *majorGridLineColor;
    QLineEdit *labelFormat;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DHistogramConfig)
    {
        if (DHistogramConfig->objectName().isEmpty())
            DHistogramConfig->setObjectName(QString::fromUtf8("DHistogramConfig"));
        DHistogramConfig->resize(671, 699);
        verticalLayout = new QVBoxLayout(DHistogramConfig);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(DHistogramConfig);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tableWidget = new QTableWidget(splitter);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        splitter->addWidget(tableWidget);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        seriesColor = new QPushButton(groupBox_2);
        seriesColor->setObjectName(QString::fromUtf8("seriesColor"));

        gridLayout->addWidget(seriesColor, 3, 1, 1, 1);

        currentChannel = new QComboBox(groupBox_2);
        currentChannel->setObjectName(QString::fromUtf8("currentChannel"));

        gridLayout->addWidget(currentChannel, 0, 1, 1, 1);

        horizontalAxis = new QComboBox(groupBox_2);
        horizontalAxis->setObjectName(QString::fromUtf8("horizontalAxis"));

        gridLayout->addWidget(horizontalAxis, 2, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        verticalAxis = new QComboBox(groupBox_2);
        verticalAxis->setObjectName(QString::fromUtf8("verticalAxis"));

        gridLayout->addWidget(verticalAxis, 1, 1, 1, 1);

        deleteVerticalAxis = new QPushButton(groupBox_2);
        deleteVerticalAxis->setObjectName(QString::fromUtf8("deleteVerticalAxis"));
        deleteVerticalAxis->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteVerticalAxis->setIcon(icon);

        gridLayout->addWidget(deleteVerticalAxis, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(25, 25));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        deleteHorizontalAxis = new QPushButton(groupBox_2);
        deleteHorizontalAxis->setObjectName(QString::fromUtf8("deleteHorizontalAxis"));
        deleteHorizontalAxis->setMaximumSize(QSize(25, 25));
        deleteHorizontalAxis->setIcon(icon);

        gridLayout->addWidget(deleteHorizontalAxis, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(17, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        splitter->addWidget(groupBox_2);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 10, 0, 1, 1);

        alignment = new QComboBox(groupBox);
        alignment->addItem(QString());
        alignment->addItem(QString());
        alignment->addItem(QString());
        alignment->addItem(QString());
        alignment->setObjectName(QString::fromUtf8("alignment"));

        gridLayout_2->addWidget(alignment, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 11, 0, 1, 1);

        minorGridLineColor = new QPushButton(groupBox);
        minorGridLineColor->setObjectName(QString::fromUtf8("minorGridLineColor"));

        gridLayout_2->addWidget(minorGridLineColor, 6, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 7, 0, 1, 1);

        labelColor = new QPushButton(groupBox);
        labelColor->setObjectName(QString::fromUtf8("labelColor"));

        gridLayout_2->addWidget(labelColor, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        minorTicks = new QLineEdit(groupBox);
        minorTicks->setObjectName(QString::fromUtf8("minorTicks"));

        gridLayout_2->addWidget(minorTicks, 5, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        autoScale = new QCheckBox(groupBox);
        autoScale->setObjectName(QString::fromUtf8("autoScale"));

        gridLayout_2->addWidget(autoScale, 10, 1, 1, 1);

        minimum = new QLineEdit(groupBox);
        minimum->setObjectName(QString::fromUtf8("minimum"));

        gridLayout_2->addWidget(minimum, 7, 1, 1, 1);

        maximum = new QLineEdit(groupBox);
        maximum->setObjectName(QString::fromUtf8("maximum"));

        gridLayout_2->addWidget(maximum, 8, 1, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 9, 0, 1, 1);

        title = new QLineEdit(groupBox);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout_2->addWidget(title, 0, 1, 1, 1);

        visible = new QCheckBox(groupBox);
        visible->setObjectName(QString::fromUtf8("visible"));

        gridLayout_2->addWidget(visible, 11, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 8, 0, 1, 1);

        majorTicks = new QLineEdit(groupBox);
        majorTicks->setObjectName(QString::fromUtf8("majorTicks"));

        gridLayout_2->addWidget(majorTicks, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 6, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        majorGridLineColor = new QPushButton(groupBox);
        majorGridLineColor->setObjectName(QString::fromUtf8("majorGridLineColor"));

        gridLayout_2->addWidget(majorGridLineColor, 4, 1, 1, 1);

        labelFormat = new QLineEdit(groupBox);
        labelFormat->setObjectName(QString::fromUtf8("labelFormat"));

        gridLayout_2->addWidget(labelFormat, 9, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        splitter->addWidget(groupBox);
        splitter_2->addWidget(splitter);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMouseTracking(false);
        frame->setFocusPolicy(Qt::NoFocus);
        frame->setContextMenuPolicy(Qt::DefaultContextMenu);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        splitter_2->addWidget(frame);

        verticalLayout->addWidget(splitter_2);

        buttonBox = new QDialogButtonBox(DHistogramConfig);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DHistogramConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), DHistogramConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DHistogramConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(DHistogramConfig);
    } // setupUi

    void retranslateUi(QDialog *DHistogramConfig)
    {
        DHistogramConfig->setWindowTitle(QApplication::translate("DHistogramConfig", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("DHistogramConfig", "Line Series Plot", nullptr));
        label_2->setText(QApplication::translate("DHistogramConfig", "Horizontal Axis", nullptr));
        seriesColor->setText(QString());
        label->setText(QApplication::translate("DHistogramConfig", "Channel", nullptr));
        label_3->setText(QApplication::translate("DHistogramConfig", "Vertical Axis", nullptr));
        label_7->setText(QApplication::translate("DHistogramConfig", "Color", nullptr));
        deleteVerticalAxis->setText(QString());
        pushButton_2->setText(QString());
        deleteHorizontalAxis->setText(QString());
        groupBox->setTitle(QApplication::translate("DHistogramConfig", "Channel Axis", nullptr));
        label_12->setText(QApplication::translate("DHistogramConfig", "Auto Scale", nullptr));
        alignment->setItemText(0, QApplication::translate("DHistogramConfig", "Left", nullptr));
        alignment->setItemText(1, QApplication::translate("DHistogramConfig", "Right", nullptr));
        alignment->setItemText(2, QApplication::translate("DHistogramConfig", "Bottom", nullptr));
        alignment->setItemText(3, QApplication::translate("DHistogramConfig", "Top", nullptr));

        label_9->setText(QApplication::translate("DHistogramConfig", "Visible", nullptr));
        minorGridLineColor->setText(QString());
        label_10->setText(QApplication::translate("DHistogramConfig", "Minimum", nullptr));
        labelColor->setText(QString());
        label_5->setText(QApplication::translate("DHistogramConfig", "Major Ticks", nullptr));
        label_6->setText(QApplication::translate("DHistogramConfig", "Minor Grid Line Color", nullptr));
        autoScale->setText(QString());
        label_15->setText(QApplication::translate("DHistogramConfig", "Label Color", nullptr));
        label_4->setText(QApplication::translate("DHistogramConfig", "Title", nullptr));
        label_16->setText(QApplication::translate("DHistogramConfig", "Label Format", nullptr));
        visible->setText(QString());
        label_11->setText(QApplication::translate("DHistogramConfig", "Maximum", nullptr));
        label_8->setText(QApplication::translate("DHistogramConfig", "Alignment", nullptr));
        label_14->setText(QApplication::translate("DHistogramConfig", "Minor LIine Color", nullptr));
        label_13->setText(QApplication::translate("DHistogramConfig", "Major Grid Line Color", nullptr));
        majorGridLineColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DHistogramConfig: public Ui_DHistogramConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMCONFIG_H
