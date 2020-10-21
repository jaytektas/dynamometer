#-------------------------------------------------
#
# Project created by QtCreator 2020-01-29T10:55:27
#
#-------------------------------------------------
#QMAKE_CC = gcc-9
#QMAKE_CXX = g++-9

QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dynamometer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += Channels \
                Channels/Expressions \
                Communications \
                Dash \
                Gauge \
                Chart

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Dash/gauge.cpp \
    Dash/dialgauge.cpp \
    Dash/lineargauge.cpp \
    Dash/lcdgauge.cpp \
    Dash/labelgauge.cpp \
    Channels/channel.cpp \
    Channels/channellist.cpp \
    Channels/Expressions/error.cpp \
    Channels/Expressions/functions.cpp \
    Channels/Expressions/parser.cpp \
    Channels/channeleditdialog.cpp \
    Communications/communications.cpp \
    Communications/connectiondialog.cpp \
    Communications/statuspacket.cpp \
    Dash/dashwidget.cpp \
    Chart/run.cpp \
    Chart/chartwidget.cpp \
    Chart/chartviewwidget.cpp \
    Chart/chartlegend.cpp \
    configuration.cpp \
    widgetconfig.cpp \
    widgetcontainer.cpp \
    Dash/histogramwidget.cpp \
    histogramconfig.cpp \
    Chart/chartchannel.cpp

HEADERS += \
    mainwindow.h \
    Dash/gauge.h \
    Dash/dialgauge.h \
    Dash/lineargauge.h \
    Dash/lcdgauge.h \
    Dash/labelgauge.h \
    Channels/channel.h \
    Channels/channellist.h \
    Channels/delegate.h \
    Channels/Expressions/error.h \
    Channels/Expressions/functions.h \
    Channels/Expressions/parser.h \
    Communications/communications.h \
    Communications/connectiondialog.h \
    Communications/statuspacket.h \
    Dash/dashwidget.h \
    Chart/run.h \
    Chart/chartwidget.h \
    Chart/chartviewwidget.h \
    Channels/channeleditdialog.h \
    configuration.h \
    filemagic.h \
    Chart/chartlegend.h \
    widgetcontainer.h \
    widgetconfig.h \
    Dash/histogramwidget.h \
    histogramconfig.h \
    Chart/chartchannel.h

FORMS += \
        mainwindow.ui \
    connectiondialog.ui \
    dashwidget.ui \
    chartwidget.ui \
    channeleditdialog.ui \
    configuration.ui \
    chartviewwidget.ui \
    widgetconfig.ui \
    histogramconfig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    dynamometer.qrc \
    Dash/gauge.qrc

SUBDIRS += \
