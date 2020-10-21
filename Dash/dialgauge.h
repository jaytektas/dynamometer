#ifndef DIALGAUGE_H
#define DIALGAUGE_H

#include "gauge.h"

namespace Dynamometer
{
class DDialGauge : public DGauge
{
    Q_OBJECT

    // gauge
    Q_PROPERTY(qreal startAngle READ getStartAngle WRITE setStartAngle USER true)
    Q_PROPERTY(qreal endAngle READ getEndAngle WRITE setEndAngle USER true)

    // dial
    Q_PROPERTY(int dialRadius READ getDialRadius WRITE setDialRadius USER true)
    Q_PROPERTY(QColor dialColor READ getDialColor WRITE setDialColor USER true)
    Q_PROPERTY(QPixmap dialImage READ getDialImage WRITE setDialImage USER true)
    Q_PROPERTY(bool dialEnabled READ getDialEnabled WRITE setDialEnabled USER true)

    // bezel
    Q_PROPERTY(int bezelRadius READ getBezelRadius WRITE setBezelRadius USER true)
    Q_PROPERTY(int bezelWidth READ getBezelWidth WRITE setBezelWidth USER true)
    Q_PROPERTY(QColor bezelColor0 READ getBezelColor0 WRITE setBezelColor0 USER true)
    Q_PROPERTY(QColor bezelColor1 READ getBezelColor1 WRITE setBezelColor1 USER true)
    Q_PROPERTY(bool bezelEnabled READ getBezelEnabled WRITE setBezelEnabled USER true)

    // major ticks
    Q_PROPERTY(int majorTickCount READ getMajorTickCount WRITE setMajorTickCount USER true)
    Q_PROPERTY(int majorTickRadius READ getMajorTickRadius WRITE setMajorTickRadius USER true)
    Q_PROPERTY(int majorTickLength READ getMajorTickLength WRITE setMajorTickLength USER true)
    Q_PROPERTY(int majorTickWidth READ getMajorTickWidth WRITE setMajorTickWidth USER true)
    Q_PROPERTY(QColor majorTickColor READ getMajorTickColor WRITE setMajorTickColor USER true)
    Q_PROPERTY(bool majorTicksEnabled READ getMajorTicksEnabled WRITE setMajorTicksEnabled USER true)

    // minor ticks
    Q_PROPERTY(int minorTickCount READ getMinorTickCount WRITE setMinorTickCount USER true)
    Q_PROPERTY(int minorTickRadius READ getMinorTickRadius WRITE setMinorTickRadius USER true)
    Q_PROPERTY(int minorTickLength READ getMinorTickLength WRITE setMinorTickLength USER true)
    Q_PROPERTY(int minorTickWidth READ getMinorTickWidth WRITE setMinorTickWidth USER true)
    Q_PROPERTY(QColor minorTickColor READ getMinorTickColor WRITE setMinorTickColor USER true)
    Q_PROPERTY(bool minorTicksEnabled READ getMinorTicksEnabled WRITE setMinorTicksEnabled USER true)

    // title
    Q_PROPERTY(QString title READ getTitle WRITE setTitle USER true)
    Q_PROPERTY(QRectF titlePosition READ getTitlePosition WRITE setTitlePosition USER true)
    Q_PROPERTY(QFont titleFont READ getTitleFont WRITE setTitleFont USER true)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor USER true)
    Q_PROPERTY(bool titleEnabled READ getTitleEnabled WRITE setTitleEnabled USER true)

    // units
    Q_PROPERTY(QString units READ getUnits WRITE setUnits USER true)
    Q_PROPERTY(QRectF unitsPosition READ getUnitsPosition WRITE setUnitsPosition USER true)
    Q_PROPERTY(QFont unitsFont READ getUnitsFont WRITE setUnitsFont USER true)
    Q_PROPERTY(QColor unitsColor READ getUnitsColor WRITE setUnitsColor USER true)
    Q_PROPERTY(bool unitsEnabled READ getUnitsEnabled WRITE setUnitsEnabled USER true)

