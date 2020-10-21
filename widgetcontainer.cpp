#include "widgetcontainer.h"

#include <QPoint>
#include <QRect>
#include <QRectF>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QApplication>

namespace Dynamometer
{
DWidgetContainer::DWidgetContainer(QWidget *parent)
{
    setParent(parent);

    w_mode = NONE;

    setAttribute(Qt::WA_DeleteOnClose);
    setAutoFillBackground(true);

    // see through background needed for QGraphicsView(s)
    QPalette p;
    p.setColor(QPalette::Background, QColor(0,0,0,0));
    setPalette(p);

    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);
}

void DWidgetContainer::mousePressEvent(QMouseEvent *event)
{
    if (!w_editingEnabled) return;

    if (event->buttons() & Qt::LeftButton)
    {
        w_infocus = true;
        w_position = QPoint(event->globalX()-geometry().x(), event->globalY()-geometry().y());
        w_relativeGeometry = geometry();
        repaint();
    }
}


void DWidgetContainer::paintEvent(QPaintEvent *)
{
QPainter painter(this);
QColor handleColor;

    if (w_infocus)
    {
        QColor pbc = parentWidget()->palette().color(QPalette::Background);
        int g = static_cast<int>(pbc.red() * .299 + pbc.green() * .587 + pbc.blue() * .114);
        if (g > 128) handleColor = QColor(Qt::black);
        else handleColor = QColor(Qt::white);

        // Draw container selection
        painter.fillRect(0, 0, HANDLESIZE, HANDLESIZE, handleColor);
        painter.fillRect(width() - HANDLESIZE, 0, HANDLESIZE, HANDLESIZE, handleColor);
        painter.fillRect(width() - HANDLESIZE, height() - HANDLESIZE, HANDLESIZE, HANDLESIZE, handleColor);
        painter.fillRect(0, height() - HANDLESIZE, HANDLESIZE, HANDLESIZE, handleColor);
    }
    painter.end();
}

void DWidgetContainer::mouseMoveEvent(QMouseEvent *event) {

    if (!w_editingEnabled) return;
    if (!w_infocus) return;

    if (!event->buttons() && Qt::LeftButton)
    {
        setCursorShape(event->pos());
        return;
    }

    QPoint toMove = event->globalPos() - w_position;

    if (event->buttons() & Qt::LeftButton)
    {
        switch (w_mode)
        {
            case MOVE:
            case NONE:
                if (toMove.x() < 0) toMove.setX(0);
                if (toMove.y() < 0) toMove.setY(0);
                if (toMove.x() > this->parentWidget()->width() - this->width())
                    toMove.setX(this->parentWidget()->width() - this->width());
                if (toMove.y() > this->parentWidget()->height() - this->height())
                    toMove.setY(this->parentWidget()->height() - this->height());

                move(toMove);
                w_relativeGeometry = geometry();
                w_parentRelativeGeometry = this->parentWidget()->geometry();
                emit newGeometry(this->geometry());
                break;

            case RESIZETL:
            {    //Left-Top
                int newwidth = event->globalX() - w_position.x() - geometry().x();
                int newheight = event->globalY() - w_position.y() - geometry().y();
                QPoint toMove = event->globalPos() - w_position;

                if (toMove.x() < 0 || width() - newwidth < minimumWidth())
                {
                    newwidth = 0;
                    toMove.setX(x());
                }

                if (toMove.y() < 0 || height()- newheight < minimumHeight())
                {
                    newheight = 0;
                    toMove.setY(y());
                }

                resize(width() - newwidth, height() - newheight);
                move(toMove.x(), toMove.y());
                break;
            }

            case RESIZETR:
            {    //Right-Top
                int newHeight = event->globalY() - w_position.y() - y();
                int newWidth = event->x();

                QPoint toMove = event->globalPos() - w_position;

                if (toMove.y() < 0 || height() - newHeight < minimumHeight())
                {
                    newHeight = 0;
                    toMove.setY(y());
                }

                if (x() + event->x() > parentWidget()->width())
                {
                    newWidth = width();
                }

                resize(newWidth, height() - newHeight);
                move(x(), toMove.y());
                break;
            }

            case RESIZEBL:
            {    //Left-Bottom
                int newWidth = event->globalX() - w_position.x() - geometry().x();
                int newHeight = event->y();

                QPoint toMove = event->globalPos() - w_position;

                if (toMove.x() < 0 || width() - newWidth < minimumWidth())
                {
                    newWidth = 0;
                    toMove.setX(x());
                }

                if (y() + event->y() > parentWidget()->height())
                {
                    newHeight = height();
                }

                resize(width() - newWidth, newHeight);
                move(toMove.x(), y());
                break;
            }

            case RESIZEBR:
            {    //Right-Bottom
                int newWidth = event->x();
                int newHeight = event->y();

                if (x() + newWidth > parentWidget()->width())
                    newWidth = width();

                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();

                resize(newWidth, newHeight);
                break;
            }

        case RESIZEL:
        {     //Left
            int newWidth = event->globalX() - w_position.x() - geometry().x();
            QPoint toMove = event->globalPos() - w_position;

            if (toMove.x() < 0 || width() - newWidth < minimumWidth())
            {
                newWidth = 0;
                toMove.setX(x());
            }

            resize(width() - newWidth, height());
            move(toMove.x(), this->y());
            break;
        }

        case RESIZET:
        {     //Top
            int newHeight = event->globalY() - w_position.y() - geometry().y();
            QPoint toMove = event->globalPos() - w_position;

            if (toMove.y() < 0 || height()- newHeight < minimumHeight())
            {
                newHeight = 0;
                toMove.setY(geometry().y());
            }

            resize(width(), height() - newHeight);
            move(x(), toMove.y());
            break;
        }

        case RESIZER:
        {     //Right
            int newWidth = event->x();

            if (x() + newWidth > parentWidget()->width())
                newWidth = width();

            resize(newWidth, height());
            break;
        }

        case RESIZEB:
            {     //Bottom
                int newHeight = event->y();
                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();
                resize(width(), newHeight);
                break;
            }
        }
    }

    w_relativeGeometry = geometry();
    w_parentRelativeGeometry = this->parentWidget()->geometry();
    emit newGeometry(this->geometry());
}

