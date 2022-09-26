include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier \

SOURCES += main.cpp \
    testboard.cpp \
    testgame.cpp \
    testmarble.cpp \
    testplayer.cpp \
    testposition.cpp

HEADERS += \
    catch.hpp \
    testgame.h
