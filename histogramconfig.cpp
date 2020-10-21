#include "histogramconfig.h"
#include "ui_histogramconfig.h"

namespace Dynamometer
{
DHistogramConfig::DHistogramConfig(DHistogramWidget *parent) : QDialog(parent), ui(new Ui::DHistogramConfig)
{
    ui->setupUi(this);
    show();

    h_parent = parent;

    h_display = new DHistogramWidget(parent);
    connect(h_display, &DHistogramWidget::channelAdded, this, &DHistogramConfig::channelAdded);
    connect(h_display, &DHistogramWidget::channelRemoved, this, &DHistogramConfig::channelRemoved);

    // cause copy
    *h_display = *parent;
    currentChannelChanged(ui->currentChannel->currentText());

    h_display->setParent(ui->frame);
    h_display->setGeometry(0,0,100,100);
    h_display->show();

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({ "Property", "Value" });
    ui->tableWidget->setColumnWidth(0, 170);
    ui->tableWidget->setColumnWidth(1, 100);

    const QMetaObject *mo = parent->metaObject();
    int r = 0;
    for (int i = 0; i < mo->propertyCount(); i++)
        if (mo->property(i).isUser() && mo->property(i).isWritable())
        {
            h_display->setProperty(mo->property(i).name(), mo->property(i).read(parent));
            QTableWidgetItem *ni = new QTableWidgetItem(mo->property(i).name());
            ui->tableWidget->setRowCount(r+1);
            ui->tableWidget->setItem(r, 0, ni);
            ui->tableWidget->setRowHeight(r, 24);
            switch(static_cast<QMetaType::Type>(mo->property(i).read(parent).type()))
            {
                case QMetaType::QFont:
                {
                    QPushButton *pb = new QPushButton("Font...");
                    pb->setProperty("userfont", mo->property(i).read(parent));
                    pb->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, pb);
                    connect(pb, &QPushButton::clicked, this, &DHistogramConfig::fontButton);
                }
                break;
                case QMetaType::QColor:
                {
                    QPushButton *pb = new QPushButton;
                    pb->setProperty("property", mo->property(i).name());
                    QPalette p;
                    p.setColor(QPalette::Button, mo->property(i).read(parent).value<QColor>());
                    pb->setPalette(p);
                    ui->tableWidget->setCellWidget(r, 1, pb);
                    connect(pb, &QPushButton::clicked, this, &DHistogramConfig::colorButton);
                }
                break;

                case QMetaType::Bool:
                {
                    QCheckBox *cb = new QCheckBox();
                    cb->setProperty("property", mo->property(i).name());
                    bool state = mo->property(i).read(parent).value<bool>();
                     if (state == true) cb->setCheckState(Qt::CheckState::Checked);
                     else cb->setCheckState(Qt::CheckState::Unchecked);
                    ui->tableWidget->setCellWidget(r, 1, cb);
                    connect(cb, &QCheckBox::clicked, this, &DHistogramConfig::checkBox);
                }
                break;

                case QMetaType::Int:
                case QMetaType::Double:
                {
                    QLineEdit *le = new QLineEdit(QString::number(mo->property(i).read(parent).value<qreal>()));
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, &QLineEdit::textEdited, this, &DHistogramConfig::lineEdit);
                }
                break;

                case QMetaType::QByteArray:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QByteArray>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, &QLineEdit::textEdited, this, &DHistogramConfig::lineEdit);
                }
                break;

                case QMetaType::QString:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QString>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, &QLineEdit::textEdited, this, &DHistogramConfig::lineEdit);
                }
                break;

                case QMetaType::Char:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QString>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, &QLineEdit::textEdited, this, &DHistogramConfig::lineEdit);
                }
                break;

            default:
                break;
            }
        r++;
        }

    connect(ui->currentChannel, SIGNAL(currentIndexChanged(QString)), this, SLOT(currentChannelChanged(QString)));
}

DHistogramConfig::~DHistogramConfig()
{
    if (h_display) delete h_display;
    delete ui;
}

