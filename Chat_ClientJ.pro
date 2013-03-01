#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T10:44:47
#
#-------------------------------------------------

QT       += core gui network webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat_ClientJ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jugador.cpp \
    gamearea.cpp \
    clientconnection.cpp

HEADERS  += mainwindow.h \
    jugador.h \
    gamearea.h \
    clientconnection.h

FORMS    += mainwindow.ui

RESOURCES += \
    recursos.qrc
