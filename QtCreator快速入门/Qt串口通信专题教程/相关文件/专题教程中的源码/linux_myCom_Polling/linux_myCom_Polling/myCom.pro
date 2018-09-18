#-------------------------------------------------
#
# Project created by QtCreator 2010-07-16T11:13:12
#
#-------------------------------------------------

QT       += core gui

TARGET = myCom
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp

HEADERS  += widget.h \
    qextserialbase.h \
    posix_qextserialport.h

FORMS    += widget.ui
