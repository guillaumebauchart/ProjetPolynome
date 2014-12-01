TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    src/polynomial/operations.c \
    src/polynomial/polynomial.c \
    src/tools/complex.c \
    src/tools/utility.c \
    src/tools/monomial.c \
    src/tools/ui.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    src/polynomial/operations.h \
    src/polynomial/polynomial.h \
    src/tools/complex.h \
    src/tools/utility.h \
    src/tools/monomial.h \
    src/tools/ui.h

