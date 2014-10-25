TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    src/complex/complex.c \
    src/monomial/monomial.c \
    src/polynomial/operations.c \
    src/polynomial/polynomial.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    src/complex/complex.h \
    src/monomial/monomial.h \
    src/polynomial/operations.h \
    src/polynomial/polynomial.h

