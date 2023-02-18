TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "../../onion/"
SOURCES += \
    ../main.cpp

DISTFILES += \
    ../../onion/onion.png \
    ../../onion/LICENSE.md \
    ../../onion/README.md


HEADERS += \
    ../../onion/cops/functions/rv_functions.hpp \
    ../../onion/cops/mkp/mkp.hpp \
    ../../onion/cops/tsp/array/create_random.hpp \
    ../../onion/cops/tsp/array/tsp.hpp \
    ../../onion/cops/tsp/bitmatrix/tsp.hpp \
    ../../onion/onion/create.hpp \
    ../../onion/onion/local_search.hpp \
    ../../onion/onion/non_copyable.hpp \
    ../../onion/onion.hpp \
    ../../onion/onionfw.hpp \
    ../../onion/onion/component.hpp


CONFIG(debug, debug|release) {
    DEFINES += "__DEBUG__"
}
CONFIG(release, debug|release) {
    macx | linux: QMAKE_CXXFLAGS += -O3
    DEFINES -= "__DEBUG__"
}


