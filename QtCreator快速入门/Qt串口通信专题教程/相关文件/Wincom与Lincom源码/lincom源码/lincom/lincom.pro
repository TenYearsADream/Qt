#-------------------------------------------------
#
# Project created by QtCreator 2010-07-15T18:29:26
#
#-------------------------------------------------

QT       += core gui

TARGET = lincom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    qextserialbase.h \
    posix_qextserialport.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

OTHER_FILES +=

RESOURCES += \
    src.qrc
RC_FILE += myico.rc
