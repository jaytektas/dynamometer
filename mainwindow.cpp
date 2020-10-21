#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "communications.h"
#include "connectiondialog.h"
#include "channellist.h"
#include "dialgauge.h"
#include "chartviewwidget.h"
#include "dashwidget.h"
#include "channeleditdialog.h"
#include "configuration.h"
#include "filemagic.h"

#include <QRegExp>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>
#include <QCheckBox>

using namespace Dynamometer;
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCorner(Qt::Corner::TopLeftCorner, Qt::DockWidgetArea::LeftDockWidgetArea);
    setCorner(Qt::Corner::BottomLeftCorner, Qt::DockWidgetArea::LeftDockWidgetArea);
    setCorner(Qt::Corner::TopRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);
    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);

    tabifyDockWidget(ui->setupDock, ui->channelDock);
    tabifyDockWidget(ui->sessionDock, ui->fileDock);

    Channels->setParent(this);
    Comms->setParent(this);

    m_fileSystemModel = new QFileSystemModel(this);
    ui->fileTree->setModel(m_fileSystemModel);
    ui->fileTree->setAnimated(false);
    ui->fileTree->setIndentation(20);
    ui->fileTree->setSortingEnabled(true);
    ui->fileTree->setColumnWidth(0, ui->fileTree->width() / 2);

    QRegExp regExp("^[a-zA-Z_]+[a-zA-Z_0-9]*$");
    QValidator *validator = new QRegExpValidator(regExp, this);
    ui->channelLineEdit->setValidator(validator);

    QObject::connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::tabCloseRequested);
    QObject::connect(Comms, &DCommunications::connected, this, &MainWindow::connected);
    QObject::connect(Channels, &DChannelList::channelsChanged, this, &MainWindow::channelsChanged);
    QObject::connect(Configuration, &DConfiguration::configurationChanged, this, &MainWindow::configurationChanged);
    configurationChanged();

    ui->sessionTableWidget->setColumnCount(5);
    ui->sessionTableWidget->setHorizontalHeaderLabels({"", "", "Time Date", "Name", "Comment"});
    ui->sessionTableWidget->horizontalHeader()->setMinimumWidth(2);
    ui->sessionTableWidget->setColumnWidth(0, 10);
    ui->sessionTableWidget->setColumnWidth(1, 10);
    ui->sessionTableWidget->setColumnWidth(2, 200);
    ui->sessionTableWidget->setColumnWidth(3, 200);
    ui->sessionTableWidget->setColumnWidth(4, 400);

    ui->sessionTableWidget->verticalHeader()->setDefaultSectionSize(20);

    ui->sessionTableWidget->viewport()->setAcceptDrops(true);
    ui->sessionTableWidget->setDropIndicatorShown(true);
    m_fileSystemModel->setReadOnly(false);
}

MainWindow::~MainWindow()
{  
    disconnect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::tabCloseRequested);
    disconnect(Comms, &DCommunications::connected, this, &MainWindow::connected);
    disconnect(Channels, &DChannelList::channelsChanged, this, &MainWindow::channelsChanged);
    disconnect(Configuration, &DConfiguration::configurationChanged, this, &MainWindow::configurationChanged);
    if (m_fileSystemModel) delete m_fileSystemModel;
    delete ui;
}

void MainWindow::configurationChanged()
{
    m_fileSystemModel->setRootPath(Configuration->getWorkspacePath());
    ui->fileTree->setRootIndex(m_fileSystemModel->index(Configuration->getWorkspacePath()));
    channelsChanged();
}

void MainWindow::connected(bool connected)
{
    if (connected)
    {
        ui->actionConnect->setCheckable(true);
        ui->actionConnect->setChecked(true);
        setStatus("Connected");
    }
    else
    {
        ui->actionConnect->setCheckable(false);
        ui->actionConnect->setChecked(false);
        setStatus(("Disconnected"));
    }
}

