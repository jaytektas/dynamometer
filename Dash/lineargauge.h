#ifndef LINEARGAUGE_H
#define LINEARGAUGE_H

#include "gauge.h"

using namespace std;

namespace Dynamometer
{
class DLinearGauge : public DGauge
{
    Q_OBJECT

    // dial
    Q_PROPERTY(int barWidth READ getBarWidth WRITE setBarWidth USER true)
    Q_PROPERTY(QColor dialColor READ getDialColor WRITE setDialColor USER true)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding USER true)
    Q_PROPERTY(bool dialEnabled READ getDialEnabled WRITE setDialEnabled USER true)

    // bezel
    Q_PROPERTY(int bezelWidth READ getBezelWidth WRITE setBezelWidth USER true)
    Q_PROPERTY(int bezelRadius READ getBezelRadius WRITE setBezelRadius USER true)
    Q_PROPERTY(QColor bezelColor0 READ getBezelColor0 WRITE setBezelColor0 USER true)
    Q_PROPERTY(QColor bezelColor1 READ getBezelColor1 WRITE setBezelColor1 USER true)
    Q_PROPERTY(bool bezelEnabled READ getBezelEnabled WRITE setBezelEnabled USER true)

    // major ticks
    Q_PROPERTY(int majorTickCount READ getMajorTickCount WRITE setMajorTickCount USER true)
    Q_PROPERTY(int majorTickOffset READ getMajorTickOffset WRITE setMajorTickOffset USER true)
    Q_PROPERTY(int majorTickWidth READ getMajorTickWidth WRITE setMajorTickWidth USER true)
    Q_PROPERTY(int majorTickLength READ getMajorTickLength WRITE setMajorTickLength USER true)
    Q_PROPERTY(QColor majorTickColor READ getMajorTickColor WRITE setMajorTickColor USER true)
    Q_PROPERTY(bool majorTicksEnabled READ getMajorTicksEnabled WRITE setMajorTicksEnabled USER true)

    // minor ticks
    Q_PROPERTY(int minorTickCount READ getMinorTickCount WRITE setMinorTickCount USER true)
    Q_PROPERTY(int minorTickOffset READ getMinorTickOffset WRITE setMinorTickOffset USER true)
    Q_PROPERTY(int minorTickWidth READ getMinorTickWidth WRITE setMinorTickWidth USER true)
    Q_PROPERTY(int minorTickLength READ getMinorTickLength WRITE setMinorTickLength USER true)
    Q_PROPERTY(QColor MinorTickColor READ getMinorTickColor WRITE setMinorTickColor USER true)
    Q_PROPERTY(bool minorTicksEnabled READ getMinorTicksEnabled WRITE setMinorTicksEnabled USER true)

    // scale
    Q_PROPERTY(QFont scaleFont READ getScaleFont WRITE setScaleFont USER true)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor USER true)
    Q_PROPERTY(int scaleDigits READ getScaleDigits WRITE setScaleDigits USER true)
    Q_PROPERTY(char scaleFiller READ getScaleFiller WRITE setScaleFiller USER true)
    Q_PROPERTY(int scalePrecision READ getScalePrecision WRITE setScalePrecision USER true)
    Q_PROPERTY(qreal scaleScale READ getScaleScale WRITE setScaleScale USER true)
    Q_PROPERTY(int scaleOffset READ getScaleOffset WRITE setScaleOffset USER true)
    Q_PROPERTY(bool scaleEnabled READ getScaleEnabled WRITE setScaleEnabled USER true)
