#-------------------------------------------------
#
# Project created by QtCreator 2017-10-21T16:49:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MouseEvent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp \
    mypushbutton.cpp

HEADERS  += widget.h \
    mylabel.h \
    mypushbutton.h

FORMS    += widget.ui

CONFIG +=C++11
