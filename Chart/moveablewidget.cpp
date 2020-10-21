#include "moveablewidget.h"

namespace Dynamometer
{
DMoveableWidget::DMoveableWidget(QWidget *parent) : QWidget(parent)
{
    m_mode = NONE;
    setAttribute(Qt::WA_DeleteOnClose);
    setVisible(true);
    setAutoFillBackground(false);
    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);
    setFocus();
    m_infocus = true;

    setMinimumSize(QSize(80,80));
    setMouseTracking(true);
}

DMoveableWidget::~DMoveableWidget()
{
    delete m_vLayout;
}

void DMoveableWidget::focusInEvent(QFocusEvent *) {
//    m_infocus = true;
//    repaint();
//    emit inFocus(true);
}

void DMoveableWidget::focusOutEvent(QFocusEvent *) {
    if (!m_isEditing) return;

    m_mode = NONE;
    emit outFocus(false);

    m_infocus = false;
    setCursor(QCursor(Qt::ArrowCursor));
    update();
}

void DMoveableWidget::paintEvent(QPaintEvent *)
{
QPainter painter(this);
    if (m_infocus)
    {
        if (parentWidget())
        {
            QColor pbc = parentWidget()->palette().color(QPalette::Background);
            int g = static_cast<int>(pbc.red() * .299 + pbc.green() * .587 + pbc.blue() * .114);
            if (g > 128) m_handleColor = QColor(Qt::black);
            else m_handleColor = QColor(Qt::white);
        }
        else m_handleColor = Qt::black;

        // Draw container selection
        painter.fillRect(0, 0, 6, 6, m_handleColor);
        painter.fillRect(width() - 6, 0, 6, 6, m_handleColor);
        painter.fillRect(width() - 6, height() - 6, 6, 6, m_handleColor);
        painter.fillRect(0, height() - 6, 6, 6, m_handleColor);
    }

}

void DMoveableWidget::mousePressEvent(QMouseEvent *e)
{
    if (!m_isEditing) return;

    if (e->buttons() & Qt::LeftButton)
    {
        m_infocus = true;
        m_position = QPoint(e->globalX()-geometry().x(), e->globalY()-geometry().y());
        repaint();
    }
}

