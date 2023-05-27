TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

DEFINES += ZMQ_STATIC
LIBS += -L$$PWD/../lib -lzmq -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.cpp \
    calculate.cpp \
    data.cpp \
    send.cpp

HEADERS += \
    calculate.h \
    data.h \
    send.h
