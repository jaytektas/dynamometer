#include "widgetconfig.h"
#include "ui_widgetconfig.h"

#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QColorDialog>
#include <QFontDialog>

namespace Dynamometer
{
DWidgetConfig::DWidgetConfig(QWidget *parent, QWidget *display) : QDialog(parent), ui(new Ui::DWidgetConfig)
{
    ui->setupUi(this);
    show();
    g_display = display;
    display->setParent(ui->frame);
    display->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
    display->setGeometry(0,0,100,100);
    display->show();

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({ "Property", "Value" });
    ui->tableWidget->setColumnWidth(0, 300);

    const QMetaObject *mo = parent->metaObject();
    int r = 0;
    for (int i = 0; i < mo->propertyCount(); i++)
        if (mo->property(i).isUser() && mo->property(i).isWritable())
        {
            display->setProperty(mo->property(i).name(), mo->property(i).read(parent));
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
                    connect(pb, SIGNAL(clicked()), this, SLOT(fontButton()));
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
                    connect(pb, SIGNAL(clicked()), this, SLOT(colorButton()));
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
                    connect(cb, SIGNAL(clicked()), this, SLOT(checkBox()));
                }
                break;

                case QMetaType::Int:
                case QMetaType::Double:
                {
                    QLineEdit *le = new QLineEdit(QString::number(mo->property(i).read(parent).value<qreal>()));
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, SIGNAL(textEdited(const QString&)), this, SLOT(lineEdit(const QString&)));
                }
                break;

                case QMetaType::QByteArray:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QByteArray>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, SIGNAL(textEdited(const QString&)), this, SLOT(lineEdit(const QString&)));
                }
                break;

                case QMetaType::QString:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QString>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, SIGNAL(textEdited(const QString&)), this, SLOT(lineEdit(const QString&)));
                }
                break;

                case QMetaType::Char:
                {
                    QLineEdit *le = new QLineEdit(mo->property(i).read(parent).value<QString>());
                    le->setProperty("property", mo->property(i).name());
                    ui->tableWidget->setCellWidget(r, 1, le);
                    connect(le, SIGNAL(textEdited(const QString&)), this, SLOT(lineEdit(const QString&)));
                }
                break;

            default:
                break;
            }
        r++;
        }
}

void DWidgetConfig::lineEdit(const QString &)
{
    QLineEdit *le = dynamic_cast<QLineEdit *>(sender());
    if (!le) return;
    QString name = le->property("property").toString();

    switch(static_cast<QMetaType::Type>(g_display->property(name.toUtf8().constData()).type()))
    {
        case QMetaType::Int:
            g_display->setProperty(name.toUtf8().constData(), le->text().toInt());
        break;

        case QMetaType::Double:
            g_display->setProperty(name.toUtf8().constData(), le->text().toDouble());
        break;

        case QMetaType::QByteArray:
            g_display->setProperty(name.toUtf8().constData(), le->text().toUtf8().constData());
            break;

        case QMetaType::QString:
            g_display->setProperty(name.toUtf8().constData(), le->text());
            break;

        case QMetaType::Char:
            g_display->setProperty(name.toUtf8().constData(), le->text().toUtf8().data()[0]);
            break;

        default:
            break;
    }
    DGauge *g = dynamic_cast<DGauge*>(g_display);
    if (g) g->refresh();
}

void DWidgetConfig::checkBox()
{
    QCheckBox *cb = dynamic_cast<QCheckBox *>(sender());
    if (!cb) return;
    bool state;

    if (cb->checkState() == Qt::CheckState::Checked)
        state = true;
    else state = false;

    QString name = cb->property("property").toString();
    g_display->setProperty(name.toUtf8().constData(), state);
    DGauge *g = dynamic_cast<DGauge*>(g_display);
    if (g) g->refresh();
}

void DWidgetConfig::colorButton()
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
    g_display->setProperty(name.toUtf8().constData(), c);
    DGauge *g = dynamic_cast<DGauge*>(g_display);
    if (g) g->refresh();
}

void DWidgetConfig::fontButton()
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
        g_display->setProperty(name.toUtf8().constData(), nf);
    }
    DGauge *g = dynamic_cast<DGauge*>(g_display);
    if (g) g->refresh();
}

DWidgetConfig::~DWidgetConfig()
{
    delete ui;
}

void DWidgetConfig::on_buttonBox_accepted()
{
    // copy the display gauge settings back to us
    const QMetaObject *mo = g_display->metaObject();

    for (int i = 0; i < mo->propertyCount(); i++)
        if (mo->property(i).isUser() && mo->property(i).isWritable())
           parent()->setProperty(mo->property(i).name(), mo->property(i).read(g_display));
}
}
