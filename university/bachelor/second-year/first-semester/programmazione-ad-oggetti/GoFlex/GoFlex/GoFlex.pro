QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_ICONS = GoFlex.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardio.cpp \
    controller.cpp \
    creaesercizio.cpp \
    crossfit.cpp \
    dialog.cpp \
    eseguiesercizi.cpp \
    esercizio.cpp \
    main.cpp \
    menus.cpp \
    model.cpp \
    monoesercizio.cpp \
    orario.cpp \
    riposo.cpp \
    riposoattivo.cpp \
    riposopassivo.cpp \
    screen.cpp \
    sollevamentopesi.cpp \
    view.cpp \
    widgetcreator.cpp

HEADERS += \
    cardio.h \
    controller.h \
    creaesercizio.h \
    crossfit.h \
    deepptr.h \
    dialog.h \
    dlist.h \
    eseguiesercizi.h \
    esercizio.h \
    menus.h \
    model.h \
    monoesercizio.h \
    orario.h \
    riposo.h \
    riposoattivo.h \
    riposopassivo.h \
    screen.h \
    sollevamentopesi.h \
    view.h \
    widgetcreator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
