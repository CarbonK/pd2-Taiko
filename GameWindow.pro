#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T20:39:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameWindow
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    note.cpp \
    result.cpp

HEADERS  += gamewindow.h \
    note.h \
    result.h

FORMS    += gamewindow.ui \
    result.ui

RESOURCES += \
    image.qrc
