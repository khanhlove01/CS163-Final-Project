QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwordwindow.cpp \
    editword.cpp \
    function.cpp \
    main.cpp \
    mainwindow.cpp \
    randomword.cpp \
    removeword.cpp \
    searchdefinitionwindow.cpp \
    searchwindow.cpp \
    switchdataset.cpp \
    viewhistory.cpp

HEADERS += \
    addwordwindow.h \
    editword.h \
    function.h \
    mainwindow.h \
    randomword.h \
    removeword.h \
    searchdefinitionwindow.h \
    searchwindow.h \
    switchdataset.h \
    viewhistory.h

FORMS += \
    addwordwindow.ui \
    editword.ui \
    mainwindow.ui \
    randomword.ui \
    removeword.ui \
    searchdefinitionwindow.ui \
    searchwindow.ui \
    switchdataset.ui \
    viewhistory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
