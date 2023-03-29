TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += network
QT += core
QT += widgets


DEFINES += ZMQ_STATIC
LIBS += -L$$PWD/../lib -lzmq -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.cpp \
    dice.cpp

HEADERS += \
    dice.h
