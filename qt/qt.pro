TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "../../onion/"
SOURCES += main.cpp \
    ../../onion/onion/class_info.cpp

DISTFILES += \
    ../../onion/onion.png \
    ../../onion/LICENSE.md \
    ../../onion/README.md

HEADERS += \
    ../../onion/cops/cop_info.hpp \
    ../../onion/cops/functions/rv_functions.hpp \
    ../../onion/cops/mkp/mkp.hpp \
    ../../onion/cops/tsp/array/create.hpp \
    ../../onion/cops/tsp/array/create.hpp \
    ../../onion/cops/tsp/array/tsp.hpp \
    ../../onion/cops/tsp/bitmatrix/tsp.hpp \
    ../../onion/onion/class_info.hpp \
    ../../onion/onion/create.hpp \
    ../../onion/onion/local_search.hpp \
    ../../onion/onion/non_copyable.hpp \
    ../../onion/onion.hpp \
    ../../onion/cops/cop_info.hpp \
    ../../onion/onionfw.hpp



