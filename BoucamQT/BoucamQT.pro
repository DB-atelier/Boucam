#-------------------------------------------------
#
# Project created by QtCreator 2013-07-17T17:24:45
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = BoucamQT
TEMPLATE = app


QMAKE_POST_LINK += $${QMAKE_COPY} .\\release\\BoucamQT.exe  .\\..\\Boucam\\BoucamQT.exe

INCLUDEPATH += $$PWD/../../opencv246/build/include
DEPENDPATH += $$PWD/../../opencv246/build/include


SOURCES += \
    ../src/mainwindow.cpp \
    ../src/main.cpp \
    ../src/webcam.cpp \
    ../src/facedetection.cpp

HEADERS  += \
    ../src/mainwindow.h \
    ../src/webcam.h \
    ../src/facedetection.h

FORMS    += \
    ../src/mainwindow.ui


LIBS += -L$$PWD/../../opencv246/build/x86/vc10/lib/ \
        -lopencv_calib3d246      \
        -lopencv_contrib246      \
        -lopencv_core246         \
        -lopencv_features2d246   \
        -lopencv_flann246        \
        -lopencv_gpu246          \
        -lopencv_highgui246      \
        -lopencv_imgproc246      \
        -lopencv_legacy246       \
        -lopencv_ml246           \
        -lopencv_nonfree246      \
        -lopencv_objdetect246    \
        -lopencv_photo246        \
        -lopencv_stitching246    \
        -lopencv_video246        \
        -lopencv_videostab246
