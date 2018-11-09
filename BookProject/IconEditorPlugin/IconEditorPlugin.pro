TEMPLATE = lib

QT += widgets designer


HEADERS += \
    iconeditorplugin.h \
    ../IconEditor/iconeditor.h

SOURCES += \
    iconeditorplugin.cpp \
    ../IconEditor/iconeditor.cpp

RESOURCES += \
    resources.qrc


DESTDIR = $${QT_INSTALL_PLUGINS}/designer
