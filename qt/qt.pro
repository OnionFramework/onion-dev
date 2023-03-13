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
    ../../onion/onion/Algorithm.hpp \
    ../../onion/onion/ComparissonOperator.hpp \
    ../../onion/onion/CreateOperator.hpp \
    ../../onion/onion/IdentifiedComponent.hpp \
    ../../onion/onion/LocalSearch.hpp \
    ../../onion/onion/NonCopyable.hpp \
    ../../onion/onion/ObjectiveFunction.hpp \
    ../../onion/onion/Random.hpp \
    ../../onion/onion/RandomEngine.hpp \
    ../../onion/onion/RandomLegacyC.hpp \
    ../../onion/onion/RandomSTL.hpp \
    ../../onion/onion.hpp \
    ../../onion/onion/SelectOperator.hpp \
    ../test_rng.hpp \
    ../../onion/onion/PerturbationOperator.hpp \
    ../../onion/onion/TypeTraits.hpp \
    ../../onion/onion/PerturbationParameterOperator.hpp


CONFIG(debug, debug|release) {
    DEFINES += "__DEBUG__"
}
CONFIG(release, debug|release) {
    macx | linux: QMAKE_CXXFLAGS += -O3
    DEFINES -= "__DEBUG__"
}


