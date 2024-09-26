QT += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    bagdialog.cpp \
    createorderdialog.cpp \
    database.cpp \
    factory.cpp \
    good.cpp \
    main.cpp \
    mainwindow.cpp \
    order.cpp \
    orderstate.cpp \
    startWindow.cpp \
    user.cpp

HEADERS += \
    bagdialog.h \
    createorderdialog.h \
    database.h \
    factory.h \
    good.h \
    mainwindow.h \
    order.h \
    orderstate.h \
    startWindow.h \
    user.h

FORMS += \
    bagdialog.ui \
    createorderdialog.ui \
    mainwindow.ui \
    startWindow.ui

TRANSLATIONS += \
    OrderManagementSystem_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
