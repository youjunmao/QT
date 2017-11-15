#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T14:22:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTcpfile
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    clientwidget.cpp

HEADERS  += widget.h \
    clientwidget.h

FORMS    += widget.ui \
    clientwidget.ui

CONFIG+=C++11
