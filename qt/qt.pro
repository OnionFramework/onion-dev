TEMPLATE = app
TARGET = onion
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "../../onion/"
SOURCES += \
    ../../onion/onion/Random.cpp \
    ../main.cpp

HEADERS += \
    ../../onion/cops/functions/rv_functions.hpp \
    ../../onion/cops/mkp/mkp.hpp \
    ../../onion/cops/tsp/array/create_random.hpp \
    ../../onion/cops/tsp/array/tsp.hpp \
    ../../onion/cops/tsp/bitmatrix/tsp.hpp \
    ../../onion/onion/NonCopyable.hpp \
    ../../onion/onion/Random.hpp \
    ../../onion/onion/RandomEngine.hpp \
    ../../onion/onion/RandomLegacyC.hpp \
    ../../onion/onion/RandomSTL.hpp \
    ../../onion/onion/create.hpp \
    ../../onion/onion/local_search.hpp \
    ../../onion/onion/component.hpp \
    ../../onion/onion.hpp \
    ../test_rng.hpp


CONFIG(debug, debug|release) {
    DEFINES += "__DEBUG__"
}
CONFIG(release, debug|release) {
    macx | linux: QMAKE_CXXFLAGS += -O3
    DEFINES -= "__DEBUG__"
}


