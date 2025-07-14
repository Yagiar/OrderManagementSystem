QT = core gui sql
LIBS += -L/Users/otrix/lib

CONFIG += c++17 cmdline
CONFIG += sql_psql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    bagdialog.cpp \
    changestateform.cpp \
    createorderdialog.cpp \
    database.cpp \
    factory.cpp \
    good.cpp \
    main.cpp \
    mainwindow.cpp \
    order.cpp \
    orderlistwindow.cpp \
    orderprocessingstrategy.cpp \
    orderstate.cpp \
    orderstatehandler.cpp \
    paymentsystemadapter.cpp \
    startWindow.cpp \
    user.cpp \
    visitor.cpp

HEADERS += \
    bagdialog.h \
    changestateform.h \
    createorderdialog.h \
    database.h \
    factory.h \
    good.h \
    mainwindow.h \
    order.h \
    orderlistwindow.h \
    orderprocessingstrategy.h \
    orderstate.h \
    orderstatehandler.h \
    paymentsystemadapter.h \
    startWindow.h \
    user.h \
    visitor.h

FORMS += \
    bagdialog.ui \
    changestateform.ui \
    createorderdialog.ui \
    mainwindow.ui \
    orderlistwindow.ui \
    startWindow.ui

TRANSLATIONS += \
    OrderManagementSystem_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
