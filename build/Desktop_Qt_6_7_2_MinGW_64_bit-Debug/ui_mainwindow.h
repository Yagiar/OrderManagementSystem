/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *butShowOrders;
    QLabel *labelCountGoods;
    QPushButton *butShowCurBag;
    QPushButton *butCreateOrder;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1175, 598);
        label = new QLabel(MainWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 80, 281, 20));
        scrollArea = new QScrollArea(MainWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 110, 1151, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1149, 469));
        scrollArea->setWidget(scrollAreaWidgetContents);
        butShowOrders = new QPushButton(MainWindow);
        butShowOrders->setObjectName("butShowOrders");
        butShowOrders->setGeometry(QRect(10, 40, 271, 29));
        labelCountGoods = new QLabel(MainWindow);
        labelCountGoods->setObjectName("labelCountGoods");
        labelCountGoods->setGeometry(QRect(290, 80, 63, 20));
        butShowCurBag = new QPushButton(MainWindow);
        butShowCurBag->setObjectName("butShowCurBag");
        butShowCurBag->setGeometry(QRect(370, 70, 161, 31));
        butCreateOrder = new QPushButton(MainWindow);
        butCreateOrder->setObjectName("butCreateOrder");
        butCreateOrder->setGeometry(QRect(540, 70, 141, 31));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\320\262\320\260\321\200\320\276\320\262 \320\262 \321\202\320\265\320\272\321\203\321\211\320\265\320\274 \320\267\320\260\320\272\320\260\320\267\320\265:", nullptr));
        butShowOrders->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        labelCountGoods->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        butShowCurBag->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\276\321\200\320\267\320\270\320\275\321\203", nullptr));
        butCreateOrder->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