void DHistogramConfig::lineEdit(const QString &)
{
    QLineEdit *le = dynamic_cast<QLineEdit *>(sender());
    if (!le) return;
    QString name = le->property("property").toString();

    switch(static_cast<QMetaType::Type>(h_display->property(name.toUtf8().constData()).type()))
    {
        case QMetaType::Int:
            h_display->setProperty(name.toUtf8().constData(), le->text().toInt());
        break;

        case QMetaType::Double:
            h_display->setProperty(name.toUtf8().constData(), le->text().toDouble());
        break;

        case QMetaType::QByteArray:
            h_display->setProperty(name.toUtf8().constData(), le->text().toUtf8().constData());
            break;

        case QMetaType::QString:
            h_display->setProperty(name.toUtf8().constData(), le->text());
            break;

        case QMetaType::Char:
            h_display->setProperty(name.toUtf8().constData(), le->text().toUtf8().data()[0]);
            break;

        default:
            break;
    }
    DGauge *g = dynamic_cast<DGauge*>(h_display);
    if (g) g->refresh();
}

void DHistogramConfig::checkBox()
{
    QCheckBox *cb = dynamic_cast<QCheckBox *>(sender());
    if (!cb) return;
    bool state;

    if (cb->checkState() == Qt::CheckState::Checked)
        state = true;
    else state = false;

    QString name = cb->property("property").toString();
    h_display->setProperty(name.toUtf8().constData(), state);
    DGauge *g = dynamic_cast<DGauge*>(h_display);
    if (g) g->refresh();
}

void DHistogramConfig::colorButton()
{
    QPushButton *pb = dynamic_cast<QPushButton *>(sender());
    if (!pb) return;

    QColorDialog cd;
    QColor c;
    c = cd.getColor(pb->palette().color(QPalette::Button));
    if (c.spec() == QColor::Invalid) return;

    QPalette p = pb->palette();
    p.setColor(QPalette::Button, c);
    pb->setPalette(p);
    QString name = pb->property("property").toString().toUtf8().constData();
    h_display->setProperty(name.toUtf8().constData(), c);
    DGauge *g = dynamic_cast<DGauge*>(h_display);
    if (g) g->refresh();
}

void DHistogramConfig::fontButton()
{
    QPushButton *pb = dynamic_cast<QPushButton *>(sender());
    if (!pb) return;

    bool ok;

    QFont cf = pb->property("userfont").value<QFont>();
    QFont nf = QFontDialog::getFont(&ok, cf, this);
    if (ok)
    {
        QString name = pb->property("property").toString();
        pb->setProperty("userfont", nf);
        h_display->setProperty(name.toUtf8().constData(), nf);
    }
    DGauge *g = dynamic_cast<DGauge*>(h_display);
    if (g) g->refresh();
}

void DHistogramConfig::channelAdded(QByteArray channelName)
{
    ui->currentChannel->addItem(channelName);
    DChartChannel *chartChannel = h_display->getChartChannels().value(channelName);
    if (chartChannel)
    {
        // horizontal or vertical axis?
        QValueAxis *channelAxis = chartChannel->getAxis();
        if (channelAxis)
        {
            if (channelAxis->alignment() == Qt::AlignLeft || channelAxis->alignment() == Qt::AlignRight)
            {
                ui->verticalAxis->blockSignals(true);
                ui->verticalAxis->addItem(channelName);
                ui->verticalAxis->blockSignals(false);
            }
            else
            {
                ui->horizontalAxis->blockSignals(true);
                ui->horizontalAxis->addItem(channelName);
                ui->horizontalAxis->blockSignals(false);
            }
        }
    }
}

void DHistogramConfig::channelRemoved(QByteArray channelName)
{
int index;

        index = ui->verticalAxis->findText(channelName);
        if (index >= 0)
        {
            ui->verticalAxis->blockSignals(true);
            ui->verticalAxis->removeItem(index);
            ui->verticalAxis->blockSignals(false);
        }

        index = ui->horizontalAxis->findText(channelName);
        if (index >= 0)
        {
            ui->horizontalAxis->blockSignals(true);
            ui->horizontalAxis->removeItem(index);
            ui->horizontalAxis->blockSignals(false);
        }

        // may trigger details to be loaded of next available channel in combo
        index = ui->currentChannel->findText(channelName);
        if (index >= 0) ui->currentChannel->removeItem(index);
}

