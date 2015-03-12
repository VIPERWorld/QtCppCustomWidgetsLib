#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T12:37:11
#
#-------------------------------------------------

QT       += core gui widgets testlib printsupport

TARGET = QtCppCustomWidgets
TEMPLATE = app
#TEMPLATE = lib
#CONFIG += staticlib

INCLUDEPATH += ../../QtExternalLibs/qcustomplot \
    PicHistogramManager/SingleHistogram

SOURCES += main.cpp \
    qtcppcustomwidgets.cpp \
    ../../QtExternalLibs/qcustomplot/qcustomplot.cpp \
    pichistogrammanager.cpp \
    PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.cpp \
    PicHistogramManager/SingleHistogram/singlehistogram.cpp \
    PicHistogramManager/SingleHistogram/histowitheditboxes.cpp



HEADERS += qtcppcustomwidgets.h \
    ../../QtExternalLibs/qcustomplot/qcustomplot.h \
    pichistogrammanager.h \
    PicHistogramManager/SingleHistogram/singlehistogram.h \
    PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.h \
    PicHistogramManager/SingleHistogram/histowitheditboxes.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

# C++11 support
CONFIG += c++11
#QMAKE_CXXFLAGS += -std=c++0x

FORMS += \
    PicHistogramManager/SingleHistogram/singlehistogram.ui \
    PicHistogramManager/pichistogram.ui \
    PicHistogramManager/SingleHistogram/histowitheditboxes.ui

