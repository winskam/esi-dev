include(../defaults.pri)

CONFIG += qt
QT+= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#you MUST include headers to subprojects, for instance like this
#"core" is not added here because it's already in defaults.pri

#INCLUDEPATH += $$PWD/../controllers

LIBS += -L../lib -llibmetier \

SOURCES += \
    hexacell.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    hexacell.h \
    mainwindow.h \
    point.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
