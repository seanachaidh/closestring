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
    probleminstance.cpp \
    neighbourhood.cpp \
    pivotrule.cpp \
    initialsolution.cpp \
    constantinitialsolution.cpp \
    hammingneighbourhood.cpp \
    bestimprovement.cpp \
    firstimprovement.cpp

HEADERS += \
    ant.h \
    antcolony.h \
    probleminstance.h \
    neighbourhood.h \
    pivotrule.h \
    initialsolution.h \
    constantinitialsolution.h \
    hammingneighbourhood.h \
    bestimprovement.h \
    firstimprovement.h

DISTFILES += \
    createStat.sh