void DHistogramConfig::currentChannelChanged(QString currentChannelName)
{
    if (currentChannelName.isEmpty()) return;

    // fetch chart channel
    DChartChannel *chartChannel = h_display->getChartChannels().value(currentChannelName.toUtf8());

    if (chartChannel)
    {
        QValueAxis *channelAxis = chartChannel->getAxis();
        QLineSeries *lineSeries = chartChannel->getLineSeries();

        // series
        ui->verticalAxis->blockSignals(true);
        ui->verticalAxis->setCurrentIndex(ui->verticalAxis->findText(chartChannel->getVerticalAxis()));
        ui->verticalAxis->blockSignals(false);

        ui->horizontalAxis->blockSignals(true);
        ui->horizontalAxis->setCurrentIndex(ui->horizontalAxis->findText(chartChannel->getHorizontalAxis()));
        ui->horizontalAxis->blockSignals(false);

        QPalette p;
        p.setColor(QPalette::Button, lineSeries->color());
        ui->seriesColor->setPalette(p);

        // axis
        if (channelAxis)
        {
            ui->title->setText(channelAxis->titleText());
            ui->majorTicks->setText(QString::number(channelAxis->tickCount()));
            QPalette p;
            p.setColor(QPalette::Button, channelAxis->gridLineColor());
            ui->majorGridLineColor->setPalette(p);

            p.setColor(QPalette::Button, channelAxis->minorGridLineColor());
            ui->minorGridLineColor->setPalette(p);

            p.setColor(QPalette::Button, channelAxis->labelsColor());
            ui->labelColor->setPalette(p);

            ui->minorTicks->setText(QString::number(channelAxis->minorTickCount()));
            ui->minimum->setText(QString::number(chartChannel->getHintMin()));
            ui->maximum->setText(QString::number(chartChannel->getHintMax()));
            ui->labelFormat->setText(channelAxis->labelFormat());

            if (chartChannel->getAutoScaleAxis())
                ui->autoScale->setCheckState(Qt::Checked);
            else
                ui->autoScale->setCheckState(Qt::Unchecked);

            if (channelAxis->isVisible())
                ui->visible->setChecked(true);
            else
                ui->visible->setChecked(false);

            ui->alignment->blockSignals(true);
            switch (channelAxis->alignment())
            {
                case Qt::AlignLeft:
                    ui->alignment->setCurrentIndex(ui->alignment->findText("Left"));
                    break;
                case Qt::AlignRight:
                    ui->alignment->setCurrentIndex(ui->alignment->findText("Right"));
                    break;
                case Qt::AlignTop:
                    ui->alignment->setCurrentIndex(ui->alignment->findText("Top"));
                    break;
                case Qt::AlignBottom:
                    ui->alignment->setCurrentIndex(ui->alignment->findText("Bottom"));
                    break;
            }
            ui->alignment->blockSignals(false);
        }
        else
        {
            ui->title->setText("");
            ui->majorTicks->setText("");
            ui->minorTicks->setText("");
            ui->minimum->setText("");
            ui->maximum->setText("");
            ui->alignment->setCurrentIndex(-1);
            ui->currentChannel->setCurrentIndex(-1);

            ui->verticalAxis->setCurrentIndex(-1);
            ui->horizontalAxis->setCurrentIndex(-1);
        }

    }
}

void Dynamometer::DHistogramConfig::on_autoScale_stateChanged(int arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        if (arg1)
            chartChannel->setAutoScaleAxis(true);
        else
            chartChannel->setAutoScaleAxis(false);
    }
}

void Dynamometer::DHistogramConfig::on_title_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        QValueAxis *channelAxis = chartChannel->getAxis();

        if (channelAxis)
            channelAxis->setTitleText(arg1);
    }
}