    // scale
    Q_PROPERTY(int scaleRadius READ getScaleRadius WRITE setScaleRadius USER true)
    Q_PROPERTY(QFont scaleFont READ getScaleFont WRITE setScaleFont USER true)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor USER true)
    Q_PROPERTY(int scaleDigits READ getScaleDigits WRITE setScaleDigits USER true)
    Q_PROPERTY(char scaleFiller READ getScaleFiller WRITE setScaleFiller USER true)
    Q_PROPERTY(int scalePrecision READ getScalePrecision WRITE setScalePrecision USER true)
    Q_PROPERTY(qreal scaleScale READ getScaleScale WRITE setScaleScale USER true)
    Q_PROPERTY(bool scaleEnabled READ getScaleEnabled WRITE setScaleEnabled USER true)

    // digital
    Q_PROPERTY(QRectF digitalPosition READ getDigitalPosition WRITE setDigitalPosition USER true)
    Q_PROPERTY(QFont digitalFont READ getDigitalFont WRITE setDigitalFont USER true)
    Q_PROPERTY(QColor digitalColor READ getDigitalColor WRITE setDigitalColor USER true)
    Q_PROPERTY(int digitalDigits READ getDigitalDigits WRITE setDigitalDigits USER true)
    Q_PROPERTY(char digitalFiller READ getDigitalFiller WRITE setDigitalFiller USER true)
    Q_PROPERTY(int digitalPrecision READ getDigitalPrecision WRITE setDigitalPrecision USER true)
    Q_PROPERTY(qreal digitalScale READ getDigitalScale WRITE setDigitalScale USER true)
    Q_PROPERTY(bool digitalEnabled READ getDigitalEnabled WRITE setDigitalEnabled USER true)

    // needle
    Q_PROPERTY(QColor needleColor0 READ getNeedleColor0 WRITE setNeedleColor0 USER true)
    Q_PROPERTY(QColor needleColor1 READ getNeedleColor1 WRITE setNeedleColor1 USER true)
    Q_PROPERTY(int needleLength READ getNeedleLength WRITE setNeedleLength USER true)
    Q_PROPERTY(int needleWidth READ getNeedleWidth WRITE setNeedleWidth USER true)
    Q_PROPERTY(bool needleEnabled READ getNeedleEnabled WRITE setNeedleEnabled USER true)

    // needle hat
    Q_PROPERTY(int needleHatRadius READ getNeedleHatRadius WRITE setNeedleHatRadius USER true)
    Q_PROPERTY(QColor needleHatColor0 READ getNeedleHatColor0 WRITE setNeedleHatColor0 USER true)
    Q_PROPERTY(QColor needleHatColor1 READ getNeedleHatColor1 WRITE setNeedleHatColor1 USER true)
    Q_PROPERTY(bool needleHatEnabled READ getNeedleHatEnabled WRITE setNeedleHatEnabled USER true)

    // lower critical
    Q_PROPERTY(int lowerCriticalRadius READ getLowerCriticalRadius WRITE setLowerCriticalRadius USER true)
    Q_PROPERTY(int lowerCriticalWidth READ getLowerCriticalWidth WRITE setLowerCriticalWidth USER true)

    // lower warning
    Q_PROPERTY(int lowerWarningRadius READ getLowerWarningRadius WRITE setLowerWarningRadius USER true)
    Q_PROPERTY(int lowerWarninglWidth READ getLowerWarningWidth WRITE setLowerWarningWidth USER true)

    // valid
    Q_PROPERTY(int validRadius READ getValidRadius WRITE setValidRadius USER true)
    Q_PROPERTY(int validWidth READ getValidWidth WRITE setValidWidth USER true)

    // upper warning
    Q_PROPERTY(int upperWarningRadius READ getUpperWarningRadius WRITE setUpperWarningRadius USER true)
    Q_PROPERTY(int upperWarninglWidth READ getUpperWarningWidth WRITE setUpperWarningWidth USER true)

    // upper critical
    Q_PROPERTY(int upperCriticalRadius READ getUpperCriticalRadius WRITE setUpperCriticalRadius USER true)
    Q_PROPERTY(int upperCriticalWidth READ getUpperCriticalWidth WRITE setUpperCriticalWidth USER true)