void MainWindow::on_actionConnect_triggered()
{
    Comms->setTimeout(1000);

    if(!ui->actionConnect->isCheckable())
    {
        QSettings settings;

        setStatus("Connecting...");
        settings.beginGroup("Connection");

        Comms->setPortName(settings.value("PortName").toString());

        switch (settings.value("BaudRate", 0).toInt()) {
        case 0:
            Comms->setBaud(QSerialPort::Baud1200);
            break;
        case 1:
            Comms->setBaud(QSerialPort::Baud2400);
            break;
        case 2:
            Comms->setBaud(QSerialPort::Baud4800);
            break;
        case 3:
            Comms->setBaud(QSerialPort::Baud9600);
            break;
        case 4:
            Comms->setBaud(QSerialPort::Baud19200);
            break;
        case 5:
            Comms->setBaud(QSerialPort::Baud38400);
            break;
        case 6:
            Comms->setBaud(QSerialPort::Baud57600);
            break;
        case 7:
            Comms->setBaud(QSerialPort::Baud115200);
            break;
        }

        switch (settings.value("DataBits", 3).toInt()) {
        case 0:
            Comms->setDataBits(QSerialPort::Data5);
            break;
        case 1:
            Comms->setDataBits(QSerialPort::Data6);
            break;
        case 2:
            Comms->setDataBits(QSerialPort::Data7);
            break;
        case 3:
            Comms->setDataBits(QSerialPort::Data8);
            break;
        }

        switch (settings.value("Parity", 0).toInt()) {
        case 0:
            Comms->setParity(QSerialPort::NoParity);
            break;
        case 1:
            Comms->setParity(QSerialPort::EvenParity);
            break;
        case 2:
            Comms->setParity(QSerialPort::OddParity);
            break;
        case 3:
            Comms->setParity(QSerialPort::MarkParity);
            break;
        case 4:
            Comms->setParity(QSerialPort::SpaceParity);
            break;
        }

        switch (settings.value("StopBits", 0).toInt()) {
        case 0:
            Comms->setStopBits(QSerialPort::OneStop);
            break;
#ifdef Q_OS_WIN
        case 1:
            Comms->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 2:
            Comms->setStopBits(QSerialPort::TwoStop);
            break;
#else
        case 1:
            Comms->setStopBits(QSerialPort::TwoStop);
            break;
#endif
        }

        switch (settings.value("FlowControl", 0).toInt()) {
        case 0:
            Comms->setFlowControl(QSerialPort::NoFlowControl);
            break;
        case 1:
            Comms->setFlowControl(QSerialPort::HardwareControl);
            break;
        case 2:
            Comms->setFlowControl(QSerialPort::SoftwareControl);
            break;
        }

        Comms->openSerial();
    }
    else
    {
        setStatus(QString("Disconnecting..."));
        Comms->closeSerial();
    }
}

void MainWindow::on_actionConnectionSettings_triggered()
{
    cd.show();
}

void MainWindow::on_actionNewChartView_triggered()
{
    QWidget *chartTabView = new QWidget();
    chartTabView->setProperty("type", "chartview");
    chartTabView->setObjectName(QString::fromUtf8("Chart Tab"));
    chartTabView->setStyleSheet(QString::fromUtf8(""));

    DChartViewWidget *chartViewWidget = new DChartViewWidget(chartTabView);
    chartViewWidget->setTabIndex(m_index++);
    chartViewWidget->setDocked(true);
    connect(this, &MainWindow::selectedRunsChanged, chartViewWidget, &DChartViewWidget::selectedRunsChanged);

    chartTabView->setProperty("index", chartViewWidget->getTabIndex());

    QHBoxLayout *Layout = new QHBoxLayout(chartTabView);
    Layout->setObjectName(QString::fromUtf8("Layout"));
    Layout->setContentsMargins(0, 0, 0, 0);
    Layout->setSpacing(0);

    chartTabView->setLayout(Layout);
    Layout->addWidget(chartViewWidget);

    m_sessions.push_back(chartViewWidget);

    ui->tabWidget->addTab(chartTabView, "Chart View");
    ui->tabWidget->setCurrentWidget(chartTabView);
}

