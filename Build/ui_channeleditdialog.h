/********************************************************************************
** Form generated from reading UI file 'channeleditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELEDITDIALOG_H
#define UI_CHANNELEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DChannelEditDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLineEdit *offset;
    QSpacerItem *horizontalSpacer;
    QComboBox *type;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *name;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_22;
    QLineEdit *value;
    QLabel *label_21;
    QLineEdit *expression;
    QComboBox *dataType;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *upperCriticalStart;
    QLineEdit *upperWarningEnd;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *lowerCriticalEnd;
    QLineEdit *upperCriticalEnd;
    QLabel *label_16;
    QLabel *label_6;
    QLabel *label_19;
    QLineEdit *lowerWarningStart;
    QLineEdit *lowerWarningEnd;
    QLabel *label_12;
    QLineEdit *upperWarningStart;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_18;
    QLineEdit *scale;
    QLabel *label_14;
    QLabel *label_11;
    QLineEdit *filler;
    QLabel *label_17;
    QLineEdit *validStart;
    QLineEdit *digits;
    QLineEdit *validEnd;
    QLineEdit *units;
    QLabel *label_15;
    QLineEdit *minimum;
    QLabel *label_8;
    QLineEdit *lowerCriticalStart;
    QLineEdit *maximum;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_26;
    QLabel *label_25;
    QLineEdit *majorTicks;
    QCheckBox *autoScaleAxis;
    QLineEdit *labelFormat;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *minorTicks;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DChannelEditDialog)
    {
        if (DChannelEditDialog->objectName().isEmpty())
            DChannelEditDialog->setObjectName(QString::fromUtf8("DChannelEditDialog"));
        DChannelEditDialog->resize(718, 815);
        verticalLayout_3 = new QVBoxLayout(DChannelEditDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter_2 = new QSplitter(DChannelEditDialog);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        offset = new QLineEdit(groupBox_2);
        offset->setObjectName(QString::fromUtf8("offset"));
        offset->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(offset, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 3, 1, 1);

        type = new QComboBox(groupBox_2);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName(QString::fromUtf8("type"));
        type->setMinimumSize(QSize(0, 0));
        type->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(type, 1, 1, 1, 1);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        name = new QLineEdit(groupBox_2);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout_3->addWidget(name, 0, 1, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 3, 0, 1, 1);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 5, 0, 1, 1);

        value = new QLineEdit(groupBox_2);
        value->setObjectName(QString::fromUtf8("value"));
        value->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(value, 5, 1, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 0, 0, 1, 1);

        expression = new QLineEdit(groupBox_2);
        expression->setObjectName(QString::fromUtf8("expression"));

        gridLayout_3->addWidget(expression, 2, 1, 1, 3);

        dataType = new QComboBox(groupBox_2);
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->addItem(QString());
        dataType->setObjectName(QString::fromUtf8("dataType"));
        dataType->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(dataType, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        splitter_2->addWidget(groupBox_2);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        upperCriticalStart = new QLineEdit(groupBox);
        upperCriticalStart->setObjectName(QString::fromUtf8("upperCriticalStart"));
        upperCriticalStart->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(upperCriticalStart, 11, 1, 1, 1);

        upperWarningEnd = new QLineEdit(groupBox);
        upperWarningEnd->setObjectName(QString::fromUtf8("upperWarningEnd"));
        upperWarningEnd->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(upperWarningEnd, 10, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        lowerCriticalEnd = new QLineEdit(groupBox);
        lowerCriticalEnd->setObjectName(QString::fromUtf8("lowerCriticalEnd"));
        lowerCriticalEnd->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lowerCriticalEnd, 4, 1, 1, 1);

        upperCriticalEnd = new QLineEdit(groupBox);
        upperCriticalEnd->setObjectName(QString::fromUtf8("upperCriticalEnd"));
        upperCriticalEnd->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(upperCriticalEnd, 12, 1, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 13, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 15, 0, 1, 1);

        lowerWarningStart = new QLineEdit(groupBox);
        lowerWarningStart->setObjectName(QString::fromUtf8("lowerWarningStart"));
        lowerWarningStart->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lowerWarningStart, 5, 1, 1, 1);

        lowerWarningEnd = new QLineEdit(groupBox);
        lowerWarningEnd->setObjectName(QString::fromUtf8("lowerWarningEnd"));
        lowerWarningEnd->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lowerWarningEnd, 6, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 9, 0, 1, 1);

        upperWarningStart = new QLineEdit(groupBox);
        upperWarningStart->setObjectName(QString::fromUtf8("upperWarningStart"));
        upperWarningStart->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(upperWarningStart, 9, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 10, 0, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        scale = new QLineEdit(groupBox);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(scale, 15, 1, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 11, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        filler = new QLineEdit(groupBox);
        filler->setObjectName(QString::fromUtf8("filler"));
        filler->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(filler, 14, 1, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 14, 0, 1, 1);

        validStart = new QLineEdit(groupBox);
        validStart->setObjectName(QString::fromUtf8("validStart"));
        validStart->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(validStart, 7, 1, 1, 1);

        digits = new QLineEdit(groupBox);
        digits->setObjectName(QString::fromUtf8("digits"));
        digits->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(digits, 13, 1, 1, 1);

        validEnd = new QLineEdit(groupBox);
        validEnd->setObjectName(QString::fromUtf8("validEnd"));
        validEnd->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(validEnd, 8, 1, 1, 1);

        units = new QLineEdit(groupBox);
        units->setObjectName(QString::fromUtf8("units"));
        units->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(units, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 12, 0, 1, 1);

        minimum = new QLineEdit(groupBox);
        minimum->setObjectName(QString::fromUtf8("minimum"));
        minimum->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(minimum, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        lowerCriticalStart = new QLineEdit(groupBox);
        lowerCriticalStart->setObjectName(QString::fromUtf8("lowerCriticalStart"));
        lowerCriticalStart->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lowerCriticalStart, 3, 1, 1, 1);

        maximum = new QLineEdit(groupBox);
        maximum->setObjectName(QString::fromUtf8("maximum"));
        maximum->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(maximum, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        splitter->addWidget(groupBox);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_2->addWidget(label_26, 3, 0, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_2->addWidget(label_25, 2, 0, 1, 1);

        majorTicks = new QLineEdit(groupBox_3);
        majorTicks->setObjectName(QString::fromUtf8("majorTicks"));
        majorTicks->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(majorTicks, 0, 1, 1, 1);

        autoScaleAxis = new QCheckBox(groupBox_3);
        autoScaleAxis->setObjectName(QString::fromUtf8("autoScaleAxis"));
        autoScaleAxis->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(autoScaleAxis, 3, 1, 1, 1);

        labelFormat = new QLineEdit(groupBox_3);
        labelFormat->setObjectName(QString::fromUtf8("labelFormat"));
        labelFormat->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(labelFormat, 2, 1, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 0, 0, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 1, 0, 1, 1);

        minorTicks = new QLineEdit(groupBox_3);
        minorTicks->setObjectName(QString::fromUtf8("minorTicks"));
        minorTicks->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(minorTicks, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        splitter->addWidget(groupBox_3);
        splitter_2->addWidget(splitter);

        verticalLayout_3->addWidget(splitter_2);

        buttonBox = new QDialogButtonBox(DChannelEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        QWidget::setTabOrder(name, type);
        QWidget::setTabOrder(type, expression);
        QWidget::setTabOrder(expression, dataType);
        QWidget::setTabOrder(dataType, offset);
        QWidget::setTabOrder(offset, value);
        QWidget::setTabOrder(value, minimum);
        QWidget::setTabOrder(minimum, maximum);
        QWidget::setTabOrder(maximum, lowerCriticalStart);
        QWidget::setTabOrder(lowerCriticalStart, lowerCriticalEnd);
        QWidget::setTabOrder(lowerCriticalEnd, lowerWarningStart);
        QWidget::setTabOrder(lowerWarningStart, lowerWarningEnd);
        QWidget::setTabOrder(lowerWarningEnd, validStart);
        QWidget::setTabOrder(validStart, validEnd);
        QWidget::setTabOrder(validEnd, upperWarningStart);
        QWidget::setTabOrder(upperWarningStart, upperWarningEnd);
        QWidget::setTabOrder(upperWarningEnd, upperCriticalStart);
        QWidget::setTabOrder(upperCriticalStart, upperCriticalEnd);
        QWidget::setTabOrder(upperCriticalEnd, digits);
        QWidget::setTabOrder(digits, filler);
        QWidget::setTabOrder(filler, scale);

        retranslateUi(DChannelEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DChannelEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DChannelEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DChannelEditDialog);
    } // setupUi

    void retranslateUi(QDialog *DChannelEditDialog)
    {
        DChannelEditDialog->setWindowTitle(QApplication::translate("DChannelEditDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("DChannelEditDialog", "Channel", nullptr));
        type->setItemText(0, QApplication::translate("DChannelEditDialog", "STATUS", nullptr));
        type->setItemText(1, QApplication::translate("DChannelEditDialog", "APPLICATION", nullptr));
        type->setItemText(2, QApplication::translate("DChannelEditDialog", "CONSTANT", nullptr));
        type->setItemText(3, QApplication::translate("DChannelEditDialog", "USER", nullptr));

        label_20->setText(QApplication::translate("DChannelEditDialog", "Offset", nullptr));
        label_5->setText(QApplication::translate("DChannelEditDialog", "Expression", nullptr));
        label->setText(QApplication::translate("DChannelEditDialog", "Type", nullptr));
        label_2->setText(QApplication::translate("DChannelEditDialog", "Data Type", nullptr));
        label_22->setText(QApplication::translate("DChannelEditDialog", "Value", nullptr));
        label_21->setText(QApplication::translate("DChannelEditDialog", "Name", nullptr));
        dataType->setItemText(0, QApplication::translate("DChannelEditDialog", "NaN", nullptr));
        dataType->setItemText(1, QApplication::translate("DChannelEditDialog", "UINT8", nullptr));
        dataType->setItemText(2, QApplication::translate("DChannelEditDialog", "INT8", nullptr));
        dataType->setItemText(3, QApplication::translate("DChannelEditDialog", "UINT16", nullptr));
        dataType->setItemText(4, QApplication::translate("DChannelEditDialog", "INT16", nullptr));
        dataType->setItemText(5, QApplication::translate("DChannelEditDialog", "UINT32", nullptr));
        dataType->setItemText(6, QApplication::translate("DChannelEditDialog", "INT32", nullptr));

        groupBox->setTitle(QApplication::translate("DChannelEditDialog", "Gauge Hints", nullptr));
        label_3->setText(QApplication::translate("DChannelEditDialog", "Minimum", nullptr));
        label_4->setText(QApplication::translate("DChannelEditDialog", "Maximum", nullptr));
        label_7->setText(QApplication::translate("DChannelEditDialog", "Lower Critical End", nullptr));
        label_16->setText(QApplication::translate("DChannelEditDialog", "Digits", nullptr));
        label_6->setText(QApplication::translate("DChannelEditDialog", "Lower Critical Start", nullptr));
        label_19->setText(QApplication::translate("DChannelEditDialog", "Scale", nullptr));
        label_12->setText(QApplication::translate("DChannelEditDialog", "Upper Warning Start", nullptr));
        label_10->setText(QApplication::translate("DChannelEditDialog", "Valid Start", nullptr));
        label_9->setText(QApplication::translate("DChannelEditDialog", "Lower Warning End", nullptr));
        label_13->setText(QApplication::translate("DChannelEditDialog", "Upper Warning End", nullptr));
        label_18->setText(QApplication::translate("DChannelEditDialog", "Units", nullptr));
        label_14->setText(QApplication::translate("DChannelEditDialog", "Upper Critical Start", nullptr));
        label_11->setText(QApplication::translate("DChannelEditDialog", "Valid End", nullptr));
        label_17->setText(QApplication::translate("DChannelEditDialog", "Filler", nullptr));
        label_15->setText(QApplication::translate("DChannelEditDialog", "Upper Critical End", nullptr));
        label_8->setText(QApplication::translate("DChannelEditDialog", "Lower Warning Start", nullptr));
        groupBox_3->setTitle(QApplication::translate("DChannelEditDialog", "Chart Hints", nullptr));
        label_26->setText(QApplication::translate("DChannelEditDialog", "Auto scale axis", nullptr));
        label_25->setText(QApplication::translate("DChannelEditDialog", "Label Format", nullptr));
        autoScaleAxis->setText(QString());
        label_23->setText(QApplication::translate("DChannelEditDialog", "Major Ticks", nullptr));
        label_24->setText(QApplication::translate("DChannelEditDialog", "Minor Ticks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChannelEditDialog: public Ui_DChannelEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELEDITDIALOG_H
