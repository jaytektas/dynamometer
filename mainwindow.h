#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connectiondialog.h"
#include "chartviewwidget.h"
#include "dashwidget.h"

#include <QTimer>
#include <QMainWindow>
#include <QAction>
#include <QFileSystemModel>
#include <QTableWidgetItem>
#include <QStatusBar>

using namespace std;
using namespace Dynamometer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setError(QString error);
    QString getError() const { return m_error; }

    void setStatus(QString status);

signals:
    void selectedRunsChanged();

public slots:
    void connected(bool connected);
    void channelsChanged();
    void configurationChanged();

protected:
    bool loadFileByMagic(QString filename);

    void sessionTableUpdate();
    bool loadRun(QString filename);

private slots:
    void deleteRun();
    void runCheckBoxStateChanged(int state);
    void on_actionConnect_triggered();
    void on_actionConnectionSettings_triggered();
    void on_actionNewChartView_triggered();
    void tabCloseRequested(int tabIndex);
    void undock();
    void dock();

    void on_actionNewDash_triggered();

    void on_channelListWidget_itemClicked(QListWidgetItem *item);

    void on_channelListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_channelDeletePushButton_clicked();

    void on_channelAddPushButton_clicked();

    void on_fileTree_doubleClicked(const QModelIndex &index);

    void on_actionConfiguration_triggered();

    void on_actionOpen_triggered();

private:
    void closeEvent(QCloseEvent *closeEvent);

    Ui::MainWindow *ui;
    QTimer m_statusTimer;
    list<DChartViewWidget *> m_sessions;
    list<DDashWidget *> m_dashs;
    ConnectionDialog cd;
    QFileSystemModel  *m_fileSystemModel = nullptr;

    int m_counter = 0;
    bool m_connected = false;
    int m_index = 0;
    QString m_error;
};

#endif // MAINWINDOW_H