void Dynamometer::DHistogramConfig::on_majorTicks_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        QValueAxis *channelAxis = chartChannel->getAxis();

        if (channelAxis)
            channelAxis->setTickCount(arg1.toInt());
    }
}

void Dynamometer::DHistogramConfig::on_minorTicks_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        QValueAxis *channelAxis = chartChannel->getAxis();

        if (channelAxis)
            channelAxis->setMinorTickCount(arg1.toInt());
    }
}

void Dynamometer::DHistogramConfig::on_alignment_currentIndexChanged(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        // remove vertical / horizontal combos
        if (chartChannel->getAlignment() == Qt::AlignLeft || chartChannel->getAlignment() == Qt::AlignRight)
        {
            int index = ui->verticalAxis->findText(chartChannel->getChannelName());
            if (index >= 0) ui->verticalAxis->removeItem(index);
        }
        else
        {
            int index = ui->horizontalAxis->findText(chartChannel->getChannelName());
            ui->horizontalAxis->removeItem(index);
        }

        // remove from all lineseries
        QValueAxis *axis = h_display->detachAxis(chartChannel->getChannelName());

        // remove from chart
        if (axis) h_display->chart()->removeAxis(axis);

        // add axis back to chart with new alignment
        if (arg1 == "Left")
        {
            h_display->chart()->addAxis(chartChannel->getAxis(), Qt::AlignLeft);
            chartChannel->setAlignment(Qt::AlignLeft);
        }
        if (arg1 == "Right")
        {
            h_display->chart()->addAxis(chartChannel->getAxis(), Qt::AlignRight);
            chartChannel->setAlignment(Qt::AlignRight);
        }
        if (arg1 == "Top")
        {
            h_display->chart()->addAxis(chartChannel->getAxis(), Qt::AlignTop);
            chartChannel->setAlignment(Qt::AlignTop);
        }
        if (arg1 == "Bottom")
        {
            h_display->chart()->addAxis(chartChannel->getAxis(), Qt::AlignBottom);
            chartChannel->setAlignment(Qt::AlignBottom);
        }

        // re-attach axis to lineseries
        h_display->attachAxis(chartChannel->getChannelName());

        // insert vertical / horizontal combos
        if (chartChannel->getAlignment() == Qt::AlignLeft || chartChannel->getAlignment() == Qt::AlignRight)
            ui->verticalAxis->addItem(chartChannel->getChannelName());
        else
            ui->horizontalAxis->addItem(chartChannel->getChannelName());
    }
}

void Dynamometer::DHistogramConfig::on_visible_stateChanged(int arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        if (arg1)
            chartChannel->setAxisVisible(true);
        else
            chartChannel->setAxisVisible(false);
    }
}

void Dynamometer::DHistogramConfig::on_minimum_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        chartChannel->setHintMin(ui->minimum->text().toDouble());
        chartChannel->getAxis()->setMin(chartChannel->getHintMin());
    }
}

void Dynamometer::DHistogramConfig::on_maximum_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        chartChannel->setHintMax(ui->maximum->text().toDouble());
        chartChannel->getAxis()->setMax(chartChannel->getHintMax());
    }
}

void Dynamometer::DHistogramConfig::on_seriesColor_clicked()
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (!chartChannel) return;

    QColorDialog cd;
    QColor c;
    c = cd.getColor(ui->seriesColor->palette().color(QPalette::Button));
    if (c.spec() == QColor::Invalid) return;

    // color button
    QPalette p = ui->seriesColor->palette();
    p.setColor(QPalette::Button, c);
    ui->seriesColor->setPalette(p);

    // color line series
    chartChannel->getLineSeries()->setColor(c);
}

void Dynamometer::DHistogramConfig::on_buttonBox_accepted()
{
    *h_parent = *h_display;
}

