TEMPLATE = app
TARGET = onion
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "../../onion/"
SOURCES += \
    ../main.cpp \
    ../../onion/Random.cpp

HEADERS += \
    ../../onion/cops/functions/rv_functions.hpp \
    ../../onion/cops/mkp/mkp.hpp \
    ../../onion/cops/tsp/array/create_random.hpp \
    ../../onion/cops/tsp/array/tsp.hpp \
    ../../onion/cops/tsp/bitmatrix/tsp.hpp \
    ../test_rng.hpp \
    ../../onion/Algorithm.hpp \
    ../../onion/ComparissonOperator.hpp \
    ../../onion/CreateOperator.hpp \
    ../../onion/LocalSearch.hpp \
    ../../onion/NonCopyable.hpp \
    ../../onion/ObjectiveFunction.hpp \
    ../../onion/PerturbationOperator.hpp \
    ../../onion/Random.hpp \
    ../../onion/RandomEngine.hpp \
    ../../onion/RandomLegacyC.hpp \
    ../../onion/RandomSTL.hpp \
    ../../onion/SelectOperator.hpp \
    ../../onion/TypeTraits.hpp \
    ../../onion/ComponentID.hpp \
    ../../onion/ParameterOperator.hpp \
    ../test_functional.hpp \
    ../test_delta_fcns.hpp \
    ../test_copy_vector.hpp

CONFIG(debug, debug|release) {
    DEFINES += "__DEBUG__"
}
CONFIG(release, debug|release) {
    macx | linux: QMAKE_CXXFLAGS += -O3
    DEFINES -= "__DEBUG__"
}