void MainWindow::tabCloseRequested(int tabIndex)
{
    QWidget *tab = ui->tabWidget->widget(tabIndex);

    if (tab->property("type") == "chartview")
    {
        int index = tab->property("index").toInt();

        list<DChartViewWidget *>::iterator sw;

        for (sw = m_sessions.begin(); sw != m_sessions.end(); sw++)
            if ((*sw)->getDocked() && (*sw)->getTabIndex() == index)
            {
                if ((*sw)->close())
                {
                    ui->tabWidget->removeTab(tabIndex);
                    sw = m_sessions.erase(sw);
                }
            }
    }

    if (tab->property("type") == "dash")
    {
        int index = tab->property("index").toInt();

        list<DDashWidget*>::iterator dw;

        for (dw = m_dashs.begin(); dw != m_dashs.end(); dw++)
        {
            if ((*dw)->getDocked() && (*dw)->getIndex() == index)
            {
                if ((*dw)->close())
                {
                    ui->tabWidget->removeTab(tabIndex);
                    dw = m_dashs.erase(dw);
                }
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *closeEvent)
{
    if (Channels->getChanged())
    {
        Channels->save(Configuration->getChannelFilename());
    }

    if (Configuration->getChanged())
    {
        QSettings s;
        s.beginGroup("configuration");
        QString fp = s.value("filename").toString();
        s.endGroup();
        Configuration->save(fp);
    }
    closeEvent->accept();
}

void MainWindow::on_actionNewDash_triggered()
{
    DDashWidget *newDashWidget = new DDashWidget();
    newDashWidget->setWindowTitle("New Dash");
    newDashWidget->setName("New Dash");
    newDashWidget->setDocked(true);

    newDashWidget->setProperty("type", "dash");
    newDashWidget->setIndex(m_index++);

    newDashWidget->setProperty("index", newDashWidget->getIndex());

    m_dashs.push_back(newDashWidget);

    ui->tabWidget->addTab(newDashWidget, newDashWidget->getName());
    ui->tabWidget->setCurrentWidget(newDashWidget);
    QObject::connect(newDashWidget, &DDashWidget::undock, this, &MainWindow::undock);
    QObject::connect(newDashWidget, &DDashWidget::dock, this, &MainWindow::dock);
}

void MainWindow::dock()
{
    DDashWidget *dashWidget = dynamic_cast<DDashWidget *>(sender());

    if (dashWidget)
    {
        ui->tabWidget->addTab(dashWidget, dashWidget->getName());
        ui->tabWidget->setCurrentWidget(dashWidget);
    }
}

void MainWindow::undock()
{
    DDashWidget *dashWidget = dynamic_cast<DDashWidget *>(sender());

    if (dashWidget)
    {
        dashWidget->setParent(nullptr);
        dashWidget->show();
    }
}

void MainWindow::channelsChanged()
{
    ui->channelListWidget->clear();

    QMap<QByteArray, DChannel *>::iterator channel;
    for (channel = Channels->c_channels.begin(); channel != Channels->c_channels.end(); channel++)
        ui->channelListWidget->addItem((*channel)->getName());
}

void MainWindow::on_channelListWidget_itemClicked(QListWidgetItem *item)
{
    ui->channelLineEdit->setText(item->text());
}

void MainWindow::on_channelListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    DChannelEditDialog ced;
    if (ced.setChannelName(item->text().toUtf8().data()))
        ced.exec();
}

void MainWindow::on_channelDeletePushButton_clicked()
{
    if (!ui->channelLineEdit->text().isEmpty())
        Channels->deleteChannel(ui->channelLineEdit->text().toUtf8().data(), false);
}

void MainWindow::on_channelAddPushButton_clicked()
{
    if (ui->channelLineEdit->text().isEmpty()) return;
    Channels->addChannel(ui->channelLineEdit->text().toUtf8().data(), DChannel::USER, "", DChannel::DATA_TYPE::NaN, 0, false);
}

void MainWindow::on_fileTree_doubleClicked(const QModelIndex &)
{
    QModelIndexList sl = ui->fileTree->selectionModel()->selectedIndexes();
    QModelIndexList::iterator mi;

    for (mi = sl.begin(); mi != sl.end(); mi++)
        if(mi->column() == 0)
            loadFileByMagic(m_fileSystemModel->filePath(*mi));
}

void MainWindow::on_actionConfiguration_triggered()
{
    Configuration->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog fd;
    fd.setWindowTitle("Open file");
    fd.setFileMode(QFileDialog::FileMode::ExistingFiles);
    fd.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);

    if (fd.exec())
    {
        QStringList filenames = fd.selectedFiles();
        for (QString fn : filenames)
            loadFileByMagic(fn);
    }
}

bool MainWindow::loadFileByMagic(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        quint32 magic;
        in >> magic;
        file.close();

        switch (magic)
        {
            case MAGIC::CONFIGURATION:
                if (Configuration->load(filename))
                {
                    setStatus(QString("%1 sucessfully loaded").arg(filename));
                    configurationChanged();
                    return true;
                }
                else setError(QString("failed to load configuration %1 %2").arg(filename, Configuration->getError()));
                break;

            case MAGIC::RUN:
                if (loadRun(filename))
                {
                    setStatus(QString("%1 sucessfully loaded").arg(filename));
                    emit selectedRunsChanged();
                    return true;
                }
                else setError(QString("failed to load run %1 %2").arg(filename, Configuration->getError()));
                break;

            case MAGIC::CHANNEL:
                break;

            default:
                setError(QString("unknown file format %1").arg(filename));
                break;
        }
    }
    return false;
}