void DWidgetContainer::setCursorShape(const QPoint &pos)
{
    const int diff = 5;
    QRect topLeft = { 0, 0, diff, diff };
    QRect topRight = { width() - diff, 0, diff, diff };
    QRect bottomRight = { width() - diff, height() - diff, diff, diff };
    QRect bottomLeft = { 0, height() - diff, diff, diff };
    QRect top = { 0, 0, width(), diff };
    QRect right = { width() - diff, 0, diff, height() };
    QRect bottom = { 0, height() - diff, width(), diff };
    QRect left = { 0, 0, diff, height() };

    // top-left
    if (topLeft.contains(pos))
    {
        w_mode = RESIZETL;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (topRight.contains(pos))
    {
        w_mode = RESIZETR;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (bottomRight.contains(pos))
    {
        w_mode = RESIZEBR;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (bottomLeft.contains(pos))
    {
        w_mode = RESIZEBL;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (top.contains(pos))
    {
        w_mode = RESIZET;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (right.contains(pos))
    {
        w_mode = RESIZER;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (bottom.contains(pos))
    {
        w_mode = RESIZEB;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (left.contains(pos))
    {
        w_mode = RESIZEL;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else
    {
        setCursor(QCursor(Qt::ArrowCursor));
        w_mode = MOVE;
    }
}

void DWidgetContainer::focusOutEvent(QFocusEvent *) {
    if (!w_editingEnabled) return;

    w_mode = NONE;
    emit outFocus(false);

    w_infocus = false;
    setCursor(QCursor(Qt::ArrowCursor));
    update();
}

void DWidgetContainer::keyPressEvent(QKeyEvent *e)
{
    if (!w_editingEnabled) return;
    if (e->key() == Qt::Key_Delete)
    {
        this->deleteLater();
    }

    // Moving container with arrows
    if (!QApplication::keyboardModifiers())
    {
        QPoint newPos(x(),y());

        if (e->key() == Qt::Key_Up)
        {
            newPos.setY(newPos.y() - 1);
            if (newPos.y() < 0) return;
        }

        if (e->key() == Qt::Key_Down)
        {
            newPos.setY(newPos.y() + 1);
            if (newPos.y() > parentWidget()->height() - height()) return;
        }

        if (e->key() == Qt::Key_Left)
        {
            newPos.setX(newPos.x() - 1);
            if (newPos.x() < 0) return;
        }

        if (e->key() == Qt::Key_Right)
        {
            newPos.setX(newPos.x() + 1);
            if (newPos.x() > parentWidget()->width() - width()) return;
        }

        move(newPos);
        emit newGeometry(this->geometry());
    }
    if (QApplication::keyboardModifiers() == Qt::ControlModifier) {
        if (e->key() == Qt::Key_Up)
        {
            if (height() <= minimumHeight()) return;
            resize(width(), height() - 1);
        }

        if (e->key() == Qt::Key_Down)
        {
            if (height() >= maximumHeight()) return;
            if (geometry().y() + height() >= parentWidget()->height()) return;
            resize(width(), height() + 1);
        }

        if (e->key() == Qt::Key_Left)
        {
            resize(width() - 1, height());
        }

        if (e->key() == Qt::Key_Right)
        {
            if (width() >= maximumWidth()) return;
            if (geometry().x() + width() >= parentWidget()->width()) return;
            resize(width() + 1, height());
        }

        emit newGeometry(this->geometry());
    }
}

bool DWidgetContainer::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::Show:
        w_relativeGeometry = geometry();
        if (dynamic_cast<QWidget *>(parent()))
        {
            w_parentRelativeGeometry = parentWidget()->geometry();
            w_scaleValid = true;
        }
        break;

    default:
        break;

    }

    return QWidget::event(event);
}

bool DWidgetContainer::eventFilter(QObject *obj, QEvent *evt)
{
    if (evt->type() == QEvent::Resize)
    {
        // scale geometry as parent is resized
        if (evt->type() == QEvent::Resize && obj == this->parentWidget() && w_scalingEnabled && w_scaleValid)
        {
            qreal xscale = static_cast<qreal>(parentWidget()->geometry().width()) / w_parentRelativeGeometry.width();
            qreal yscale = static_cast<qreal>(parentWidget()->geometry().height()) / w_parentRelativeGeometry.height();

            setGeometry(static_cast<int>(w_relativeGeometry.left() * xscale), static_cast<int>(w_relativeGeometry.top() * yscale),
                        static_cast<int>(w_relativeGeometry.width() * xscale), static_cast<int>(w_relativeGeometry.height() * yscale));
        }
    }
    return QWidget::eventFilter(obj, evt);
}

void DWidgetContainer::setParent(QWidget *parent)
{
    if (dynamic_cast<QWidget *>(parentWidget()))
    {
        parentWidget()->removeEventFilter(this);
        w_scaleValid = false;
    }

    QWidget::setParent(parent);

    if (dynamic_cast<QWidget *>(parentWidget()))
    {
        parentWidget()->installEventFilter(this);
        w_parentRelativeGeometry = parentWidget()->geometry();
        w_relativeGeometry = geometry();
        w_scaleValid = true;
    }
}

}
