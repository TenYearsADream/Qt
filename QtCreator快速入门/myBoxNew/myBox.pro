# -------------------------------------------------
# Project created by QtCreator 2009-11-22T16:08:56
# -------------------------------------------------
TARGET = myBox
TEMPLATE = app
SOURCES += main.cpp \
    mybox.cpp \
    gamearea.cpp \
    myitem.cpp \
    startdlg.cpp \
    myboxaudio.cpp
HEADERS += mybox.h \
    gamearea.h \
    myitem.h \
    startdlg.h \
    myboxaudio.h
FORMS += mybox.ui \
    startdlg.ui
RESOURCES += myph.qrc
RC_FILE += mybox.rc
QT += phonon
