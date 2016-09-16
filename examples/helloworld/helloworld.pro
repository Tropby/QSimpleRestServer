QT += core
QT -= gui

TARGET = helloworld
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    helloworldlistener.cpp

include(../../REST.pri)

HEADERS += \
    helloworldlistener.h

