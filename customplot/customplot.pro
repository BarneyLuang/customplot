#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T15:01:56
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customplot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot/qcustomplot.h

FORMS    += mainwindow.ui