public:
    explicit DDialGauge(QWidget *parent = nullptr);
    virtual ~DDialGauge() override ;

    virtual QByteArray type() const override { return "dial"; }

    void setStartAngle(qreal startAngle) { g_startAngle = startAngle; }
    qreal getStartAngle() const { return g_startAngle; }
    void setEndAngle(qreal endAngle) { g_endAngle = endAngle; }
    qreal getEndAngle() const { return g_endAngle; }

    // dial
    void setDialRadius(int dialRadius) { g_dialRadius = dialRadius; }
    int getDialRadius() const { return g_dialRadius; }
    void setDialColor(QColor dialColor) { g_dialColor = dialColor; }
    QColor getDialColor() const { return g_dialColor; }
    void setDialImage(QPixmap dialImage) { g_dialImage = dialImage; }
    QPixmap getDialImage() const { return g_dialImage; }
    void setDialEnabled(bool drawDialEnabled) { g_drawDialEnabled = drawDialEnabled; }
    bool getDialEnabled() const { return g_drawDialEnabled; }

    // bezel
    void setBezelRadius(int bezelRadius) { g_bezelRadius = bezelRadius; }
    int getBezelRadius() const { return g_bezelRadius; }
    void setBezelWidth(int bezelWidth) { g_bezelWidth = bezelWidth; }
    int getBezelWidth() const { return g_bezelWidth; }
    void setBezelColor0(QColor bezelColor0) { g_bezelColor0 = bezelColor0; }
    QColor getBezelColor0() const { return g_bezelColor0; }
    void setBezelColor1(QColor bezelColor1) { g_bezelColor1 = bezelColor1; }
    QColor getBezelColor1() const { return g_bezelColor1; }
    void setBezelEnabled(bool drawBezelEnabled) { g_drawBezelEnabled = drawBezelEnabled; }
    bool getBezelEnabled() const { return g_drawBezelEnabled; }

    // major ticks
    void setMajorTickCount(int majorTickCount) { g_majorTickCount = majorTickCount; }
    int getMajorTickCount() const { return g_majorTickCount; }
    void setMajorTickRadius(int majorTickRadius) { g_majorTickRadius = majorTickRadius; }
    int getMajorTickRadius() const { return g_majorTickRadius; }
    void setMajorTickLength(int majorTickLength) { g_majorTickLength = majorTickLength; }
    int getMajorTickLength() const { return g_majorTickLength; }
    void setMajorTickWidth(int majorTickWidth) { g_majorTickWidth = majorTickWidth; }
    int getMajorTickWidth() const { return g_majorTickWidth; }
    void setMajorTickColor(QColor majorTickColor) { g_majorTickColor = majorTickColor; }
    QColor getMajorTickColor() const { return g_majorTickColor; }
    void setMajorTicksEnabled(bool drawMajorTicksEnabled) { g_drawMajorTicksEnabled = drawMajorTicksEnabled; }
    bool getMajorTicksEnabled() const { return g_drawMajorTicksEnabled; }

    // minor ticks
    void setMinorTickCount(int minorTickCount) { g_minorTickCount = minorTickCount; }
    int getMinorTickCount() const { return g_minorTickCount; }
    void setMinorTickRadius(int minorTickRadius) { g_minorTickRadius = minorTickRadius; }
    int getMinorTickRadius() const { return g_minorTickRadius; }
    void setMinorTickLength(int minorTickLength) { g_minorTickLength = minorTickLength; }
    int getMinorTickLength() const { return g_minorTickLength; }
    void setMinorTickWidth(int minorTickWidth) { g_minorTickWidth = minorTickWidth; }
    int getMinorTickWidth() const { return g_minorTickWidth; }
    void setMinorTickColor(QColor minorTickColor) { g_minorTickColor = minorTickColor; }
    QColor getMinorTickColor() const { return g_minorTickColor; }
    void setMinorTicksEnabled(bool drawMinorTicksEnabled) { g_drawMinorTicksEnabled = drawMinorTicksEnabled; }
    bool getMinorTicksEnabled() const { return g_drawMinorTicksEnabled; }

    // title
    void setTitle(QString title) { g_title = title; }
    QString getTitle() const { return g_title; }
    void setTitlePosition(QRectF titlePosition) { g_titlePosition = titlePosition; }
    QRectF getTitlePosition() const { return g_titlePosition; }
    void setTitleFont(QFont titleFont) { g_titleFont = titleFont; }
    QFont getTitleFont() const { return g_titleFont; }
    void setTitleColor(QColor titleColor) { g_titleColor = titleColor; }
    QColor getTitleColor() const { return g_titleColor; }
    void setTitleEnabled(bool drawTitleEnabled) { g_drawTitleEnabled = drawTitleEnabled; }
    bool getTitleEnabled() const { return g_drawTitleEnabled; }

    // units
    void setUnits(QString units) { g_units = units; }
    QString getUnits() const { return g_units; }
    void setUnitsPosition(QRectF position) { g_unitsPosition = position; }
    QRectF getUnitsPosition() const { return g_unitsPosition; }
    void setUnitsFont(QFont unitsFont) { g_unitsFont = unitsFont; }
    QFont getUnitsFont() const { return g_unitsFont; }
    void setUnitsColor(QColor unitsColor) { g_unitsColor = unitsColor; }
    QColor getUnitsColor() const { return g_unitsColor; }
    void setUnitsEnabled(bool drawUnitsEnabled) { g_drawUnitsEnabled = drawUnitsEnabled; }
    bool getUnitsEnabled() const { return g_drawUnitsEnabled; }

    // scale
    void setScaleRadius(int scaleRadius) { g_scaleRadius = scaleRadius; }
    int getScaleRadius() const { return g_scaleRadius; }
    void setScaleFont(QFont scaleFont) { g_scaleFont = scaleFont; }
    QFont getScaleFont() const { return g_scaleFont; }
    void setScaleColor(QColor scaleColor) { g_scaleColor = scaleColor; }
    QColor getScaleColor() const { return g_scaleColor; }
    void setScaleDigits(int scaleDigits) { g_scaleDigits = scaleDigits; }
    int getScaleDigits() const { return g_scaleDigits; }
    void setScaleFiller(char scaleFiller) { g_scaleFiller = scaleFiller; }
    char getScaleFiller() const { return g_scaleFiller; }
    void setScalePrecision(int scalePrecision) { g_scalePrecision = scalePrecision; }
    int getScalePrecision() const { return g_scalePrecision; }
    void setScaleScale(qreal scale) { g_scaleScale = scale; }
    qreal getScaleScale() const { return g_scaleScale; }
    void setScaleEnabled(bool drawScaleEnabled) { g_drawScaleEnabled = drawScaleEnabled; }
    bool getScaleEnabled() const { return g_drawScaleEnabled; }

    // digital inset
    void setDigitalPosition(QRectF digitalPosition) { g_digitalPosition = digitalPosition; }
    QRectF getDigitalPosition() const { return g_digitalPosition; }
    void setDigitalFont(QFont digitalFont) { g_digitalFont = digitalFont; }
    QFont getDigitalFont() const { return g_digitalFont; }
    void setDigitalColor(QColor digitalColor) { g_digitalColor = digitalColor; }
    QColor getDigitalColor() const { return g_digitalColor; }
    void setDigitalDigits(int digitalDigits) { g_digitalDigits = digitalDigits; }
    int getDigitalDigits() const { return g_digitalDigits; }
    void setDigitalFiller(char digitalFiller) { g_digitalFiller = digitalFiller; }
    char getDigitalFiller() const { return g_digitalFiller; }
    void setDigitalPrecision(int digitalPrecision) { g_digitalPrecsion = digitalPrecision; }
    int getDigitalPrecision() const { return g_digitalPrecsion; }
    void setDigitalScale(qreal digitalScale) { g_digitalScale = digitalScale; }
    qreal getDigitalScale() const { return g_digitalScale; }
    void setDigitalEnabled(bool drawDigitalEnabled) { g_drawDigitalEnabled = drawDigitalEnabled; }
    bool getDigitalEnabled() const { return g_drawDigitalEnabled; }

    // needle
    void setNeedleColor0(QColor needleColor0) { g_needleColor0 = needleColor0; update(); }
    QColor getNeedleColor0() const { return g_needleColor0; }
    void setNeedleColor1(QColor needleColor1) { g_needleColor1 = needleColor1; update(); }
    QColor getNeedleColor1() const { return g_needleColor1; }
    void setNeedleLength(int needleLength) { g_needleLength = needleLength; update(); }
    int getNeedleLength() const { return g_needleLength; }
    void setNeedleWidth(int needleWidth) { g_needleWidth = needleWidth; update(); }
    int getNeedleWidth() const { return g_needleWidth; }
    void setNeedleEnabled(bool drawNeedleEnabled) { g_drawNeedleEnabled = drawNeedleEnabled; update(); }
    bool getNeedleEnabled() const { return g_drawNeedleEnabled; }

    // needle hat
    void setNeedleHatRadius(int needleHatRadius) { g_needleHatRadius = needleHatRadius; update(); }
    int getNeedleHatRadius() const { return g_needleHatRadius; }
    void setNeedleHatColor0(QColor needleHatColor0) { g_needleHatColor0 = needleHatColor0; update(); }
    QColor getNeedleHatColor0() const { return g_needleHatColor0; }
    void setNeedleHatColor1(QColor needleHatColor1) { g_needleHatColor1 = needleHatColor1; update(); }
    QColor getNeedleHatColor1() const { return g_needleHatColor1; }
    void setNeedleHatEnabled(bool drawNeedleHatEnabled) { g_drawNeedleHatEnabled = drawNeedleHatEnabled; update(); }
    bool getNeedleHatEnabled() const { return g_drawNeedleHatEnabled; }

    // lower critical
    void setLowerCriticalRadius(int lowerCriticalRadius) { g_lowerCriticalRadius = lowerCriticalRadius; }
    int getLowerCriticalRadius() const { return g_lowerCriticalRadius; }
    void setLowerCriticalWidth(int lowerCriticalWidth) { g_lowerCriticalWidth = lowerCriticalWidth; }
    int getLowerCriticalWidth() const { return g_lowerCriticalWidth; }

    // lower warning
    void setLowerWarningRadius(int lowerWarningRadius) { g_lowerWarningRadius = lowerWarningRadius; }
    int getLowerWarningRadius() const { return g_lowerWarningRadius;}
    void setLowerWarningWidth(int lowerWarningWidth) { g_lowerWarningWidth = lowerWarningWidth; }
    int getLowerWarningWidth() const { return g_lowerWarningWidth; }

    // valid
    void setValidRadius(int ValidRadius) { g_validRadius = ValidRadius; }
    int getValidRadius() const { return g_validRadius; }
    void setValidWidth(int ValidWidth) { g_validWidth = ValidWidth; }
    int getValidWidth() const { return g_validWidth; }

    // upper warning
    void setUpperWarningRadius(int upperWarningRadius) { g_upperWarningRadius = upperWarningRadius; }
    int getUpperWarningRadius() const { return g_upperWarningRadius; }
    void setUpperWarningWidth(int upperWarningWidth) { g_upperWarningWidth = upperWarningWidth; }
    int getUpperWarningWidth() const { return g_upperWarningWidth; }

    //  upper critical
    void setUpperCriticalRadius(int upperCriticalRadius) { g_upperCriticalRadius = upperCriticalRadius; }
    int getUpperCriticalRadius() const { return g_upperCriticalRadius; }
    void setUpperCriticalWidth(int upperCriticalWidth) { g_upperCriticalWidth = upperCriticalWidth; }
    int getUpperCriticalWidth() const { return g_upperCriticalWidth; }

    void setContextEnabled(bool contextEnabled) { g_contextEnabled = contextEnabled; }
    bool getContextEnabled() const { return g_contextEnabled; }

