TARGET = findfiles

QT += widgets

HEADERS       = window.h
SOURCES       = main.cpp \
                window.cpp

# install
target.path = /opt/xiaohai/bin
INSTALLS += target
