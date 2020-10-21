/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnectionSettings;
    QAction *actionExit;
    QAction *actionConnect;
    QAction *actionChannelEditor;
    QAction *actionNewChartView;
    QAction *actionNewDash;
    QAction *actionConfiguration;
    QAction *actionOpen;
    QAction *actionSave_Configuration_As;
    QAction *actionSave_Channels_As;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuConnection;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *channelDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *channelLineEdit;
    QPushButton *channelAddPushButton;
    QPushButton *channelDeletePushButton;
    QListWidget *channelListWidget;
    QDockWidget *setupDock;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QDockWidget *sessionDock;
    QWidget *dockWidgetContents_4;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *sessionTableWidget;
    QDockWidget *fileDock;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_5;
    QTreeView *fileTree;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 727);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionConnectionSettings = new QAction(MainWindow);
        actionConnectionSettings->setObjectName(QString::fromUtf8("actionConnectionSettings"));
        actionConnectionSettings->setChecked(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionConnect->setCheckable(false);
        actionConnect->setChecked(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icons/connect.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConnect->setIcon(icon);
        actionChannelEditor = new QAction(MainWindow);
        actionChannelEditor->setObjectName(QString::fromUtf8("actionChannelEditor"));
        actionChannelEditor->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/channels.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChannelEditor->setIcon(icon1);
        actionNewChartView = new QAction(MainWindow);
        actionNewChartView->setObjectName(QString::fromUtf8("actionNewChartView"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/session.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewChartView->setIcon(icon2);
        actionNewDash = new QAction(MainWindow);
        actionNewDash->setObjectName(QString::fromUtf8("actionNewDash"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/dash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewDash->setIcon(icon3);
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfiguration->setIcon(icon4);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_Configuration_As = new QAction(MainWindow);
        actionSave_Configuration_As->setObjectName(QString::fromUtf8("actionSave_Configuration_As"));
        actionSave_Channels_As = new QAction(MainWindow);
        actionSave_Channels_As->setObjectName(QString::fromUtf8("actionSave_Channels_As"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setFocusPolicy(Qt::ClickFocus);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QString::fromUtf8("menuConnection"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setIconSize(QSize(24, 24));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);
        channelDock = new QDockWidget(MainWindow);
        channelDock->setObjectName(QString::fromUtf8("channelDock"));
        channelDock->setWindowIcon(icon1);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        channelLineEdit = new QLineEdit(dockWidgetContents);
        channelLineEdit->setObjectName(QString::fromUtf8("channelLineEdit"));
        channelLineEdit->setMaxLength(60);

        horizontalLayout->addWidget(channelLineEdit);

        channelAddPushButton = new QPushButton(dockWidgetContents);
        channelAddPushButton->setObjectName(QString::fromUtf8("channelAddPushButton"));
        channelAddPushButton->setMaximumSize(QSize(24, 24));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/chart_curve_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        channelAddPushButton->setIcon(icon5);

        horizontalLayout->addWidget(channelAddPushButton);

        channelDeletePushButton = new QPushButton(dockWidgetContents);
        channelDeletePushButton->setObjectName(QString::fromUtf8("channelDeletePushButton"));
        channelDeletePushButton->setMaximumSize(QSize(24, 24));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/chart_curve_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        channelDeletePushButton->setIcon(icon6);

        horizontalLayout->addWidget(channelDeletePushButton);


        verticalLayout->addLayout(horizontalLayout);

        channelListWidget = new QListWidget(dockWidgetContents);
        channelListWidget->setObjectName(QString::fromUtf8("channelListWidget"));
        channelListWidget->setDragEnabled(true);

        verticalLayout->addWidget(channelListWidget);


        verticalLayout_4->addLayout(verticalLayout);

        channelDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), channelDock);
        setupDock = new QDockWidget(MainWindow);
        setupDock->setObjectName(QString::fromUtf8("setupDock"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(dockWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(dockWidgetContents_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(dockWidgetContents_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        setupDock->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), setupDock);
        sessionDock = new QDockWidget(MainWindow);
        sessionDock->setObjectName(QString::fromUtf8("sessionDock"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        sessionTableWidget = new QTableWidget(dockWidgetContents_4);
        sessionTableWidget->setObjectName(QString::fromUtf8("sessionTableWidget"));
        sessionTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        sessionTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        sessionTableWidget->setSortingEnabled(true);
        sessionTableWidget->horizontalHeader()->setMinimumSectionSize(24);
        sessionTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        sessionTableWidget->verticalHeader()->setMinimumSectionSize(24);
        sessionTableWidget->verticalHeader()->setDefaultSectionSize(24);

        horizontalLayout_2->addWidget(sessionTableWidget);

        sessionDock->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), sessionDock);
        fileDock = new QDockWidget(MainWindow);
        fileDock->setObjectName(QString::fromUtf8("fileDock"));
        fileDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        fileTree = new QTreeView(dockWidgetContents_5);
        fileTree->setObjectName(QString::fromUtf8("fileTree"));
        fileTree->setAcceptDrops(true);
        fileTree->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        fileTree->setDragEnabled(true);
        fileTree->setDragDropMode(QAbstractItemView::InternalMove);
        fileTree->setDefaultDropAction(Qt::MoveAction);
        fileTree->setSelectionMode(QAbstractItemView::SingleSelection);
        fileTree->setSelectionBehavior(QAbstractItemView::SelectRows);
        fileTree->setSortingEnabled(true);
        fileTree->setAnimated(false);
        fileTree->setExpandsOnDoubleClick(true);

        verticalLayout_5->addWidget(fileTree);

        fileDock->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), fileDock);
        QWidget::setTabOrder(tabWidget, channelLineEdit);
        QWidget::setTabOrder(channelLineEdit, channelAddPushButton);
        QWidget::setTabOrder(channelAddPushButton, channelDeletePushButton);
        QWidget::setTabOrder(channelDeletePushButton, channelListWidget);
        QWidget::setTabOrder(channelListWidget, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConnection->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Configuration_As);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Channels_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuConnection->addAction(actionConnectionSettings);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionNewChartView);
        mainToolBar->addAction(actionNewDash);
        mainToolBar->addAction(actionChannelEditor);
        mainToolBar->addAction(actionConfiguration);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dynamometer by JayTek", nullptr));
        actionConnectionSettings->setText(QApplication::translate("MainWindow", "Connection Settings", nullptr));
#ifndef QT_NO_STATUSTIP
        actionConnectionSettings->setStatusTip(QApplication::translate("MainWindow", "connect to dynamometer", nullptr));
#endif // QT_NO_STATUSTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Quit the application", nullptr));
#endif // QT_NO_TOOLTIP
        actionConnect->setText(QApplication::translate("MainWindow", "Toggle Connection", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "toggle connection to the dynamometer", nullptr));
#endif // QT_NO_TOOLTIP
        actionChannelEditor->setText(QApplication::translate("MainWindow", "Edit Channels...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionChannelEditor->setToolTip(QApplication::translate("MainWindow", "open the channel editor", nullptr));
#endif // QT_NO_TOOLTIP
        actionNewChartView->setText(QApplication::translate("MainWindow", "New...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewChartView->setToolTip(QApplication::translate("MainWindow", "Create new graph view", nullptr));
#endif // QT_NO_TOOLTIP
        actionNewDash->setText(QApplication::translate("MainWindow", "New...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewDash->setToolTip(QApplication::translate("MainWindow", "Create a new dash", nullptr));
#endif // QT_NO_TOOLTIP
        actionConfiguration->setText(QApplication::translate("MainWindow", "Configuration", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConfiguration->setToolTip(QApplication::translate("MainWindow", "Configure Dynamometer", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
        actionSave_Configuration_As->setText(QApplication::translate("MainWindow", "Save Configuration As...", nullptr));
        actionSave_Channels_As->setText(QApplication::translate("MainWindow", "Save Channels As...", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuConnection->setTitle(QApplication::translate("MainWindow", "Connection", nullptr));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Tool Bar", nullptr));
        channelDock->setWindowTitle(QApplication::translate("MainWindow", "Channels", nullptr));
        channelLineEdit->setInputMask(QString());
        channelAddPushButton->setText(QString());
        channelDeletePushButton->setText(QString());
        setupDock->setWindowTitle(QApplication::translate("MainWindow", "Setup", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "RPM", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Brake", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Auto Run", nullptr));
        sessionDock->setWindowTitle(QApplication::translate("MainWindow", "Session", nullptr));
        fileDock->setWindowTitle(QApplication::translate("MainWindow", "Files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