void Dynamometer::DHistogramConfig::on_majorGridLineColor_clicked()
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (!chartChannel) return;

    QColorDialog cd;
    QColor c;
    c = cd.getColor(ui->majorGridLineColor->palette().color(QPalette::Button));
    if (c.spec() == QColor::Invalid) return;

    // color button
    QPalette p = ui->majorGridLineColor->palette();
    p.setColor(QPalette::Button, c);
    ui->majorGridLineColor->setPalette(p);

    // color line series
    chartChannel->getAxis()->setGridLineColor(c);
}

void Dynamometer::DHistogramConfig::on_minorGridLineColor_clicked()
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (!chartChannel) return;

    QColorDialog cd;
    QColor c;
    c = cd.getColor(ui->minorGridLineColor->palette().color(QPalette::Button));
    if (c.spec() == QColor::Invalid) return;

    // color button
    QPalette p = ui->majorGridLineColor->palette();
    p.setColor(QPalette::Button, c);
    ui->minorGridLineColor->setPalette(p);

    // color line series
    chartChannel->getAxis()->setMinorGridLineColor(c);
}

void Dynamometer::DHistogramConfig::on_labelColor_clicked()
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (!chartChannel) return;

    QColorDialog cd;
    QColor c;
    c = cd.getColor(ui->labelColor->palette().color(QPalette::Button));
    if (c.spec() == QColor::Invalid) return;

    // color button
    QPalette p = ui->labelColor->palette();
    p.setColor(QPalette::Button, c);
    ui->labelColor->setPalette(p);

    // color line series
    chartChannel->getAxis()->setLabelsColor(c);
}

void Dynamometer::DHistogramConfig::on_labelFormat_textEdited(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());

    if (chartChannel)
    {
        QValueAxis *channelAxis = chartChannel->getAxis();

        if (channelAxis)
            channelAxis->setLabelFormat(arg1);
    }
}

void Dynamometer::DHistogramConfig::on_verticalAxis_currentIndexChanged(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());
    DChartChannel *verticalAxisChannel = h_display->getChartChannels().value(chartChannel->getHorizontalAxis());

    chartChannel->setVerticalAxis(arg1.toUtf8());

    if (verticalAxisChannel)
    {
        QValueAxis *axis = verticalAxisChannel->getAxis();
        if (axis) chartChannel->getLineSeries()->detachAxis(axis);
    }

    verticalAxisChannel = h_display->getChartChannels().value(arg1.toUtf8());

    if (verticalAxisChannel)
    {
        QValueAxis *axis = verticalAxisChannel->getAxis();
        if (axis) chartChannel->getLineSeries()->attachAxis(axis);
    }
}

void Dynamometer::DHistogramConfig::on_horizontalAxis_currentIndexChanged(const QString &arg1)
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());
    DChartChannel *horizontalAxisChannel = h_display->getChartChannels().value(chartChannel->getHorizontalAxis());

    chartChannel->setHorizontalAxis(arg1.toUtf8());

    if (horizontalAxisChannel)
    {
        QValueAxis *axis = horizontalAxisChannel->getAxis();
        if (axis) chartChannel->getLineSeries()->detachAxis(axis);
    }

    horizontalAxisChannel = h_display->getChartChannels().value(arg1.toUtf8());

    if (horizontalAxisChannel)
    {
        QValueAxis *axis = horizontalAxisChannel->getAxis();
        if (axis) chartChannel->getLineSeries()->attachAxis(axis);
    }
}

void Dynamometer::DHistogramConfig::on_deleteVerticalAxis_clicked()
{
    DChartChannel *chartChannel = h_display->getChartChannels().value(ui->currentChannel->currentText().toUtf8());
    DChartChannel *verticalAxisChannel = h_display->getChartChannels().value(chartChannel->getHorizontalAxis());
    // detach vertical axis
    if (verticalAxisChannel) chartChannel->getLineSeries()->detachAxis(verticalAxisChannel->getAxis());

    chartChannel->setVerticalAxis("");
    ui->verticalAxis->blockSignals(true);
    ui->verticalAxis->setCurrentIndex(-1);
    ui->verticalAxis->blockSignals(false);
}
}