void DMoveableWidget::keyPressEvent(QKeyEvent *e)
{
    if (!m_isEditing) return;
    if (e->key() == Qt::Key_Delete) {
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

void DMoveableWidget::setCursorShape(const QPoint &e_pos) {
    const int diff = 5;
    if (
            //Left-Bottom
            ((e_pos.y() > y() + height() - diff) &&     //Bottom
             (e_pos.x() < x() + diff)) ||               //Left
            //Right-Bottom
            ((e_pos.y() > y() + height() - diff) &&     //Bottom
             (e_pos.x() > x() + width() - diff)) ||     //Right
            //Left-Top
            ((e_pos.y() < y() + diff) &&                //Top
             (e_pos.x() < x() + diff)) ||               //Left
            //Right-Top
            ((e_pos.y() < y() + diff) &&                //Top
             (e_pos.x() > x() + width() - diff))        //Right
            )
    {
        //Left-Bottom
        if ((e_pos.y() > y() + height() - diff) &&      //Bottom
                (e_pos.x() < x() + diff))               //Left
        {
            m_mode = RESIZEBL;
            setCursor(QCursor(Qt::SizeBDiagCursor));
        }
        //Right-Bottom
        if ((e_pos.y() > y() + height() - diff) &&      //Bottom
                (e_pos.x() > x() + width() - diff))     //Right
        {
            m_mode = RESIZEBR;
            setCursor(QCursor(Qt::SizeFDiagCursor));
        }
        //Left-Top
        if ((e_pos.y() < y() + diff) &&                 //Top
                (e_pos.x() < x() + diff))               //Left
        {
            m_mode = RESIZETL;
            setCursor(QCursor(Qt::SizeFDiagCursor));
        }
        //Right-Top
        if ((e_pos.y() < y() + diff) &&                 //Top
                (e_pos.x() > x() + width() - diff))     //Right
        {
            m_mode = RESIZETR;
            setCursor(QCursor(Qt::SizeBDiagCursor));
        }
    }
    // check cursor horizontal position
    else if ((e_pos.x() < x() + diff) ||                //Left
             ((e_pos.x() > x() + width() - diff)))      //Right
    {
        if (e_pos.x() < x() + diff) {                   //Left
            setCursor(QCursor(Qt::SizeHorCursor));
            m_mode = RESIZEL;
        } else {                                        //Right
            setCursor(QCursor(Qt::SizeHorCursor));
            m_mode = RESIZER;
        }
    }
    // check cursor vertical position
    else if (((e_pos.y() > y() + height() - diff)) ||   //Bottom
             (e_pos.y() < y() + diff))                  //Top
    {
        if (e_pos.y() < y() + diff) {                   //Top
            setCursor(QCursor(Qt::SizeVerCursor));
            m_mode = RESIZET;
        } else {                                        //Bottom
            setCursor(QCursor(Qt::SizeVerCursor));
            m_mode = RESIZEB;
        }
    } else {
        setCursor(QCursor(Qt::ArrowCursor));
        m_mode = MOVE;
    }
}

void DMoveableWidget::mouseReleaseEvent(QMouseEvent *e) {
    QWidget::mouseReleaseEvent(e);
}

void DMoveableWidget::mouseMoveEvent(QMouseEvent *e) {
    QWidget::mouseMoveEvent(e);
    if (!m_isEditing) return;
    if (!m_infocus) return;
    if (!e->buttons() && Qt::LeftButton) {
        QPoint p = QPoint(e->x() + geometry().x(), e->y() + geometry().y());
        setCursorShape(p);
        return;
    }

    if ((m_mode == MOVE || m_mode == NONE) && e->buttons() && Qt::LeftButton) {
        QPoint toMove = e->globalPos() - m_position;
        if (toMove.x() < 0) toMove.setX(0);
        if (toMove.y() < 0) toMove.setY(0);
        if (toMove.x() > this->parentWidget()->width() - this->width())
            toMove.setX(this->parentWidget()->width() - this->width());
        if (toMove.y() > this->parentWidget()->height() - this->height())
            toMove.setY(this->parentWidget()->height() - this->height());

        move(toMove);
        m_relativeGeometry = geometry();
        m_parentRelativeGeometry = this->parentWidget()->geometry();

        emit newGeometry(this->geometry());
        return;
    }

    if ((m_mode != MOVE) && e->buttons() && Qt::LeftButton) {
        switch (m_mode)
        {
            case RESIZETL:
            {    //Left-Top
                int newwidth = e->globalX() - m_position.x() - geometry().x();
                int newheight = e->globalY() - m_position.y() - geometry().y();
                QPoint toMove = e->globalPos() - m_position;

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
                int newHeight = e->globalY() - m_position.y() - y();
                int newWidth = e->x();

                QPoint toMove = e->globalPos() - m_position;

                if (toMove.y() < 0 || height() - newHeight < minimumHeight())
                {
                    newHeight = 0;
                    toMove.setY(y());
                }

                if (x() + e->x() > parentWidget()->width())
                {
                    newWidth = width();
                }

                resize(newWidth, height() - newHeight);
                move(x(), toMove.y());
                break;
            }

            case RESIZEBL:
            {    //Left-Bottom
                int newWidth = e->globalX() - m_position.x() - geometry().x();
                int newHeight = e->y();

                QPoint toMove = e->globalPos() - m_position;

                if (toMove.x() < 0 || width() - newWidth < minimumWidth())
                {
                    newWidth = 0;
                    toMove.setX(x());
                }

                if (y() + e->y() > parentWidget()->height())
                {
                    newHeight = height();
                }

                resize(width() - newWidth, newHeight);
                move(toMove.x(), y());
                break;
            }

            case RESIZEBR:
            {    //Right-Bottom
                int newWidth = e->x();
                int newHeight = e->y();

                if (x() + newWidth > parentWidget()->width())
                    newWidth = width();

                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();

                resize(newWidth, newHeight);
                break;
            }

        case RESIZEL:
        {     //Left
            int newWidth = e->globalX() - m_position.x() - geometry().x();
            QPoint toMove = e->globalPos() - m_position;

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
            int newHeight = e->globalY() - m_position.y() - geometry().y();
            QPoint toMove = e->globalPos() - m_position;

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
            int newWidth = e->x();

            if (x() + newWidth > parentWidget()->width())
                newWidth = width();

            resize(newWidth, height());
            break;
        }

        case RESIZEB:
            {     //Bottom
                int newHeight = e->y();
                if (y() + newHeight > parentWidget()->height())
                    newHeight = height();
                resize(width(), newHeight);
                break;
            }
        }

        m_relativeGeometry = geometry();
        m_parentRelativeGeometry = this->parentWidget()->geometry();
    }
    emit newGeometry(this->geometry());
}

void DMoveableWidget::save(QDataStream &out) const
{
    const QMetaObject *mo = metaObject();

    int count = 0;
    for (int i = 0; i < mo->propertyCount(); i++)
    {
        QMetaProperty mp = mo->property(i);
        if (mp.isUser())
            count++;
    }

    out << count;

    for (int i = 0; i < mo->propertyCount(); i++)
    {
        QMetaProperty mp = mo->property(i);
        if (mp.isUser())
            out << mp.name() << mp.read(this);
    }
}

void DMoveableWidget::load(QDataStream &in)
{
    int count = 0;
    in >> count;

    for (int i = 0; i < count; i++)
    {
        QByteArray name;
        QVariant value;
        in >> name;
        in >> value;
        setProperty(name, value);
    }
}

void DMoveableWidget::newParent(QWidget *parent)
{
    setParent(parent);
    m_parentRelativeGeometry = parentWidget()->geometry();
    parentWidget()->installEventFilter(this);
}

QDataStream & operator<< (QDataStream & out, const DMoveableWidget & gauge)
{
    gauge.save(out);
    return out;
}

QDataStream & operator>> (QDataStream & in, DMoveableWidget & gauge)
{
    gauge.load(in);
    return in;
}
}
