TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

debug {
    DEFINES+=DEBUG
}

SOURCES += \
    ant.cpp \
    antcolony.cpp \
    main.cpp \
    probleminstance.cpp

HEADERS += \
    ant.h \
    antcolony.h \
    probleminstance.h
