TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    interfaz/interfaz.c \
    logica/logica.c \
    menu/menu.c

HEADERS += \
    interfaz/interfaz.h \
    logica/logica.h \
    menu/menu.h

