#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T21:11:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrackInfo+
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    prefix.cpp \
    about.cpp \
    donate.cpp

HEADERS  += mainwindow.h \
    prefix.h \
    about.h \
    donate.h

FORMS    += mainwindow.ui \
    prefix.ui \
    about.ui \
    donate.ui
