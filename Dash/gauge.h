#ifndef GAUGE_H
#define GAUGE_H

#include "widgetcontainer.h"

#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QtGui>
#include <QVBoxLayout>
#include <QMenu>

using namespace std;

namespace Dynamometer
{
class DGauge : public DWidgetContainer
{
    Q_OBJECT
    Q_PROPERTY(QByteArray type READ type USER true)
    Q_PROPERTY(qreal minimum READ getMinimum WRITE setMinimum USER true)
    Q_PROPERTY(qreal maximum READ getMaximum WRITE setMaximum USER true)

    Q_PROPERTY(qreal lowerCriticalStart READ getLowerCriticalStart WRITE setLowerCriticalStart USER true)
    Q_PROPERTY(qreal lowerCriticalEnd READ getLowerCriticalEnd WRITE setLowerCriticalEnd USER true)
    Q_PROPERTY(QColor lowerCriticalColor READ getLowerCriticalColor WRITE setLowerCriticalColor USER true)
    Q_PROPERTY(bool lowerCriticalEnabled READ getLowerCriticalEnabled WRITE setLowerCriticalEnabled USER true)

    Q_PROPERTY(qreal lowerWarningStart READ getLowerWarningStart WRITE setLowerWarningStart USER true)
    Q_PROPERTY(qreal lowerWarningEnd READ getLowerWarningEnd WRITE setLowerWarningEnd USER true)
    Q_PROPERTY(QColor lowerWarningColor READ getLowerWarningColor WRITE setLowerWarningColor USER true)
    Q_PROPERTY(bool lowerWarningEnabled READ getLowerWarningEnabled WRITE setLowerWarningEnabled USER true)

    Q_PROPERTY(qreal ValidStart READ getValidStart WRITE setValidStart USER true)
    Q_PROPERTY(qreal ValidEnd READ getValidEnd WRITE setValidEnd USER true)
    Q_PROPERTY(QColor ValidColor READ getValidColor WRITE setValidColor USER true)
    Q_PROPERTY(bool ValidEnabled READ getValidEnabled WRITE setValidEnabled USER true)

    Q_PROPERTY(qreal upperWarningStart READ getUpperWarningStart WRITE setUpperWarningStart USER true)
    Q_PROPERTY(qreal upperWarningEnd READ getUpperWarningEnd WRITE setUpperWarningEnd USER true)
    Q_PROPERTY(QColor upperWarningColor READ getUpperWarningColor WRITE setUpperWarningColor USER true)
    Q_PROPERTY(bool upperWarningEnabled READ getUpperWarningEnabled WRITE setUpperWarningEnabled USER true)

    Q_PROPERTY(qreal upperCriticalStart READ getUpperCriticalStart WRITE setUpperCriticalStart USER true)
    Q_PROPERTY(qreal upperCriticalEnd READ getUpperCriticalEnd WRITE setUpperCriticalEnd USER true)
    Q_PROPERTY(QColor upperCriticalColor READ getUpperCriticalColor WRITE setUpperCriticalColor USER true)
    Q_PROPERTY(bool upperCriticalEnabled READ getUpperCriticalEnabled WRITE setUpperCriticalEnabled USER true)

    Q_PROPERTY(QByteArray channelName READ getChannelName WRITE setChannelName USER true)
    Q_PROPERTY(bool autoUpdateEnabled READ getAutoUpdateEnabled WRITE setAutoUpdateEnable USER true)
    Q_PROPERTY(int autoUpdateRateMs READ getAutoUpdateRateMs WRITE setAutoUpdateRateMs USER true)

public:
    explicit DGauge(QWidget *parent = nullptr);

    void setValue(qreal value);
    qreal getValue() const { return g_value; }

    void setMinimum(qreal minimum) { g_minimum = minimum; }
    qreal getMinimum() const { return g_minimum; }

    void setMaximum(qreal maximum) { g_maximum = maximum; }
    qreal getMaximum() const { return g_maximum; }

    void setChannelName(QByteArray channelName) { g_channelName = channelName; }
    QByteArray getChannelName() const { return g_channelName; }

    void setAutoUpdateEnable(bool autoUpdateEnable);
    bool getAutoUpdateEnabled() const { return g_autoUpdateEnabled; }
    void setAutoUpdateRateMs(int autoUpdateRateMs) { g_autoUpdateRateMs = autoUpdateRateMs; }
    int getAutoUpdateRateMs() const { return g_autoUpdateRateMs; }

    // lower critical
    void setLowerCriticalStart(qreal lowerCriticalStart) { g_lowerCriticalStart = lowerCriticalStart; }
    qreal getLowerCriticalStart() const { return g_lowerCriticalStart; }
    void setLowerCriticalEnd(qreal lowerCriticalEnd) { g_lowerCriticalEnd = lowerCriticalEnd; }
    qreal getLowerCriticalEnd() const { return g_lowerCriticalEnd; }
    void setLowerCriticalColor(QColor lowerCriticalColor) { g_lowerCriticalColor = lowerCriticalColor; }
    QColor getLowerCriticalColor() const { return g_lowerCriticalColor; }
    void setLowerCriticalEnabled(bool drawLowerCriticalEnabled) { g_lowerCriticalEnabled = drawLowerCriticalEnabled; }
    bool getLowerCriticalEnabled() const { return g_lowerCriticalEnabled; }

