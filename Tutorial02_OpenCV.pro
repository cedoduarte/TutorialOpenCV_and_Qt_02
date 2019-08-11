#-------------------------------------------------
#
# Project created by QtCreator 2019-08-10T17:16:23
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tutorial02_OpenCV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        myopencv.cpp

HEADERS += \
        mainwindow.h \
        myopencv.h

FORMS += \
        mainwindow.ui

LIBS += -luser32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world411
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world411d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world411

INCLUDEPATH += $$PWD/../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../opencv/build/include
