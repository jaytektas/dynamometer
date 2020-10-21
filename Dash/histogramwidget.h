#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include "gauge.h"
#include "chartchannel.h"

#include <QtCharts>

using namespace std;
using namespace QtCharts;

namespace Dynamometer
{
class DHistogramConfig;

class DHistogramWidget : public QChartView
{
    Q_OBJECT
    Q_PROPERTY(QByteArray type READ type USER true)
    Q_PROPERTY(int points READ getPoints WRITE setPoints USER true)

    Q_PROPERTY(bool autoUpdateEnabled READ getAutoUpdateEnabled WRITE setAutoUpdateEnable USER true)
    Q_PROPERTY(int autoUpdateRateMs READ getAutoUpdateRateMs WRITE setAutoUpdateRateMs USER true)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle USER true)
    Q_PROPERTY(QFont titleFont READ getTitleFont WRITE setTitleFont USER true)

protected:
    enum modes{
        NONE = 0,
        MOVE = 1,
        RESIZETL = 2,
        RESIZET = 3,
        RESIZETR = 4,
        RESIZER = 5,
        RESIZEBR = 6,
        RESIZEB = 7,
        RESIZEBL = 8,
        RESIZEL = 9
    };

#define HANDLESIZE 6


    QMap<QByteArray, DChartChannel *> h_chartChannels;

public:
    explicit DHistogramWidget(QWidget *parent = nullptr);
    DHistogramWidget& operator= (const DHistogramWidget &histogramWidget);

    void setPoints(int points) { h_points = points; }
    int getPoints() const { return h_points; }

    void setAutoUpdateEnable(bool autoUpdateEnable);
    bool getAutoUpdateEnabled() const { return h_autoUpdateEnabled; }

    void setAutoUpdateRateMs(int autoUpdateRateMs);
    int getAutoUpdateRateMs() const { return h_autoUpdateRateMs; }

    void setTitle(QString title) { chart()->setTitle(title); }
    QString getTitle() const { return chart()->title(); }

    void setTitleFont(QFont titleFont) { chart()->setTitleFont(titleFont); }
    QFont getTitleFont() const { return chart()->titleFont(); }

    void setContextEnabled(bool contextEnabled) { h_contextEnabled = contextEnabled; }
    bool getContextEnabled() const { return h_contextEnabled; }

    void setParent(QWidget *parent);
    QMap<QByteArray, DChartChannel *>& getChartChannels() { return h_chartChannels; }

    QByteArray type() const { return "histogram"; }

    QMap <QByteArray, DChartChannel *> axes(QFlags<Qt::Orientation> = Qt::Horizontal | Qt::Vertical);

    QValueAxis *attachAxis(QByteArray channelName);
    QValueAxis *detachAxis(QByteArray channelName);

signals:
    void channelAdded(QByteArray channelName);
    void channelRemoved(QByteArray channelName);

public slots:
    void showContextMenu(const QPoint & point);
    void autoUpdate();
//    void refresh() override { }

private slots:
    void bringToFront();
    void sendToBack();
    void deleteChannel();
    void configure();
    void reset();

protected:
    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent * e) override;
    bool eventFilter(QObject *obj, QEvent *evt) override;
    void keyPressEvent(QKeyEvent*) override;
    void focusOutEvent(QFocusEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void setCursorShape(const QPoint &e_pos);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override { event->acceptProposedAction(); }
    void dragLeaveEvent(QDragLeaveEvent *event) override { event->ignore(); }

    void autoUpdateToggle();

    QTimer h_autoUpdateTimer;
    int h_autoUpdateRateMs = 100;
    bool h_autoUpdateEnabled = false;

    int h_points = 100;

    bool h_contextEnabled = false;

    int h_mode;
    bool h_infocus = false;
    bool h_editingEnabled = true;

    QRect h_parentRelativeGeometry;
    QRect h_relativeGeometry;
    bool h_scaleValid = false;
    bool h_scalingEnabled = true;
    QPoint h_position;

    DHistogramConfig *h_configureDialog = nullptr;

};

}

#endif // HISTOGRAMWIDGET_H
