#ifndef GAUGELCD_H
#define GAUGELCD_H

#include "gauge.h"

#include <QLCDNumber>

using namespace std;

namespace Dynamometer
{
class DLCDGauge : public DGauge
{
    Q_OBJECT
    Q_PROPERTY(int digits READ getDigits WRITE setDigits USER true)

public:
    explicit DLCDGauge(QWidget *parent = nullptr);
    virtual ~DLCDGauge() override;

    virtual QByteArray type() const override { return "dial"; }

    void setDigits(int digits) { g_digits = digits; g_lcdNumber.setDigitCount(digits); }
    int getDigits() const { return g_digits; }

    void setContextEnabled(bool contextEnabled) { g_contextEnabled = contextEnabled; }
    bool getContextEnabled() const { return g_contextEnabled; }

public slots:
    void showContextMenu(const QPoint & point);
//    void refresh() override { }

private slots:
    void LCDConfigure();
    void contextMenuChannelSelected(QAction *action);
    void bringToFront();
    void sendToBack();

protected:
    void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    QLCDNumber g_lcdNumber;
    int g_digits = 8;
    bool g_contextEnabled = true;
};
}

#endif // GAUGELCD_H
