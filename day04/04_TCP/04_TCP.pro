#-------------------------------------------------
#
# Project created by QtCreator 2017-11-08T14:05:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04_TCP
TEMPLATE = app


SOURCES += main.cpp\
        widgetserver.cpp \
    clicentwidget.cpp

HEADERS  += widgetserver.h \
    clicentwidget.h

FORMS    += widgetserver.ui \
    clicentwidget.ui

CONFIG+=C++11