signals:
    void error(int);
    void lowerCritical();
    void lowerWarning();
    void valid();
    void upperWarning();
    void upperCritical();

public slots:
    void refresh() override { drawBase(); update(); }

private slots:
    void showContextMenu(const QPoint & point);
    void dialConfigure();
    void contextMenuChannelSelected(QAction *action);
    void bringToFront();
    void sendToBack();

protected:
    void drawBase();
    void paintEvent(QPaintEvent *event) override;
    // drawn into cached image
    void drawBezel(QPainter *);
    void drawArcWindow(QPainter *painter, QColor color, qreal startValue, qreal endValue, int radius, int width);
    void drawTicks(QPainter *painter, QColor color, qreal startAngle, qreal endAngle, int width, int length, int radius, int count);
    void drawScale(QPainter *painter);
    void drawUnits(QPainter *painter, QColor color);
    void drawLabel(QPainter *painter, QColor color);

    // drawn in the paint event on top of the cached image to 'update'
    void drawDigital(QPainter *painter);
    void drawNeedle(QPainter *painter);
    void drawNeedleHat(QPainter *painter);

    void drawText(QPainter *painter, QString text, QRectF position, QFont font, QColor color);
//    void thresholdManager();
    void resizeEvent(QResizeEvent *event) override;

    QPropertyAnimation g_sweepAnimation;
    QPixmap g_baseDrawing = QPixmap(1000, 1000);
    QPixmap g_dial;

    int g_tWidth;
    int g_tHeight;
    int g_xTranslate;
    int g_yTranslate;
    qreal g_xscale;
    qreal g_yscale;
    bool g_lockAspect = true;

    qreal g_startAngle = 240;
    qreal g_endAngle = 0;

    qreal g_lastValue = 0;

    int g_majorTickCount = 11;
    int g_minorTickCount = 3;

    // dial
    int g_dialRadius = 500;
    QColor g_dialColor = QColor(Qt::black);
    QPixmap g_dialImage; // = QPixmap(":/dials/black.png");
    bool g_drawDialEnabled = true;

    // bezel
    int g_bezelRadius = 485;
    int g_bezelWidth = 30;
    QColor g_bezelColor0 = QColor(Qt::darkGray);
    QColor g_bezelColor1 = QColor(Qt::black);
    bool g_drawBezelEnabled = true;

    // lower critical
    int g_lowerCriticalRadius = 300;
    int g_lowerCriticalWidth = 12;

    // lower warning
    int g_lowerWarningRadius = 300;
    int g_lowerWarningWidth = 12;

    // valid
    int g_validRadius = 300;
    int g_validWidth = 12;

    // upper warning
    int g_upperWarningRadius = 300;
    int g_upperWarningWidth = 12;

    // upper critical
    int g_upperCriticalRadius = 300;
    int g_upperCriticalWidth = 12;

    // major ticks
    int g_majorTickRadius = 470;
    int g_majorTickLength = 30;
    int g_majorTickWidth = 16;
    QColor g_majorTickColor = QColor(Qt::blue);
    bool g_drawMajorTicksEnabled = true;

    // minor ticks
    int g_minorTickRadius = 470;
    int g_minorTickLength = 10;
    int g_minorTickWidth = 8;
    QColor g_minorTickColor = QColor(Qt::magenta);
    bool g_drawMinorTicksEnabled = true;

    // scale
    int g_scaleRadius = 400;
    QColor g_scaleColor = QColor(Qt::green);
    QFont g_scaleFont = QFont("ubuntu", 40);
    int g_scaleDigits = 0;
    char g_scaleFiller = '0';
    int g_scalePrecision = 0;
    qreal g_scaleScale = 1;
    bool g_drawScaleEnabled = true;

    // title
    QString g_title = "Title";
    QColor g_titleColor = QColor(Qt::white);
    QRectF g_titlePosition = QRectF(-200, -250, 400, 100);
    QFont g_titleFont = QFont("ubuntu", 60);
    bool g_drawTitleEnabled = true;

    // units
    QString g_units = "Units";
    QColor g_unitsColor = QColor(Qt::white);
    QRectF g_unitsPosition = QRectF(-200, 180, 400, 100);
    QFont g_unitsFont = QFont("arial", 60);
    bool g_drawUnitsEnabled = true;

    // digital inset
    QRectF g_digitalPosition = QRectF(-200, 250, 400, 80);
    QColor g_digitalColor = QColor(Qt::cyan);
    QFont g_digitalFont = QFont("ubuntu", 60);
    int g_digitalDigits = 4;
    char g_digitalFiller = '0';
    int g_digitalPrecsion = 0;
    qreal g_digitalScale = 1;
    bool g_drawDigitalEnabled = true;

    // needle
    QColor g_needleColor0 = Qt::blue;
    QColor g_needleColor1 = Qt::green;
    int g_needleLength = 450;
    int g_needleWidth = 16;
    bool g_drawNeedleEnabled = true;

    // needle hat
    int g_needleHatRadius = 40;
    QColor g_needleHatColor0 = Qt::black;
    QColor g_needleHatColor1 = Qt::lightGray;
    bool g_drawNeedleHatEnabled = true;

    bool g_contextEnabled = true;
};
}

#endif // DIALGAUGE_H