void MainWindow::setStatus(QString status)
{
    ui->statusBar->showMessage(status, 5000);
}

void MainWindow::setError(QString error)
{
    setStatus(error);
    m_error = error;
    QMessageBox::information(this, "Error", error);
}

bool MainWindow::loadRun(QString filename)
{
    DRun *nr = new DRun;

    if (nr->load(filename))
    {
        if (!Runs.contains(nr->getDateTime()))
        {
            Runs.insert(nr->getDateTime(), nr);
            ui->sessionTableWidget->setSortingEnabled(false);
            ui->sessionTableWidget->insertRow(0);

            // the delete push button
            QPushButton *pb = new QPushButton;
            pb->setGeometry(0,0,24,24);
            pb->setMaximumSize(24, 24);
            pb->setIcon(QIcon(":/icons/cross.png"));
            pb->setProperty("run", nr->getDateTime());
            ui->sessionTableWidget->setCellWidget(0, DRun::COLUMNS::DELETE, pb);
            QObject::connect(pb, &QPushButton::clicked, this, &MainWindow::deleteRun);

            // checkbox
            QWidget *w = new QWidget;
            QCheckBox *cb = new QCheckBox(w);
            QHBoxLayout *lo = new QHBoxLayout(cb);
            w->setLayout(lo);
            lo->addWidget(cb, 0, Qt::AlignCenter);
            lo->setAlignment(Qt::AlignCenter);
            lo->setContentsMargins(0,0,0,0);
            cb->setCheckState(Qt::CheckState::Checked);
            nr->setSelected(true);
            cb->setProperty("run", nr->getDateTime());
            ui->sessionTableWidget->setCellWidget(0, DRun::COLUMNS::SELECT, w);
            QObject::connect(cb, &QCheckBox::stateChanged, this, &MainWindow::runCheckBoxStateChanged);

            QTableWidgetItem *twi = new QTableWidgetItem(nr->getDateTime().toString("dd.MM.yy hh:mm:ss.zzz"));
            twi->setData(Qt::UserRole, nr->getDateTime());
            // insert into table
            ui->sessionTableWidget->setItem(0, DRun::COLUMNS::DATETIME, twi);
            ui->sessionTableWidget->setItem(0, DRun::COLUMNS::NAME, new QTableWidgetItem(nr->getName()));
            ui->sessionTableWidget->setItem(0, DRun::COLUMNS::COMMENT, new QTableWidgetItem(nr->getComment()));
            ui->sessionTableWidget->setSortingEnabled(true);
            return true;
        }
    } else delete nr;
    return false;
}

void MainWindow::deleteRun()
{
    QPushButton *pb = dynamic_cast<QPushButton *>(sender());

    if (!pb) return; // where are we? it's life jim but not as we know it.

    QDateTime dt = pb->property("run").value<QDateTime>();

    if (Runs.contains(dt))
    {
        DRun *run = Runs.value(dt);
        Runs.remove(dt);
        delete run;
    }

    // remove from session table

    QModelIndexList il = ui->sessionTableWidget->model()->match(ui->sessionTableWidget->model()->index(0, DRun::COLUMNS::DATETIME), Qt::UserRole, dt);

    foreach (QModelIndex i, il)
        ui->sessionTableWidget->removeRow(i.row());

    emit selectedRunsChanged();
}

void MainWindow::runCheckBoxStateChanged(int state)
{
    QCheckBox *cb = dynamic_cast<QCheckBox *>(sender());

    if (!cb) return;

    QDateTime dt = cb->property("run").value<QDateTime>();
    DRun *run = Runs.value(dt);
    if (run)
    {
        if (state == Qt::Checked)
            run->setSelected(true);
        else
            run->setSelected(false);
    }

    emit selectedRunsChanged();
}

