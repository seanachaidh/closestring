TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# With C++11 support
greaterThan(QT_MAJOR_VERSION, 4){
CONFIG += c++11
} else {
QMAKE_CXXFLAGS += -std=c++0x
}

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
