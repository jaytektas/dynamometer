#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>

using namespace std;

namespace Dynamometer
{
class DWidgetContainer : public QWidget
{
    Q_OBJECT

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

public:
    explicit DWidgetContainer(QWidget *parent = nullptr);
    virtual void setParent(QWidget *parent);

    void setScalingEnabled(bool scalingEnabled) { w_scalingEnabled = scalingEnabled; }
    bool getScalingEnabeld() const { return w_scalingEnabled; }

signals:
    void inFocus(bool mode);
    void outFocus(bool mode);
    void newGeometry(QRect rect);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual bool event(QEvent * e) override;
    virtual bool eventFilter(QObject *obj, QEvent *evt) override;
    virtual void keyPressEvent(QKeyEvent*) override;
    virtual void focusOutEvent(QFocusEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;
    virtual void setCursorShape(const QPoint &e_pos);

    QVBoxLayout* w_vLayout = nullptr;
    QPoint w_position;

    int w_mode;
    bool w_infocus = false;
    bool w_editingEnabled = true;

    QRect w_parentRelativeGeometry;
    QRect w_relativeGeometry;
    bool w_scaleValid = false;
    bool w_scalingEnabled = false;
};

}

#endif // WIDGETCONTAINER_H
