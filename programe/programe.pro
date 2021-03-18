greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia
QT += core
ICON = icons.icns
FORMS += \
    begin.ui \
    choose.ui \
    login.ui \
    mainwindow.ui

HEADERS += \
    begin.h \
    choose.h \
    login.h \
    mainwindow.h \
    star.h

SOURCES += \
    begin.cpp \
    choose.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    star.cpp

RESOURCES += \
    music.qrc
