#-------------------------------------------------
#
# Project created by QtCreator 2023-08-07T13:41:16
#
#-------------------------------------------------

QT       += core gui charts sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SHomeSystem
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

SOURCES += \
        main.cpp \
        widget.cpp \
    weatherwidget.cpp \
    tabwidget.cpp \
    datawidget.cpp \
    registerview.cpp \
    loginview.cpp \
    sensormodule.cpp \
    executor.cpp \
    device.cpp

HEADERS += \
        widget.h \
    weatherwidget.h \
    tabwidget.h \
    datawidget.h \
    registerview.h \
    loginview.h \
    sensormodule.h \
    executor.h \
    device.h

FORMS += \
        widget.ui \
    weatherwidget.ui \
    tabwidget.ui \
    datawidget.ui \
    registerview.ui \
    loginview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
