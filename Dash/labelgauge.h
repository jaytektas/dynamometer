#ifndef LABELGAUGE_H
#define LABELGAUGE_H

#include "gauge.h"

#include <QLabel>

using namespace std;

namespace Dynamometer
{
class DLabelGauge : public DGauge
{
    Q_OBJECT
    Q_PROPERTY(QString label READ getLabel WRITE setLabel USER true)
    Q_PROPERTY(QFont labelFont READ getLabelFont WRITE setLabelFont USER true)
    Q_PROPERTY(QByteArray format READ getFormat WRITE setFormat USER true)

public:
    explicit DLabelGauge(QWidget *parent = nullptr);
    virtual ~DLabelGauge() override;

    virtual QByteArray type() const override { return "label"; }

    void setLabel(QString label) { g_label = label; }
    QString getLabel() const { return g_label; }

    void setLabelFont(QFont labelFont) { g_labelFont = labelFont; }
    QFont getLabelFont() const { return g_labelFont; }

    void setContextEnabled(bool contextEnabled) { g_contextEnabled = contextEnabled; }
    bool getContextEnabled() const { return g_contextEnabled; }

    void setFormat(QByteArray format) { g_format = format; }
    QByteArray getFormat() const { return g_format; }

public slots:
    void showContextMenu(const QPoint & point);
//    void refresh() override { }

private slots:
    void labelConfigure();
    void contextMenuChannelSelected(QAction *action);
    void bringToFront();
    void sendToBack();

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    QPixmap g_baseDrawing = QPixmap(500, 500);

    QFont g_labelFont = QFont("ubuntu", 40);
    QString g_label = "Hello World!";

    int g_tWidth;
    int g_tHeight;
    int g_xTranslate;
    int g_yTranslate;
    qreal g_xscale;
    qreal g_yscale;
    bool g_lockAspect = true;

    bool g_contextEnabled = true;
    QByteArray g_format = "%+06.2f";
};
}

#endif // LABELGAUGE_H
