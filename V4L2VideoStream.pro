#-------------------------------------------------
#
# Project created by QtCreator 2017-07-10T17:56:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
OPE
TARGET = V4L2VideoStream
TEMPLATE = app

# Enable c++11
CONFIG  += c++11

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    v4l2device.cpp \
    videostreamer.cpp

HEADERS += \
    v4l2device.h \
    videostreamer.h

FORMS += \
    videostreamer.ui


LIBS_PATH = /usr/local/lib

#INCLUDEPATH += /usr/include/opencv4

#LIBS += /usr/lib/aarch64-linux-gnu/libopencv_highgui.so  \
#        /usr/lib/aarch64-linux-gnu/libopencv_imgproc.so  \
#        /usr/lib/aarch64-linux-gnu/libopencv_videoio.so \
#        /usr/lib/aarch64-linux-gnu/libopencv_shape.so \
#        /usr/lib/aarch64-linux-gnu/libopencv_dnn.so \
#        /usr/lib/aarch64-linux-gnu/libopencv_core.so
