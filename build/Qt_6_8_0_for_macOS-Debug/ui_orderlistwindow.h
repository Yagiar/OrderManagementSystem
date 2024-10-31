/********************************************************************************
** Form generated from reading UI file 'orderlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERLISTWINDOW_H
#define UI_ORDERLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderListWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OrderListWindow)
    {
        if (OrderListWindow->objectName().isEmpty())
            OrderListWindow->setObjectName("OrderListWindow");
        OrderListWindow->resize(800, 600);
        centralwidget = new QWidget(OrderListWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 30, 791, 521));
        OrderListWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(OrderListWindow);
        statusbar->setObjectName("statusbar");
        OrderListWindow->setStatusBar(statusbar);

        retranslateUi(OrderListWindow);

        QMetaObject::connectSlotsByName(OrderListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OrderListWindow)
    {
        OrderListWindow->setWindowTitle(QCoreApplication::translate("OrderListWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderListWindow: public Ui_OrderListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERLISTWINDOW_H
