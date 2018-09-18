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
    win_qextserialport.cpp \
    qextserialbase.cpp

HEADERS  += widget.h \
    qextserialbase.h \
    win_qextserialport.h

FORMS    += widget.ui
