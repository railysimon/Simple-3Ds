#-------------------------------------------------
#
# Project created by QtCreator 2017-01-14T13:39:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3Ds
TEMPLATE = app

QT += opengl

SOURCES += main.cpp\
        window.cpp \
    view.cpp

HEADERS  += window.h \
    view.h \
    package.h
