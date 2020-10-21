/********************************************************************************
** Form generated from reading UI file 'dialconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALCONFIGURATION_H
#define UI_DIALCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Dash/dialgauge.h"

QT_BEGIN_NAMESPACE

class Ui_DDialConfiguration
{
public:
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *scaleScaleLineEdit;
    QLineEdit *needleHatRadiusLineEdit;
    QCheckBox *drawMajorTicksEnabledCheckBox;
    QPushButton *lowerWarningColorButton;
    QLineEdit *bezelRadiusLineEdit;
    QLineEdit *majorTickWidthLineEdit;
    QLineEdit *scaleFillerLineEdit;
    QLineEdit *upperCriticalStartLineEdit;
    QLineEdit *scalePrecisionLineEdit;
    QLineEdit *upperWarningStartLineEdit;
    QLineEdit *lowerWarningRadiusLineEdit;
    QLineEdit *upperWarningWidthLineEdit;
    QCheckBox *drawUpperWarningEnabledCheckBox;
    QLineEdit *validStartLineEdit;
    QPushButton *titleFontButton;
    QPushButton *unitsColorButton;
    QLineEdit *majorTickCountLineEdit;
    QCheckBox *drawScaleEnabledCheckBox;
    QLineEdit *minorTicksRadiusLineEdit;
    QLineEdit *lowerCriticalWidthLineEdit;
    QLineEdit *upperWarningEndLineEdit;
    QCheckBox *drawDialEnabledCheckBox;
    QPushButton *clearImageButton;
    QPushButton *upperCriticalColorButton;
    QLineEdit *majorTickLengthLineEdit;
    QCheckBox *drawTitleEnabledCheckBox;
    QPushButton *lowerCriticalColorButton;
    QPushButton *scaleColorButton;
    QLineEdit *digitalScaleLineEdit;
    QLineEdit *upperCriticalWidthLineEdit;
    QPushButton *dialColorButton;
    QLineEdit *minorTickWidthLineEdit;
    QLineEdit *digitalDigitsLineEdit;
    QPushButton *bezelColor1Button;
    QLineEdit *lowerWarningStartLineEdit;
    QLineEdit *scaleRadiusLineEdit;
    QPushButton *digitalPositionButton;
    QLineEdit *validRadiusLineEdit;
    QLineEdit *needleLengthLineEdit;
    QLineEdit *digitalFillerLineEdit;
    QPushButton *needleHatColor0Button;
    QPushButton *scaleFontButton;
    QCheckBox *drawValidEnabledCheckBox;
    QCheckBox *drawBezelEnabledCheckBox;
    QPushButton *majorTickColorButton;
    QLineEdit *lowerCriticalEndLineEdit;
    QCheckBox *drawNeedeEnabledCheckBox;
    QPushButton *bezelColor0Button;
    QLineEdit *lowerCriticalRadiusLineEdit;
    QPushButton *digitalFontButton;
    QLineEdit *lowerCriticalStartLineEdit;
    QLineEdit *minorTickLengthLineEdit;
    QCheckBox *drawLowerWarningEnabledCheckBox;
    QCheckBox *drawDigitalEnabledCheckBox;
    QPushButton *needleHatColor1Button;
    QLineEdit *scaleDigitsLineEdit;
    QLineEdit *upperCriticalRadiusLineEdit;
    QLineEdit *bezelWidthLineEdit;
    QLineEdit *upperWarningRadiusLineEdit;
    QCheckBox *drawUpperCriticalEnabledCheckBox;
    QLineEdit *majorTicksRadiusLineEdit;
    QPushButton *validColorButton;
    QLineEdit *upperCriticalEndLineEdit;
    QLineEdit *titleLineEdit;
    QCheckBox *drawUnitsEnabledCheckBox;
    QCheckBox *drawNeedeHatEnabledCheckBox;
    QLineEdit *minorTickCountLineEdit;
    QLineEdit *unitsLineEdit;
    QPushButton *titlePositionButton;
    QLineEdit *validWidthLineEdit;
    QPushButton *titleColorButton;
    QCheckBox *drawLowerCriticalEnabledCheckBox;
    QLineEdit *lowerWarningEndLineEdit;
    QPushButton *upperWarningColorButton;
    QPushButton *digitalColorButton;
    QPushButton *needleColor1Button;
    QLineEdit *lowerWarningWidthLineEdit;
    QPushButton *dialImageButton;
    QLineEdit *validEndLineEdit;
    QCheckBox *drawMinorTicksEnabledCheckBox;
    QLineEdit *digitalPrecisionLineEdit;
    QPushButton *unitsPositionButton;
    QPushButton *minorTickColorButton;
    QPushButton *unitsFontButton;
    QLineEdit *needleWidthLineEdit;
    QPushButton *needleColor0Button;
    QLineEdit *dialRadiusLineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    Dynamometer::DDialGauge *dialGaugeWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *startAngleLineEdit;
    QLineEdit *maximumLineEdit;
    QLineEdit *endAngleLineEdit;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *minimumLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DDialConfiguration)
    {
        if (DDialConfiguration->objectName().isEmpty())
            DDialConfiguration->setObjectName(QString::fromUtf8("DDialConfiguration"));
        DDialConfiguration->resize(982, 755);
        verticalLayout_4 = new QVBoxLayout(DDialConfiguration);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(DDialConfiguration);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scaleScaleLineEdit = new QLineEdit(groupBox);
        scaleScaleLineEdit->setObjectName(QString::fromUtf8("scaleScaleLineEdit"));
        scaleScaleLineEdit->setMinimumSize(QSize(40, 0));
        scaleScaleLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleScaleLineEdit, 9, 5, 1, 1);

        needleHatRadiusLineEdit = new QLineEdit(groupBox);
        needleHatRadiusLineEdit->setObjectName(QString::fromUtf8("needleHatRadiusLineEdit"));
        needleHatRadiusLineEdit->setMinimumSize(QSize(40, 0));
        needleHatRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleHatRadiusLineEdit, 14, 1, 1, 1);

        drawMajorTicksEnabledCheckBox = new QCheckBox(groupBox);
        drawMajorTicksEnabledCheckBox->setObjectName(QString::fromUtf8("drawMajorTicksEnabledCheckBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(drawMajorTicksEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawMajorTicksEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawMajorTicksEnabledCheckBox, 2, 0, 1, 1);

        lowerWarningColorButton = new QPushButton(groupBox);
        lowerWarningColorButton->setObjectName(QString::fromUtf8("lowerWarningColorButton"));
        lowerWarningColorButton->setMinimumSize(QSize(40, 0));
        lowerWarningColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerWarningColorButton, 5, 5, 1, 1);

        bezelRadiusLineEdit = new QLineEdit(groupBox);
        bezelRadiusLineEdit->setObjectName(QString::fromUtf8("bezelRadiusLineEdit"));
        bezelRadiusLineEdit->setMinimumSize(QSize(40, 0));
        bezelRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(bezelRadiusLineEdit, 1, 1, 1, 1);

        majorTickWidthLineEdit = new QLineEdit(groupBox);
        majorTickWidthLineEdit->setObjectName(QString::fromUtf8("majorTickWidthLineEdit"));
        majorTickWidthLineEdit->setMinimumSize(QSize(40, 0));
        majorTickWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(majorTickWidthLineEdit, 2, 3, 1, 1);

        scaleFillerLineEdit = new QLineEdit(groupBox);
        scaleFillerLineEdit->setObjectName(QString::fromUtf8("scaleFillerLineEdit"));
        scaleFillerLineEdit->setMinimumSize(QSize(40, 0));
        scaleFillerLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleFillerLineEdit, 9, 3, 1, 1);

        upperCriticalStartLineEdit = new QLineEdit(groupBox);
        upperCriticalStartLineEdit->setObjectName(QString::fromUtf8("upperCriticalStartLineEdit"));
        upperCriticalStartLineEdit->setMinimumSize(QSize(40, 0));
        upperCriticalStartLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperCriticalStartLineEdit, 8, 3, 1, 1);

        scalePrecisionLineEdit = new QLineEdit(groupBox);
        scalePrecisionLineEdit->setObjectName(QString::fromUtf8("scalePrecisionLineEdit"));
        scalePrecisionLineEdit->setMinimumSize(QSize(40, 0));
        scalePrecisionLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scalePrecisionLineEdit, 9, 4, 1, 1);

        upperWarningStartLineEdit = new QLineEdit(groupBox);
        upperWarningStartLineEdit->setObjectName(QString::fromUtf8("upperWarningStartLineEdit"));
        upperWarningStartLineEdit->setMinimumSize(QSize(40, 0));
        upperWarningStartLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperWarningStartLineEdit, 7, 3, 1, 1);

        lowerWarningRadiusLineEdit = new QLineEdit(groupBox);
        lowerWarningRadiusLineEdit->setObjectName(QString::fromUtf8("lowerWarningRadiusLineEdit"));
        lowerWarningRadiusLineEdit->setMinimumSize(QSize(40, 0));
        lowerWarningRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerWarningRadiusLineEdit, 5, 1, 1, 1);

        upperWarningWidthLineEdit = new QLineEdit(groupBox);
        upperWarningWidthLineEdit->setObjectName(QString::fromUtf8("upperWarningWidthLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(upperWarningWidthLineEdit->sizePolicy().hasHeightForWidth());
        upperWarningWidthLineEdit->setSizePolicy(sizePolicy2);
        upperWarningWidthLineEdit->setMinimumSize(QSize(40, 0));
        upperWarningWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperWarningWidthLineEdit, 7, 2, 1, 1);

        drawUpperWarningEnabledCheckBox = new QCheckBox(groupBox);
        drawUpperWarningEnabledCheckBox->setObjectName(QString::fromUtf8("drawUpperWarningEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawUpperWarningEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawUpperWarningEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawUpperWarningEnabledCheckBox, 7, 0, 1, 1);

        validStartLineEdit = new QLineEdit(groupBox);
        validStartLineEdit->setObjectName(QString::fromUtf8("validStartLineEdit"));
        validStartLineEdit->setMinimumSize(QSize(40, 0));
        validStartLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(validStartLineEdit, 6, 3, 1, 1);

        titleFontButton = new QPushButton(groupBox);
        titleFontButton->setObjectName(QString::fromUtf8("titleFontButton"));
        titleFontButton->setMinimumSize(QSize(40, 0));
        titleFontButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(titleFontButton, 10, 6, 1, 1);

        unitsColorButton = new QPushButton(groupBox);
        unitsColorButton->setObjectName(QString::fromUtf8("unitsColorButton"));
        unitsColorButton->setMinimumSize(QSize(40, 0));
        unitsColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(unitsColorButton, 11, 3, 1, 1);

        majorTickCountLineEdit = new QLineEdit(groupBox);
        majorTickCountLineEdit->setObjectName(QString::fromUtf8("majorTickCountLineEdit"));
        sizePolicy2.setHeightForWidth(majorTickCountLineEdit->sizePolicy().hasHeightForWidth());
        majorTickCountLineEdit->setSizePolicy(sizePolicy2);
        majorTickCountLineEdit->setMinimumSize(QSize(40, 0));
        majorTickCountLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(majorTickCountLineEdit, 2, 2, 1, 1);

        drawScaleEnabledCheckBox = new QCheckBox(groupBox);
        drawScaleEnabledCheckBox->setObjectName(QString::fromUtf8("drawScaleEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawScaleEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawScaleEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawScaleEnabledCheckBox, 9, 0, 1, 1);

        minorTicksRadiusLineEdit = new QLineEdit(groupBox);
        minorTicksRadiusLineEdit->setObjectName(QString::fromUtf8("minorTicksRadiusLineEdit"));
        minorTicksRadiusLineEdit->setMinimumSize(QSize(40, 0));
        minorTicksRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(minorTicksRadiusLineEdit, 3, 1, 1, 1);

        lowerCriticalWidthLineEdit = new QLineEdit(groupBox);
        lowerCriticalWidthLineEdit->setObjectName(QString::fromUtf8("lowerCriticalWidthLineEdit"));
        sizePolicy2.setHeightForWidth(lowerCriticalWidthLineEdit->sizePolicy().hasHeightForWidth());
        lowerCriticalWidthLineEdit->setSizePolicy(sizePolicy2);
        lowerCriticalWidthLineEdit->setMinimumSize(QSize(40, 0));
        lowerCriticalWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerCriticalWidthLineEdit, 4, 2, 1, 1);

        upperWarningEndLineEdit = new QLineEdit(groupBox);
        upperWarningEndLineEdit->setObjectName(QString::fromUtf8("upperWarningEndLineEdit"));
        upperWarningEndLineEdit->setMinimumSize(QSize(40, 0));
        upperWarningEndLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperWarningEndLineEdit, 7, 4, 1, 1);

        drawDialEnabledCheckBox = new QCheckBox(groupBox);
        drawDialEnabledCheckBox->setObjectName(QString::fromUtf8("drawDialEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawDialEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawDialEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawDialEnabledCheckBox, 0, 0, 1, 1);

        clearImageButton = new QPushButton(groupBox);
        clearImageButton->setObjectName(QString::fromUtf8("clearImageButton"));

        gridLayout->addWidget(clearImageButton, 0, 4, 1, 1);

        upperCriticalColorButton = new QPushButton(groupBox);
        upperCriticalColorButton->setObjectName(QString::fromUtf8("upperCriticalColorButton"));
        upperCriticalColorButton->setMinimumSize(QSize(40, 0));
        upperCriticalColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperCriticalColorButton, 8, 5, 1, 1);

        majorTickLengthLineEdit = new QLineEdit(groupBox);
        majorTickLengthLineEdit->setObjectName(QString::fromUtf8("majorTickLengthLineEdit"));
        majorTickLengthLineEdit->setMinimumSize(QSize(40, 0));
        majorTickLengthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(majorTickLengthLineEdit, 2, 4, 1, 1);

        drawTitleEnabledCheckBox = new QCheckBox(groupBox);
        drawTitleEnabledCheckBox->setObjectName(QString::fromUtf8("drawTitleEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawTitleEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawTitleEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawTitleEnabledCheckBox, 10, 0, 1, 1);

        lowerCriticalColorButton = new QPushButton(groupBox);
        lowerCriticalColorButton->setObjectName(QString::fromUtf8("lowerCriticalColorButton"));
        lowerCriticalColorButton->setMinimumSize(QSize(40, 0));
        lowerCriticalColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerCriticalColorButton, 4, 5, 1, 1);

        scaleColorButton = new QPushButton(groupBox);
        scaleColorButton->setObjectName(QString::fromUtf8("scaleColorButton"));
        scaleColorButton->setMinimumSize(QSize(40, 0));
        scaleColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleColorButton, 9, 6, 1, 1);

        digitalScaleLineEdit = new QLineEdit(groupBox);
        digitalScaleLineEdit->setObjectName(QString::fromUtf8("digitalScaleLineEdit"));
        digitalScaleLineEdit->setMinimumSize(QSize(40, 0));
        digitalScaleLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalScaleLineEdit, 12, 4, 1, 1);

        upperCriticalWidthLineEdit = new QLineEdit(groupBox);
        upperCriticalWidthLineEdit->setObjectName(QString::fromUtf8("upperCriticalWidthLineEdit"));
        sizePolicy2.setHeightForWidth(upperCriticalWidthLineEdit->sizePolicy().hasHeightForWidth());
        upperCriticalWidthLineEdit->setSizePolicy(sizePolicy2);
        upperCriticalWidthLineEdit->setMinimumSize(QSize(40, 0));
        upperCriticalWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperCriticalWidthLineEdit, 8, 2, 1, 1);

        dialColorButton = new QPushButton(groupBox);
        dialColorButton->setObjectName(QString::fromUtf8("dialColorButton"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dialColorButton->sizePolicy().hasHeightForWidth());
        dialColorButton->setSizePolicy(sizePolicy3);
        dialColorButton->setMinimumSize(QSize(40, 0));
        dialColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(dialColorButton, 0, 2, 1, 1);

        minorTickWidthLineEdit = new QLineEdit(groupBox);
        minorTickWidthLineEdit->setObjectName(QString::fromUtf8("minorTickWidthLineEdit"));
        minorTickWidthLineEdit->setMinimumSize(QSize(40, 0));
        minorTickWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(minorTickWidthLineEdit, 3, 3, 1, 1);

        digitalDigitsLineEdit = new QLineEdit(groupBox);
        digitalDigitsLineEdit->setObjectName(QString::fromUtf8("digitalDigitsLineEdit"));
        digitalDigitsLineEdit->setMinimumSize(QSize(40, 0));
        digitalDigitsLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalDigitsLineEdit, 12, 1, 1, 1);

        bezelColor1Button = new QPushButton(groupBox);
        bezelColor1Button->setObjectName(QString::fromUtf8("bezelColor1Button"));
        bezelColor1Button->setMinimumSize(QSize(40, 0));
        bezelColor1Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(bezelColor1Button, 1, 4, 1, 1);

        lowerWarningStartLineEdit = new QLineEdit(groupBox);
        lowerWarningStartLineEdit->setObjectName(QString::fromUtf8("lowerWarningStartLineEdit"));
        lowerWarningStartLineEdit->setMinimumSize(QSize(40, 0));
        lowerWarningStartLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerWarningStartLineEdit, 5, 3, 1, 1);

        scaleRadiusLineEdit = new QLineEdit(groupBox);
        scaleRadiusLineEdit->setObjectName(QString::fromUtf8("scaleRadiusLineEdit"));
        scaleRadiusLineEdit->setMinimumSize(QSize(40, 0));
        scaleRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleRadiusLineEdit, 9, 1, 1, 1);

        digitalPositionButton = new QPushButton(groupBox);
        digitalPositionButton->setObjectName(QString::fromUtf8("digitalPositionButton"));
        digitalPositionButton->setMinimumSize(QSize(70, 0));
        digitalPositionButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalPositionButton, 12, 7, 1, 1);

        validRadiusLineEdit = new QLineEdit(groupBox);
        validRadiusLineEdit->setObjectName(QString::fromUtf8("validRadiusLineEdit"));
        validRadiusLineEdit->setMinimumSize(QSize(40, 0));
        validRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(validRadiusLineEdit, 6, 1, 1, 1);

        needleLengthLineEdit = new QLineEdit(groupBox);
        needleLengthLineEdit->setObjectName(QString::fromUtf8("needleLengthLineEdit"));
        needleLengthLineEdit->setMinimumSize(QSize(40, 0));
        needleLengthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleLengthLineEdit, 13, 1, 1, 1);

        digitalFillerLineEdit = new QLineEdit(groupBox);
        digitalFillerLineEdit->setObjectName(QString::fromUtf8("digitalFillerLineEdit"));
        sizePolicy2.setHeightForWidth(digitalFillerLineEdit->sizePolicy().hasHeightForWidth());
        digitalFillerLineEdit->setSizePolicy(sizePolicy2);
        digitalFillerLineEdit->setMinimumSize(QSize(40, 0));
        digitalFillerLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalFillerLineEdit, 12, 2, 1, 1);

        needleHatColor0Button = new QPushButton(groupBox);
        needleHatColor0Button->setObjectName(QString::fromUtf8("needleHatColor0Button"));
        sizePolicy3.setHeightForWidth(needleHatColor0Button->sizePolicy().hasHeightForWidth());
        needleHatColor0Button->setSizePolicy(sizePolicy3);
        needleHatColor0Button->setMinimumSize(QSize(40, 0));
        needleHatColor0Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleHatColor0Button, 14, 2, 1, 1);

        scaleFontButton = new QPushButton(groupBox);
        scaleFontButton->setObjectName(QString::fromUtf8("scaleFontButton"));
        scaleFontButton->setMinimumSize(QSize(40, 0));
        scaleFontButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleFontButton, 9, 7, 1, 1);

        drawValidEnabledCheckBox = new QCheckBox(groupBox);
        drawValidEnabledCheckBox->setObjectName(QString::fromUtf8("drawValidEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawValidEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawValidEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawValidEnabledCheckBox, 6, 0, 1, 1);

        drawBezelEnabledCheckBox = new QCheckBox(groupBox);
        drawBezelEnabledCheckBox->setObjectName(QString::fromUtf8("drawBezelEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawBezelEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawBezelEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawBezelEnabledCheckBox, 1, 0, 1, 1);

        majorTickColorButton = new QPushButton(groupBox);
        majorTickColorButton->setObjectName(QString::fromUtf8("majorTickColorButton"));
        majorTickColorButton->setMinimumSize(QSize(40, 0));
        majorTickColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(majorTickColorButton, 2, 5, 1, 1);

        lowerCriticalEndLineEdit = new QLineEdit(groupBox);
        lowerCriticalEndLineEdit->setObjectName(QString::fromUtf8("lowerCriticalEndLineEdit"));
        lowerCriticalEndLineEdit->setMinimumSize(QSize(40, 0));
        lowerCriticalEndLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerCriticalEndLineEdit, 4, 4, 1, 1);

        drawNeedeEnabledCheckBox = new QCheckBox(groupBox);
        drawNeedeEnabledCheckBox->setObjectName(QString::fromUtf8("drawNeedeEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawNeedeEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawNeedeEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawNeedeEnabledCheckBox, 13, 0, 1, 1);

        bezelColor0Button = new QPushButton(groupBox);
        bezelColor0Button->setObjectName(QString::fromUtf8("bezelColor0Button"));
        bezelColor0Button->setMinimumSize(QSize(40, 0));
        bezelColor0Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(bezelColor0Button, 1, 3, 1, 1);

        lowerCriticalRadiusLineEdit = new QLineEdit(groupBox);
        lowerCriticalRadiusLineEdit->setObjectName(QString::fromUtf8("lowerCriticalRadiusLineEdit"));
        lowerCriticalRadiusLineEdit->setMinimumSize(QSize(40, 0));
        lowerCriticalRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerCriticalRadiusLineEdit, 4, 1, 1, 1);

        digitalFontButton = new QPushButton(groupBox);
        digitalFontButton->setObjectName(QString::fromUtf8("digitalFontButton"));
        digitalFontButton->setMinimumSize(QSize(40, 0));
        digitalFontButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalFontButton, 12, 6, 1, 1);

        lowerCriticalStartLineEdit = new QLineEdit(groupBox);
        lowerCriticalStartLineEdit->setObjectName(QString::fromUtf8("lowerCriticalStartLineEdit"));
        lowerCriticalStartLineEdit->setMinimumSize(QSize(40, 0));
        lowerCriticalStartLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerCriticalStartLineEdit, 4, 3, 1, 1);

        minorTickLengthLineEdit = new QLineEdit(groupBox);
        minorTickLengthLineEdit->setObjectName(QString::fromUtf8("minorTickLengthLineEdit"));
        minorTickLengthLineEdit->setMinimumSize(QSize(40, 0));
        minorTickLengthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(minorTickLengthLineEdit, 3, 4, 1, 1);

        drawLowerWarningEnabledCheckBox = new QCheckBox(groupBox);
        drawLowerWarningEnabledCheckBox->setObjectName(QString::fromUtf8("drawLowerWarningEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawLowerWarningEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawLowerWarningEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawLowerWarningEnabledCheckBox, 5, 0, 1, 1);

        drawDigitalEnabledCheckBox = new QCheckBox(groupBox);
        drawDigitalEnabledCheckBox->setObjectName(QString::fromUtf8("drawDigitalEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawDigitalEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawDigitalEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawDigitalEnabledCheckBox, 12, 0, 1, 1);

        needleHatColor1Button = new QPushButton(groupBox);
        needleHatColor1Button->setObjectName(QString::fromUtf8("needleHatColor1Button"));
        needleHatColor1Button->setMinimumSize(QSize(40, 0));
        needleHatColor1Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleHatColor1Button, 14, 3, 1, 1);

        scaleDigitsLineEdit = new QLineEdit(groupBox);
        scaleDigitsLineEdit->setObjectName(QString::fromUtf8("scaleDigitsLineEdit"));
        sizePolicy2.setHeightForWidth(scaleDigitsLineEdit->sizePolicy().hasHeightForWidth());
        scaleDigitsLineEdit->setSizePolicy(sizePolicy2);
        scaleDigitsLineEdit->setMinimumSize(QSize(40, 0));
        scaleDigitsLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(scaleDigitsLineEdit, 9, 2, 1, 1);

        upperCriticalRadiusLineEdit = new QLineEdit(groupBox);
        upperCriticalRadiusLineEdit->setObjectName(QString::fromUtf8("upperCriticalRadiusLineEdit"));
        upperCriticalRadiusLineEdit->setMinimumSize(QSize(40, 0));
        upperCriticalRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperCriticalRadiusLineEdit, 8, 1, 1, 1);

        bezelWidthLineEdit = new QLineEdit(groupBox);
        bezelWidthLineEdit->setObjectName(QString::fromUtf8("bezelWidthLineEdit"));
        sizePolicy2.setHeightForWidth(bezelWidthLineEdit->sizePolicy().hasHeightForWidth());
        bezelWidthLineEdit->setSizePolicy(sizePolicy2);
        bezelWidthLineEdit->setMinimumSize(QSize(40, 0));
        bezelWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(bezelWidthLineEdit, 1, 2, 1, 1);

        upperWarningRadiusLineEdit = new QLineEdit(groupBox);
        upperWarningRadiusLineEdit->setObjectName(QString::fromUtf8("upperWarningRadiusLineEdit"));
        upperWarningRadiusLineEdit->setMinimumSize(QSize(40, 0));
        upperWarningRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperWarningRadiusLineEdit, 7, 1, 1, 1);

        drawUpperCriticalEnabledCheckBox = new QCheckBox(groupBox);
        drawUpperCriticalEnabledCheckBox->setObjectName(QString::fromUtf8("drawUpperCriticalEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawUpperCriticalEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawUpperCriticalEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawUpperCriticalEnabledCheckBox, 8, 0, 1, 1);

        majorTicksRadiusLineEdit = new QLineEdit(groupBox);
        majorTicksRadiusLineEdit->setObjectName(QString::fromUtf8("majorTicksRadiusLineEdit"));
        majorTicksRadiusLineEdit->setMinimumSize(QSize(40, 0));
        majorTicksRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(majorTicksRadiusLineEdit, 2, 1, 1, 1);

        validColorButton = new QPushButton(groupBox);
        validColorButton->setObjectName(QString::fromUtf8("validColorButton"));
        validColorButton->setMinimumSize(QSize(40, 0));
        validColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(validColorButton, 6, 5, 1, 1);

        upperCriticalEndLineEdit = new QLineEdit(groupBox);
        upperCriticalEndLineEdit->setObjectName(QString::fromUtf8("upperCriticalEndLineEdit"));
        upperCriticalEndLineEdit->setMinimumSize(QSize(40, 0));
        upperCriticalEndLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperCriticalEndLineEdit, 8, 4, 1, 1);

        titleLineEdit = new QLineEdit(groupBox);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));
        titleLineEdit->setMinimumSize(QSize(40, 0));
        titleLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(titleLineEdit, 10, 1, 1, 4);

        drawUnitsEnabledCheckBox = new QCheckBox(groupBox);
        drawUnitsEnabledCheckBox->setObjectName(QString::fromUtf8("drawUnitsEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawUnitsEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawUnitsEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawUnitsEnabledCheckBox, 11, 0, 1, 1);

        drawNeedeHatEnabledCheckBox = new QCheckBox(groupBox);
        drawNeedeHatEnabledCheckBox->setObjectName(QString::fromUtf8("drawNeedeHatEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawNeedeHatEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawNeedeHatEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawNeedeHatEnabledCheckBox, 14, 0, 1, 1);

        minorTickCountLineEdit = new QLineEdit(groupBox);
        minorTickCountLineEdit->setObjectName(QString::fromUtf8("minorTickCountLineEdit"));
        sizePolicy2.setHeightForWidth(minorTickCountLineEdit->sizePolicy().hasHeightForWidth());
        minorTickCountLineEdit->setSizePolicy(sizePolicy2);
        minorTickCountLineEdit->setMinimumSize(QSize(40, 0));
        minorTickCountLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(minorTickCountLineEdit, 3, 2, 1, 1);

        unitsLineEdit = new QLineEdit(groupBox);
        unitsLineEdit->setObjectName(QString::fromUtf8("unitsLineEdit"));
        unitsLineEdit->setMinimumSize(QSize(40, 0));
        unitsLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(unitsLineEdit, 11, 1, 1, 2);

        titlePositionButton = new QPushButton(groupBox);
        titlePositionButton->setObjectName(QString::fromUtf8("titlePositionButton"));
        titlePositionButton->setMinimumSize(QSize(70, 0));
        titlePositionButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(titlePositionButton, 10, 7, 1, 1);

        validWidthLineEdit = new QLineEdit(groupBox);
        validWidthLineEdit->setObjectName(QString::fromUtf8("validWidthLineEdit"));
        sizePolicy2.setHeightForWidth(validWidthLineEdit->sizePolicy().hasHeightForWidth());
        validWidthLineEdit->setSizePolicy(sizePolicy2);
        validWidthLineEdit->setMinimumSize(QSize(40, 0));
        validWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(validWidthLineEdit, 6, 2, 1, 1);

        titleColorButton = new QPushButton(groupBox);
        titleColorButton->setObjectName(QString::fromUtf8("titleColorButton"));
        titleColorButton->setMinimumSize(QSize(40, 0));
        titleColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(titleColorButton, 10, 5, 1, 1);

        drawLowerCriticalEnabledCheckBox = new QCheckBox(groupBox);
        drawLowerCriticalEnabledCheckBox->setObjectName(QString::fromUtf8("drawLowerCriticalEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawLowerCriticalEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawLowerCriticalEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawLowerCriticalEnabledCheckBox, 4, 0, 1, 1);

        lowerWarningEndLineEdit = new QLineEdit(groupBox);
        lowerWarningEndLineEdit->setObjectName(QString::fromUtf8("lowerWarningEndLineEdit"));
        lowerWarningEndLineEdit->setMinimumSize(QSize(40, 0));
        lowerWarningEndLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerWarningEndLineEdit, 5, 4, 1, 1);

        upperWarningColorButton = new QPushButton(groupBox);
        upperWarningColorButton->setObjectName(QString::fromUtf8("upperWarningColorButton"));
        upperWarningColorButton->setMinimumSize(QSize(40, 0));
        upperWarningColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(upperWarningColorButton, 7, 5, 1, 1);

        digitalColorButton = new QPushButton(groupBox);
        digitalColorButton->setObjectName(QString::fromUtf8("digitalColorButton"));
        digitalColorButton->setMinimumSize(QSize(40, 0));
        digitalColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalColorButton, 12, 5, 1, 1);

        needleColor1Button = new QPushButton(groupBox);
        needleColor1Button->setObjectName(QString::fromUtf8("needleColor1Button"));
        needleColor1Button->setMinimumSize(QSize(40, 0));
        needleColor1Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleColor1Button, 13, 4, 1, 1);

        lowerWarningWidthLineEdit = new QLineEdit(groupBox);
        lowerWarningWidthLineEdit->setObjectName(QString::fromUtf8("lowerWarningWidthLineEdit"));
        sizePolicy2.setHeightForWidth(lowerWarningWidthLineEdit->sizePolicy().hasHeightForWidth());
        lowerWarningWidthLineEdit->setSizePolicy(sizePolicy2);
        lowerWarningWidthLineEdit->setMinimumSize(QSize(40, 0));
        lowerWarningWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lowerWarningWidthLineEdit, 5, 2, 1, 1);

        dialImageButton = new QPushButton(groupBox);
        dialImageButton->setObjectName(QString::fromUtf8("dialImageButton"));
        dialImageButton->setMinimumSize(QSize(40, 0));
        dialImageButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(dialImageButton, 0, 3, 1, 1);

        validEndLineEdit = new QLineEdit(groupBox);
        validEndLineEdit->setObjectName(QString::fromUtf8("validEndLineEdit"));
        validEndLineEdit->setMinimumSize(QSize(40, 0));
        validEndLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(validEndLineEdit, 6, 4, 1, 1);

        drawMinorTicksEnabledCheckBox = new QCheckBox(groupBox);
        drawMinorTicksEnabledCheckBox->setObjectName(QString::fromUtf8("drawMinorTicksEnabledCheckBox"));
        sizePolicy1.setHeightForWidth(drawMinorTicksEnabledCheckBox->sizePolicy().hasHeightForWidth());
        drawMinorTicksEnabledCheckBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(drawMinorTicksEnabledCheckBox, 3, 0, 1, 1);

        digitalPrecisionLineEdit = new QLineEdit(groupBox);
        digitalPrecisionLineEdit->setObjectName(QString::fromUtf8("digitalPrecisionLineEdit"));
        digitalPrecisionLineEdit->setMinimumSize(QSize(40, 0));
        digitalPrecisionLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(digitalPrecisionLineEdit, 12, 3, 1, 1);

        unitsPositionButton = new QPushButton(groupBox);
        unitsPositionButton->setObjectName(QString::fromUtf8("unitsPositionButton"));
        unitsPositionButton->setMinimumSize(QSize(70, 0));
        unitsPositionButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(unitsPositionButton, 11, 5, 1, 1);

        minorTickColorButton = new QPushButton(groupBox);
        minorTickColorButton->setObjectName(QString::fromUtf8("minorTickColorButton"));
        minorTickColorButton->setMinimumSize(QSize(40, 0));
        minorTickColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(minorTickColorButton, 3, 5, 1, 1);

        unitsFontButton = new QPushButton(groupBox);
        unitsFontButton->setObjectName(QString::fromUtf8("unitsFontButton"));
        unitsFontButton->setMinimumSize(QSize(40, 0));
        unitsFontButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(unitsFontButton, 11, 4, 1, 1);

        needleWidthLineEdit = new QLineEdit(groupBox);
        needleWidthLineEdit->setObjectName(QString::fromUtf8("needleWidthLineEdit"));
        sizePolicy2.setHeightForWidth(needleWidthLineEdit->sizePolicy().hasHeightForWidth());
        needleWidthLineEdit->setSizePolicy(sizePolicy2);
        needleWidthLineEdit->setMinimumSize(QSize(40, 0));
        needleWidthLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleWidthLineEdit, 13, 2, 1, 1);

        needleColor0Button = new QPushButton(groupBox);
        needleColor0Button->setObjectName(QString::fromUtf8("needleColor0Button"));
        needleColor0Button->setMinimumSize(QSize(40, 0));
        needleColor0Button->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(needleColor0Button, 13, 3, 1, 1);

        dialRadiusLineEdit = new QLineEdit(groupBox);
        dialRadiusLineEdit->setObjectName(QString::fromUtf8("dialRadiusLineEdit"));
        dialRadiusLineEdit->setMinimumSize(QSize(40, 0));
        dialRadiusLineEdit->setMaximumSize(QSize(16777215, 16777215));
        dialRadiusLineEdit->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(dialRadiusLineEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        splitter->addWidget(groupBox);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        dialGaugeWidget = new Dynamometer::DDialGauge(groupBox_3);
        dialGaugeWidget->setObjectName(QString::fromUtf8("dialGaugeWidget"));
        dialGaugeWidget->setGeometry(QRect(60, 160, 271, 301));

        verticalLayout_3->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(400, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        startAngleLineEdit = new QLineEdit(groupBox_2);
        startAngleLineEdit->setObjectName(QString::fromUtf8("startAngleLineEdit"));
        startAngleLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(startAngleLineEdit, 2, 1, 1, 1);

        maximumLineEdit = new QLineEdit(groupBox_2);
        maximumLineEdit->setObjectName(QString::fromUtf8("maximumLineEdit"));
        maximumLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(maximumLineEdit, 1, 1, 1, 1);

        endAngleLineEdit = new QLineEdit(groupBox_2);
        endAngleLineEdit->setObjectName(QString::fromUtf8("endAngleLineEdit"));
        endAngleLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(endAngleLineEdit, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        minimumLineEdit = new QLineEdit(groupBox_2);
        minimumLineEdit->setObjectName(QString::fromUtf8("minimumLineEdit"));
        minimumLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(minimumLineEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        verticalLayout_3->setStretch(0, 1);
        splitter->addWidget(layoutWidget);

        verticalLayout_4->addWidget(splitter);

        buttonBox = new QDialogButtonBox(DDialConfiguration);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);

        QWidget::setTabOrder(drawDialEnabledCheckBox, drawBezelEnabledCheckBox);
        QWidget::setTabOrder(drawBezelEnabledCheckBox, drawMajorTicksEnabledCheckBox);
        QWidget::setTabOrder(drawMajorTicksEnabledCheckBox, drawMinorTicksEnabledCheckBox);
        QWidget::setTabOrder(drawMinorTicksEnabledCheckBox, drawLowerCriticalEnabledCheckBox);
        QWidget::setTabOrder(drawLowerCriticalEnabledCheckBox, drawLowerWarningEnabledCheckBox);
        QWidget::setTabOrder(drawLowerWarningEnabledCheckBox, drawValidEnabledCheckBox);
        QWidget::setTabOrder(drawValidEnabledCheckBox, drawUpperWarningEnabledCheckBox);
        QWidget::setTabOrder(drawUpperWarningEnabledCheckBox, drawUpperCriticalEnabledCheckBox);
        QWidget::setTabOrder(drawUpperCriticalEnabledCheckBox, drawScaleEnabledCheckBox);
        QWidget::setTabOrder(drawScaleEnabledCheckBox, drawTitleEnabledCheckBox);
        QWidget::setTabOrder(drawTitleEnabledCheckBox, drawUnitsEnabledCheckBox);
        QWidget::setTabOrder(drawUnitsEnabledCheckBox, drawDigitalEnabledCheckBox);
        QWidget::setTabOrder(drawDigitalEnabledCheckBox, drawNeedeEnabledCheckBox);
        QWidget::setTabOrder(drawNeedeEnabledCheckBox, drawNeedeHatEnabledCheckBox);
        QWidget::setTabOrder(drawNeedeHatEnabledCheckBox, dialRadiusLineEdit);
        QWidget::setTabOrder(dialRadiusLineEdit, dialColorButton);
        QWidget::setTabOrder(dialColorButton, dialImageButton);
        QWidget::setTabOrder(dialImageButton, clearImageButton);
        QWidget::setTabOrder(clearImageButton, bezelRadiusLineEdit);
        QWidget::setTabOrder(bezelRadiusLineEdit, bezelWidthLineEdit);
        QWidget::setTabOrder(bezelWidthLineEdit, bezelColor0Button);
        QWidget::setTabOrder(bezelColor0Button, bezelColor1Button);
        QWidget::setTabOrder(bezelColor1Button, majorTicksRadiusLineEdit);
        QWidget::setTabOrder(majorTicksRadiusLineEdit, majorTickCountLineEdit);
        QWidget::setTabOrder(majorTickCountLineEdit, majorTickWidthLineEdit);
        QWidget::setTabOrder(majorTickWidthLineEdit, majorTickLengthLineEdit);
        QWidget::setTabOrder(majorTickLengthLineEdit, majorTickColorButton);
        QWidget::setTabOrder(majorTickColorButton, minorTicksRadiusLineEdit);
        QWidget::setTabOrder(minorTicksRadiusLineEdit, minorTickCountLineEdit);
        QWidget::setTabOrder(minorTickCountLineEdit, minorTickWidthLineEdit);
        QWidget::setTabOrder(minorTickWidthLineEdit, minorTickLengthLineEdit);
        QWidget::setTabOrder(minorTickLengthLineEdit, minorTickColorButton);
        QWidget::setTabOrder(minorTickColorButton, lowerCriticalRadiusLineEdit);
        QWidget::setTabOrder(lowerCriticalRadiusLineEdit, lowerCriticalWidthLineEdit);
        QWidget::setTabOrder(lowerCriticalWidthLineEdit, lowerCriticalStartLineEdit);
        QWidget::setTabOrder(lowerCriticalStartLineEdit, lowerCriticalEndLineEdit);
        QWidget::setTabOrder(lowerCriticalEndLineEdit, lowerCriticalColorButton);
        QWidget::setTabOrder(lowerCriticalColorButton, lowerWarningRadiusLineEdit);
        QWidget::setTabOrder(lowerWarningRadiusLineEdit, lowerWarningWidthLineEdit);
        QWidget::setTabOrder(lowerWarningWidthLineEdit, lowerWarningStartLineEdit);
        QWidget::setTabOrder(lowerWarningStartLineEdit, lowerWarningEndLineEdit);
        QWidget::setTabOrder(lowerWarningEndLineEdit, lowerWarningColorButton);
        QWidget::setTabOrder(lowerWarningColorButton, validRadiusLineEdit);
        QWidget::setTabOrder(validRadiusLineEdit, validWidthLineEdit);
        QWidget::setTabOrder(validWidthLineEdit, validStartLineEdit);
        QWidget::setTabOrder(validStartLineEdit, validEndLineEdit);
        QWidget::setTabOrder(validEndLineEdit, validColorButton);
        QWidget::setTabOrder(validColorButton, upperWarningRadiusLineEdit);
        QWidget::setTabOrder(upperWarningRadiusLineEdit, upperWarningWidthLineEdit);
        QWidget::setTabOrder(upperWarningWidthLineEdit, upperWarningStartLineEdit);
        QWidget::setTabOrder(upperWarningStartLineEdit, upperWarningEndLineEdit);
        QWidget::setTabOrder(upperWarningEndLineEdit, upperWarningColorButton);
        QWidget::setTabOrder(upperWarningColorButton, upperCriticalRadiusLineEdit);
        QWidget::setTabOrder(upperCriticalRadiusLineEdit, upperCriticalWidthLineEdit);
        QWidget::setTabOrder(upperCriticalWidthLineEdit, upperCriticalStartLineEdit);
        QWidget::setTabOrder(upperCriticalStartLineEdit, upperCriticalEndLineEdit);
        QWidget::setTabOrder(upperCriticalEndLineEdit, upperCriticalColorButton);
        QWidget::setTabOrder(upperCriticalColorButton, scaleRadiusLineEdit);
        QWidget::setTabOrder(scaleRadiusLineEdit, scaleDigitsLineEdit);
        QWidget::setTabOrder(scaleDigitsLineEdit, scaleFillerLineEdit);
        QWidget::setTabOrder(scaleFillerLineEdit, scalePrecisionLineEdit);
        QWidget::setTabOrder(scalePrecisionLineEdit, scaleScaleLineEdit);
        QWidget::setTabOrder(scaleScaleLineEdit, scaleColorButton);
        QWidget::setTabOrder(scaleColorButton, scaleFontButton);
        QWidget::setTabOrder(scaleFontButton, titleLineEdit);
        QWidget::setTabOrder(titleLineEdit, titleColorButton);
        QWidget::setTabOrder(titleColorButton, titleFontButton);
        QWidget::setTabOrder(titleFontButton, titlePositionButton);
        QWidget::setTabOrder(titlePositionButton, unitsLineEdit);
        QWidget::setTabOrder(unitsLineEdit, unitsColorButton);
        QWidget::setTabOrder(unitsColorButton, unitsFontButton);
        QWidget::setTabOrder(unitsFontButton, unitsPositionButton);
        QWidget::setTabOrder(unitsPositionButton, digitalDigitsLineEdit);
        QWidget::setTabOrder(digitalDigitsLineEdit, digitalFillerLineEdit);
        QWidget::setTabOrder(digitalFillerLineEdit, digitalPrecisionLineEdit);
        QWidget::setTabOrder(digitalPrecisionLineEdit, digitalScaleLineEdit);
        QWidget::setTabOrder(digitalScaleLineEdit, digitalColorButton);
        QWidget::setTabOrder(digitalColorButton, digitalFontButton);
        QWidget::setTabOrder(digitalFontButton, digitalPositionButton);
        QWidget::setTabOrder(digitalPositionButton, needleLengthLineEdit);
        QWidget::setTabOrder(needleLengthLineEdit, needleWidthLineEdit);
        QWidget::setTabOrder(needleWidthLineEdit, needleColor0Button);
        QWidget::setTabOrder(needleColor0Button, needleColor1Button);
        QWidget::setTabOrder(needleColor1Button, needleHatRadiusLineEdit);
        QWidget::setTabOrder(needleHatRadiusLineEdit, needleHatColor0Button);
        QWidget::setTabOrder(needleHatColor0Button, needleHatColor1Button);
        QWidget::setTabOrder(needleHatColor1Button, minimumLineEdit);
        QWidget::setTabOrder(minimumLineEdit, maximumLineEdit);
        QWidget::setTabOrder(maximumLineEdit, startAngleLineEdit);
        QWidget::setTabOrder(startAngleLineEdit, endAngleLineEdit);

        retranslateUi(DDialConfiguration);
        QObject::connect(buttonBox, SIGNAL(accepted()), DDialConfiguration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DDialConfiguration, SLOT(reject()));

        QMetaObject::connectSlotsByName(DDialConfiguration);
    } // setupUi

    void retranslateUi(QDialog *DDialConfiguration)
    {
        DDialConfiguration->setWindowTitle(QApplication::translate("DDialConfiguration", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("DDialConfiguration", "Draw", nullptr));
#ifndef QT_NO_TOOLTIP
        scaleScaleLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        scaleScaleLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        needleHatRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        needleHatRadiusLineEdit->setText(QString());
        drawMajorTicksEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Major Ticks", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerWarningColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Lower warning color", nullptr));
#endif // QT_NO_TOOLTIP
        lowerWarningColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        bezelRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        bezelRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        majorTickWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        majorTickWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        scaleFillerLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Filler", nullptr));
#endif // QT_NO_TOOLTIP
        scaleFillerLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperCriticalStartLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Start", nullptr));
#endif // QT_NO_TOOLTIP
        upperCriticalStartLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        scalePrecisionLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Precision", nullptr));
#endif // QT_NO_TOOLTIP
        scalePrecisionLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperWarningStartLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Start", nullptr));
#endif // QT_NO_TOOLTIP
        upperWarningStartLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        lowerWarningRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        lowerWarningRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperWarningWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        upperWarningWidthLineEdit->setText(QString());
        drawUpperWarningEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Upper Warning", nullptr));
#ifndef QT_NO_TOOLTIP
        validStartLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Start", nullptr));
#endif // QT_NO_TOOLTIP
        validStartLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        titleFontButton->setToolTip(QApplication::translate("DDialConfiguration", "Title font", nullptr));
#endif // QT_NO_TOOLTIP
        titleFontButton->setText(QApplication::translate("DDialConfiguration", "Font", nullptr));
#ifndef QT_NO_TOOLTIP
        unitsColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Units color", nullptr));
#endif // QT_NO_TOOLTIP
        unitsColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        majorTickCountLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Count", nullptr));
#endif // QT_NO_TOOLTIP
        majorTickCountLineEdit->setText(QString());
        drawScaleEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#ifndef QT_NO_TOOLTIP
        minorTicksRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        minorTicksRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        lowerCriticalWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        lowerCriticalWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperWarningEndLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "End", nullptr));
#endif // QT_NO_TOOLTIP
        upperWarningEndLineEdit->setText(QString());
        drawDialEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Dial", nullptr));
        clearImageButton->setText(QApplication::translate("DDialConfiguration", "Clear Img", nullptr));
#ifndef QT_NO_TOOLTIP
        upperCriticalColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Upper critical color", nullptr));
#endif // QT_NO_TOOLTIP
        upperCriticalColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        majorTickLengthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Length", nullptr));
#endif // QT_NO_TOOLTIP
        majorTickLengthLineEdit->setText(QString());
        drawTitleEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Title", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerCriticalColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Lower critical color", nullptr));
#endif // QT_NO_TOOLTIP
        lowerCriticalColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        scaleColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Scale color", nullptr));
#endif // QT_NO_TOOLTIP
        scaleColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        digitalScaleLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        digitalScaleLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperCriticalWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        upperCriticalWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        dialColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Dial color", nullptr));
#endif // QT_NO_TOOLTIP
        dialColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        minorTickWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        minorTickWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        digitalDigitsLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Digits", nullptr));
#endif // QT_NO_TOOLTIP
        digitalDigitsLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        bezelColor1Button->setToolTip(QApplication::translate("DDialConfiguration", "Bezel color1", nullptr));
#endif // QT_NO_TOOLTIP
        bezelColor1Button->setText(QApplication::translate("DDialConfiguration", "Color1", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerWarningStartLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Start", nullptr));
#endif // QT_NO_TOOLTIP
        lowerWarningStartLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        scaleRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        scaleRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        digitalPositionButton->setToolTip(QApplication::translate("DDialConfiguration", "Digital position", nullptr));
#endif // QT_NO_TOOLTIP
        digitalPositionButton->setText(QApplication::translate("DDialConfiguration", "Position", nullptr));
#ifndef QT_NO_TOOLTIP
        validRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        validRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        needleLengthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Length", nullptr));
#endif // QT_NO_TOOLTIP
        needleLengthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        digitalFillerLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Filler", nullptr));
#endif // QT_NO_TOOLTIP
        digitalFillerLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        needleHatColor0Button->setToolTip(QApplication::translate("DDialConfiguration", "Needle hat color0", nullptr));
#endif // QT_NO_TOOLTIP
        needleHatColor0Button->setText(QApplication::translate("DDialConfiguration", "Color0", nullptr));
#ifndef QT_NO_TOOLTIP
        scaleFontButton->setToolTip(QApplication::translate("DDialConfiguration", "Scale font", nullptr));
#endif // QT_NO_TOOLTIP
        scaleFontButton->setText(QApplication::translate("DDialConfiguration", "Font", nullptr));
        drawValidEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Valid", nullptr));
        drawBezelEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Bezel", nullptr));
#ifndef QT_NO_TOOLTIP
        majorTickColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Major ticks color", nullptr));
#endif // QT_NO_TOOLTIP
        majorTickColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerCriticalEndLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "End", nullptr));
#endif // QT_NO_TOOLTIP
        lowerCriticalEndLineEdit->setText(QString());
        drawNeedeEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Needle", nullptr));
#ifndef QT_NO_TOOLTIP
        bezelColor0Button->setToolTip(QApplication::translate("DDialConfiguration", "Bezel color0", nullptr));
#endif // QT_NO_TOOLTIP
        bezelColor0Button->setText(QApplication::translate("DDialConfiguration", "Color0", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerCriticalRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        lowerCriticalRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        digitalFontButton->setToolTip(QApplication::translate("DDialConfiguration", "Digital font", nullptr));
#endif // QT_NO_TOOLTIP
        digitalFontButton->setText(QApplication::translate("DDialConfiguration", "Font", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerCriticalStartLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Start", nullptr));
#endif // QT_NO_TOOLTIP
        lowerCriticalStartLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        minorTickLengthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Length", nullptr));
#endif // QT_NO_TOOLTIP
        minorTickLengthLineEdit->setText(QString());
        drawLowerWarningEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Lower Warning", nullptr));
        drawDigitalEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Digital", nullptr));
#ifndef QT_NO_TOOLTIP
        needleHatColor1Button->setToolTip(QApplication::translate("DDialConfiguration", "Needle hat color1", nullptr));
#endif // QT_NO_TOOLTIP
        needleHatColor1Button->setText(QApplication::translate("DDialConfiguration", "Color1", nullptr));
#ifndef QT_NO_TOOLTIP
        scaleDigitsLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        scaleDigitsLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperCriticalRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        upperCriticalRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        bezelWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        bezelWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperWarningRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        upperWarningRadiusLineEdit->setText(QString());
        drawUpperCriticalEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Upper Critical", nullptr));
#ifndef QT_NO_TOOLTIP
        majorTicksRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        majorTicksRadiusLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        validColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Valid color", nullptr));
#endif // QT_NO_TOOLTIP
        validColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        upperCriticalEndLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "End", nullptr));
#endif // QT_NO_TOOLTIP
        upperCriticalEndLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        titleLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Title", nullptr));
#endif // QT_NO_TOOLTIP
        titleLineEdit->setText(QString());
        drawUnitsEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Units", nullptr));
        drawNeedeHatEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Needle Hat", nullptr));
#ifndef QT_NO_TOOLTIP
        minorTickCountLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Count", nullptr));
#endif // QT_NO_TOOLTIP
        minorTickCountLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        unitsLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Units", nullptr));
#endif // QT_NO_TOOLTIP
        unitsLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        titlePositionButton->setToolTip(QApplication::translate("DDialConfiguration", "Title position", nullptr));
#endif // QT_NO_TOOLTIP
        titlePositionButton->setText(QApplication::translate("DDialConfiguration", "Position", nullptr));
#ifndef QT_NO_TOOLTIP
        validWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        validWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        titleColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Title color", nullptr));
#endif // QT_NO_TOOLTIP
        titleColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
        drawLowerCriticalEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Lower Critical", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerWarningEndLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "End", nullptr));
#endif // QT_NO_TOOLTIP
        lowerWarningEndLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        upperWarningColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Upper warning color", nullptr));
#endif // QT_NO_TOOLTIP
        upperWarningColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        digitalColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Digital color", nullptr));
#endif // QT_NO_TOOLTIP
        digitalColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        needleColor1Button->setToolTip(QApplication::translate("DDialConfiguration", "Needle color1", nullptr));
#endif // QT_NO_TOOLTIP
        needleColor1Button->setText(QApplication::translate("DDialConfiguration", "Color1", nullptr));
#ifndef QT_NO_TOOLTIP
        lowerWarningWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        lowerWarningWidthLineEdit->setText(QString());
        dialImageButton->setText(QApplication::translate("DDialConfiguration", "Image...", nullptr));
#ifndef QT_NO_TOOLTIP
        validEndLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "End", nullptr));
#endif // QT_NO_TOOLTIP
        validEndLineEdit->setText(QString());
        drawMinorTicksEnabledCheckBox->setText(QApplication::translate("DDialConfiguration", "Minor Ticks", nullptr));
#ifndef QT_NO_TOOLTIP
        digitalPrecisionLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Precision", nullptr));
#endif // QT_NO_TOOLTIP
        digitalPrecisionLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        unitsPositionButton->setToolTip(QApplication::translate("DDialConfiguration", "Units position", nullptr));
#endif // QT_NO_TOOLTIP
        unitsPositionButton->setText(QApplication::translate("DDialConfiguration", "Position", nullptr));
#ifndef QT_NO_TOOLTIP
        minorTickColorButton->setToolTip(QApplication::translate("DDialConfiguration", "Minor ticks color", nullptr));
#endif // QT_NO_TOOLTIP
        minorTickColorButton->setText(QApplication::translate("DDialConfiguration", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        unitsFontButton->setToolTip(QApplication::translate("DDialConfiguration", "Units font", nullptr));
#endif // QT_NO_TOOLTIP
        unitsFontButton->setText(QApplication::translate("DDialConfiguration", "Font", nullptr));
#ifndef QT_NO_TOOLTIP
        needleWidthLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Width", nullptr));
#endif // QT_NO_TOOLTIP
        needleWidthLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        needleColor0Button->setToolTip(QApplication::translate("DDialConfiguration", "Needle color0", nullptr));
#endif // QT_NO_TOOLTIP
        needleColor0Button->setText(QApplication::translate("DDialConfiguration", "Color0", nullptr));
#ifndef QT_NO_TOOLTIP
        dialRadiusLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Radius", nullptr));
#endif // QT_NO_TOOLTIP
        dialRadiusLineEdit->setText(QString());
        groupBox_3->setTitle(QApplication::translate("DDialConfiguration", "Preview", nullptr));
        groupBox_2->setTitle(QApplication::translate("DDialConfiguration", "Range", nullptr));
#ifndef QT_NO_TOOLTIP
        startAngleLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        startAngleLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        maximumLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        maximumLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        endAngleLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        endAngleLineEdit->setText(QString());
        label_3->setText(QApplication::translate("DDialConfiguration", "Start Angle", nullptr));
        label->setText(QApplication::translate("DDialConfiguration", "Minimum", nullptr));
        label_4->setText(QApplication::translate("DDialConfiguration", "End Angle", nullptr));
#ifndef QT_NO_TOOLTIP
        minimumLineEdit->setToolTip(QApplication::translate("DDialConfiguration", "Scale", nullptr));
#endif // QT_NO_TOOLTIP
        minimumLineEdit->setText(QString());
        label_2->setText(QApplication::translate("DDialConfiguration", "Maximum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDialConfiguration: public Ui_DDialConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALCONFIGURATION_H
