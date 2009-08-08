# -------------------------------------------------
# Project created by QtCreator 2009-07-30T16:20:43
# -------------------------------------------------
QT += network \
    webkit
TARGET = botapeha
TEMPLATE = app
SOURCES += src/captcha.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/symbol.cpp \
    include/fann/*c


HEADERS += src/captcha.h \
    src/mainwindow.h \
    src/symbol.h
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = ui
FORMS += ui/mainwindow.ui
INCLUDEPATH += include/fann/include