    // lower warning
    void setLowerWarningStart(qreal lowerWarningStart) { g_lowerWarningStart = lowerWarningStart; }
    qreal getLowerWarningStart() const { return g_lowerWarningStart; }
    void setLowerWarningEnd(qreal lowerWarningEnd) { g_lowerWarningEnd = lowerWarningEnd; }
    qreal getLowerWarningEnd() const { return g_lowerWarningEnd; }
    void setLowerWarningColor(QColor lowerWarningColor) { g_lowerWarningColor = lowerWarningColor; }
    QColor getLowerWarningColor() const { return g_lowerWarningColor; }
    void setLowerWarningEnabled(bool drawLowerWarningEnabled) { g_lowerWarningEnabled = drawLowerWarningEnabled; }
    bool getLowerWarningEnabled() const { return g_lowerWarningEnabled; }

    // valid
    void setValidStart(qreal ValidStart) { g_validStart = ValidStart; }
    qreal getValidStart() const { return g_validStart; }
    void setValidEnd(qreal ValidEnd) { g_validEnd = ValidEnd; }
    qreal getValidEnd() const { return g_validEnd; }
    void setValidColor(QColor ValidColor) { g_validColor = ValidColor; }
    QColor getValidColor() const { return g_validColor; }
    void setValidEnabled(bool drawValidEnabled) { g_validEnabled = drawValidEnabled; }
    bool getValidEnabled() const { return g_validEnabled; }

    // upper warning
    void setUpperWarningStart(qreal upperWarningStart) { g_upperWarningStart = upperWarningStart; }
    qreal getUpperWarningStart() const { return g_upperWarningStart; }
    void setUpperWarningEnd(qreal upperWarningEnd) { g_upperWarningEnd = upperWarningEnd; }
    qreal getUpperWarningEnd() const { return g_upperWarningEnd; }
    void setUpperWarningColor(QColor upperWarningColor) { g_upperWarningColor = upperWarningColor; }
    QColor getUpperWarningColor() const { return g_upperWarningColor; }
    void setUpperWarningEnabled(bool drawUpperWarningEnabled) { g_upperWarningEnabled = drawUpperWarningEnabled; }
    bool getUpperWarningEnabled() const { return g_upperWarningEnabled; }

    // upper critical
    void setUpperCriticalStart(qreal upperCriticalStart) { g_upperCriticalStart = upperCriticalStart; }
    qreal getUpperCriticalStart() const { return g_upperCriticalStart; }
    void setUpperCriticalEnd(qreal upperCriticalEnd) { g_upperCriticalEnd = upperCriticalEnd; }
    qreal getUpperCriticalEnd() const { return g_upperCriticalEnd; }
    void setUpperCriticalColor(QColor upperCriticalColor) { g_upperCriticalColor = upperCriticalColor; }
    QColor getUpperCriticalColor() const { return g_upperCriticalColor; }
    void setUpperCriticalEnabled(bool drawUpperCriticalEnabled) { g_upperCriticalEnabled = drawUpperCriticalEnabled; }
    bool getUpperCriticalEnabled() const { return g_upperCriticalEnabled; }

    void save(QDataStream& out) const;
    void load(QDataStream& in);
    void newParent(QWidget *parent);

public slots:
    virtual void gaugeConfigure(DGauge *display);
    virtual void refresh() { update(); }

private slots:
    void autoUpdate();

protected:
    virtual QByteArray type() const = 0;

    QTimer g_autoUpdateTimer;
    QByteArray g_channelName;
    int g_autoUpdateRateMs = 100;
    bool g_autoUpdateEnabled = false;

    qreal g_minimum = 0;
    qreal g_maximum = 100;
    qreal g_value = 0;

    // arcs and alarm areas
    qreal g_lowerCriticalStart = 0;
    qreal g_lowerCriticalEnd = 0;
    QColor g_lowerCriticalColor = QColor(Qt::red);
    bool g_lowerCriticalEnabled = true;

    qreal g_lowerWarningStart = 0;
    qreal g_lowerWarningEnd = 0;
    QColor g_lowerWarningColor = QColor(Qt::yellow);
    bool g_lowerWarningEnabled = true;

    qreal g_validStart = 0;
    qreal g_validEnd = 0;
    QColor g_validColor = QColor(Qt::green);
    bool g_validEnabled = true;

    qreal g_upperWarningStart = 0;
    qreal g_upperWarningEnd = 0;
    QColor g_upperWarningColor = QColor(Qt::yellow);
    bool g_upperWarningEnabled = true;

    qreal g_upperCriticalStart = 0;
    qreal g_upperCriticalEnd = 0;
    QColor g_upperCriticalColor = QColor(Qt::red);
    bool g_upperCriticalEnabled = true;
};

QDataStream & operator<< (QDataStream& out, const DGauge& gauge);
QDataStream & operator>> (QDataStream& in, DGauge& gauge);
}

#endif // GAUGE_H
