#ifndef MOVEABLEWIDGET_H
#define MOVEABLEWIDGET_H

#include <QWidget>

#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QtGui>
#include <QVBoxLayout>
#include <QMenu>

using namespace std;

namespace Dynamometer
{
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

class DMoveableWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QByteArray type READ type USER true)

public:
    explicit DMoveableWidget(QWidget *parent = nullptr);
    ~DMoveableWidget() override;

    void save(QDataStream& out) const;
    void load(QDataStream& in);
    void newParent(QWidget *parent);

signals:
    void inFocus(bool mode);
    void outFocus(bool mode);
    void newGeometry(QRect rect);

public slots:
    virtual void refresh() { update(); }

protected:
    virtual QByteArray type() const = 0;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void keyPressEvent(QKeyEvent*) override;
    virtual void focusInEvent(QFocusEvent*) override;
    virtual void focusOutEvent(QFocusEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;
    virtual void setCursorShape(const QPoint &e_pos);

    QVBoxLayout* m_vLayout = nullptr;
    QPoint m_position;
    QColor m_handleColor = QColor(Qt::black);

    int m_mode;
    bool m_infocus = false;
    bool m_isEditing = true;

    QRect m_parentRelativeGeometry;
    QRect m_relativeGeometry;
    bool m_scale = false;

};

QDataStream & operator<< (QDataStream& out, const DMoveableWidget& gauge);
QDataStream & operator>> (QDataStream& in, DMoveableWidget& gauge);
}

#endif // MOVEABLEWIDGET_H
