QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    function.cpp \
    main.cpp \
    mainwindow.cpp \
    searchdefinitionwindow.cpp \
    searchwindow.cpp \
    switchdataset.cpp

HEADERS += \
    function.h \
    mainwindow.h \
    searchdefinitionwindow.h \
    searchwindow.h \
    switchdataset.h

FORMS += \
    mainwindow.ui \
    searchdefinitionwindow.ui \
    searchwindow.ui \
    switchdataset.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
