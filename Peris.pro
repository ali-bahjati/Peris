#-------------------------------------------------
#
# Project created by QtCreator 2013-01-05T00:15:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Peris
TEMPLATE = app


SOURCES += main.cpp\
        drawingform.cpp \
    drawingarea.cpp \
    point.cpp \
    scale.cpp \
    linepoints.cpp \
    segmentpoints.cpp \
    database.cpp

HEADERS  += drawingform.h \
    drawingarea.h \
    point.h \
    scale.h \
    linepoints.h \
    segmentpoints.h \
    database.h

FORMS    += drawingform.ui
