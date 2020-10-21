#include "chartlegend.h"

#include <QAbstractSeries>
#include <QLineSeries>

using namespace QtCharts;

namespace Dynamometer
{

DChartLegend::DChartLegend(QWidget *parent) : DWidgetContainer (parent)
{
    QPalette p;
    p.setColor(QPalette::Background, QColor(0,0,0,0));
    setPalette(p);
}

void DChartLegend::wheelEvent(QWheelEvent *)
{

}

void DChartLegend::paintEvent(QPaintEvent *event)
{
QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

//    QRectF target(0, 0, width(), height());
//    QRectF source(0, 0, width(), height());

//    painter.drawPixmap(target, c_baseDrawing, source);
    painter.save();

    if (c_drawBackgroundEnabled)
    {
        QBrush b;
        QPen p;
        p.setColor(c_backGroundColor);
        b.setColor(c_backGroundColor);
        b.setStyle(Qt::BrushStyle::SolidPattern);
        painter.setBrush(b);
        painter.setPen(p);
        painter.drawRoundRect(0, 0, width(), height(), c_backgroundCornerRadius);
    }

    if (parent())
    {
        QChartView *cv = dynamic_cast<QChartView *>(parent());
        if (cv && cv->chart()->series().count())
        {
            //c_legendFont.setPixelSize(40*c_xscale);
            painter.setPen(c_legendColor);
            painter.setFont(c_legendFont);
            int y = 0;

            QList<QAbstractSeries *> series = cv->chart()->series();
            for (QList<QAbstractSeries *>::iterator i = series.begin(); i != series.end(); i++)
            {
                QLineSeries *ls = dynamic_cast<QLineSeries *>((*i));
                if (ls && ls->isVisible())
                {
                    QString s = ls->name();
                    QFontMetricsF fm(painter.font());
                    qreal h = fm.size(Qt::TextSingleLine, s).height();
                    qreal mh = fm.ascent() - fm.descent();

                    y += h;
                    painter.setPen(ls->pen());
                    painter.setBrush(ls->pen().brush());
                    painter.drawRect(c_padding, c_padding + y - mh, mh, mh);
                    painter.drawText(c_padding * 2 + mh, c_padding + y, s);
                }
            }
        }
    }
    painter.restore();
    painter.end();

    DWidgetContainer::paintEvent(event);
}

void DChartLegend::resizeEvent(QResizeEvent *)
{
}

}