public:
    explicit DLinearGauge(QWidget *parent = nullptr);
    ~DLinearGauge() override;

    virtual QByteArray type() const override { return "linear"; }

    void setBarWidth(int barWidth) { g_barWidth = barWidth; }
    int getBarWidth() const { return g_barWidth; }

    // dial
    void setDialColor(QColor dialColor) { g_dialColor = dialColor; }
    QColor getDialColor() const { return g_dialColor; }
    void setPadding(int padding) { g_padding = padding; }
    int getPadding() const { return g_padding; }
    void setDialEnabled(bool drawDialEnabled) { g_dialEnabled = drawDialEnabled; }
    bool getDialEnabled() const { return g_dialEnabled; }

    // bezel
    void setBezelWidth(int bezelWidth) { g_bezelWidth = bezelWidth; }
    int getBezelWidth() const { return g_bezelWidth; }
    void setBezelRadius(int bezelRadius) { g_bezelRadius = bezelRadius; }
    int getBezelRadius() const { return g_bezelRadius; }
    void setBezelColor0(QColor bezelColor0) { g_bezelColor0 = bezelColor0; }
    QColor getBezelColor0() const { return g_bezelColor0; }
    void setBezelColor1(QColor bezelColor1) { g_bezelColor1 = bezelColor1; }
    QColor getBezelColor1() const { return g_bezelColor1; }
    void setBezelEnabled(bool drawBezelEnabled) { g_bezelEnabled = drawBezelEnabled; }
    bool getBezelEnabled() const { return g_bezelEnabled; }

    // major ticks
    void setMajorTickCount(int majorTickCount) { g_majorTickCount = majorTickCount; }
    int getMajorTickCount() const { return g_majorTickCount; }
    void setMajorTickColor(QColor majorTickColor) { g_majorTickColor = majorTickColor; }
    QColor getMajorTickColor() const { return g_majorTickColor; }
    void setMajorTickOffset(int majorTickOffset) { g_majorTickOffset = majorTickOffset; }
    int getMajorTickOffset() const { return g_majorTickOffset; }
    void setMajorTickWidth(int majorTickWidth) { g_majorTickWidth = majorTickWidth; }
    int getMajorTickWidth() const { return g_majorTickWidth; }
    void setMajorTickLength(int majorTickLength) { g_majorTickLength = majorTickLength; }
    int getMajorTickLength() const { return g_majorTickLength; }
    void setMajorTicksEnabled(bool drawMajorTicksEnabled) { g_majorTicksEnabled = drawMajorTicksEnabled; }
    bool getMajorTicksEnabled() const { return g_majorTicksEnabled; }

    // minor ticks
    void setMinorTickCount(int minorTickCount) { g_minorTickCount = minorTickCount; }
    int getMinorTickCount() const { return g_minorTickCount; }
    void setMinorTickColor(QColor minorTickColor) { g_minorTickColor = minorTickColor; }
    QColor getMinorTickColor() const { return g_minorTickColor; }
    void setMinorTickOffset(int minorTickOffset) { g_minorTickOffset = minorTickOffset; }
    int getMinorTickOffset() const { return g_minorTickOffset; }
    void setMinorTickWidth(int minorTickWidth) { g_minorTickWidth = minorTickWidth; }
    int getMinorTickWidth() const { return g_minorTickWidth; }
    void setMinorTickLength(int minorTickLength) { g_minorTickLength = minorTickLength; }
    int getMinorTickLength() const { return g_minorTickLength; }
    void setMinorTicksEnabled(bool drawMinorTicksEnabled) { g_minorTicksEnabled = drawMinorTicksEnabled; }
    bool getMinorTicksEnabled() const { return g_minorTicksEnabled; }

    // scale
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
    void setScaleScale(qreal scaleScale) { g_scaleScale = scaleScale; }
    qreal getScaleScale() const { return g_scaleScale; }
    void setScaleOffset(int scaleOffset) { g_scaleOffset = scaleOffset; }
    int getScaleOffset() const { return g_scaleOffset; }
    bool getScaleEnabled() const { return g_scaleEnabled; }
    void setScaleEnabled(bool drawScaleEnabled) { g_scaleEnabled = drawScaleEnabled; }

    void setContextEnabled(bool contextEnabled) { g_contextEnabled = contextEnabled; }
    bool getContextEnabled() const { return g_contextEnabled; }

public slots:
    void refresh() override { drawBase(); update(); }

private slots:
    void contextMenuChannelSelected(QAction *action);
    void showContextMenu(const QPoint & point);
    void bringToFront();
    void sendToBack();
    void linearConfigure();

private:
    QPixmap g_baseDrawing = QPixmap(300, 1000);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void drawBezel(QPainter *painter);
    void drawBase();

    int g_tWidth;
    int g_tHeight;
    int g_xTranslate;
    int g_yTranslate;
    qreal g_xscale;
    qreal g_yscale;
    bool g_lockAspect = true;

    int g_padding = 100;

    QColor g_dialColor = QColor(Qt::black);
    bool g_dialEnabled = true;

    int g_bezelWidth = 30;
    int g_bezelRadius = 80;
    QColor g_bezelColor0 = QColor(Qt::darkGray);
    QColor g_bezelColor1 = QColor(Qt::black);
    bool g_bezelEnabled = true;

    int g_majorTickCount = 6;
    int g_majorTickWidth = 6;
    int g_majorTickLength = 20;
    int g_majorTickOffset = 20;
    QColor g_majorTickColor = QColor(Qt::white);
    bool g_majorTicksEnabled = true;

    int g_minorTickCount = 3;
    int g_minorTickWidth = 2;
    int g_minorTickLength = 10;
    int g_minorTickOffset = 20;
    QColor g_minorTickColor = QColor(Qt::white);
    bool g_minorTicksEnabled = true;

    QColor g_scaleColor = QColor(Qt::yellow);
    QFont g_scaleFont = QFont("ubuntu", 30);
    qreal g_scaleScale = 1;
    int g_scaleDigits = 0;
    int g_scalePrecision = 0;
    char g_scaleFiller = '0';
    int g_scaleOffset = 5;
    bool g_scaleEnabled = true;

    int g_barWidth = 40;

    bool g_contextEnabled = true;
};

}

#endif // LINEARGAUGE_H
