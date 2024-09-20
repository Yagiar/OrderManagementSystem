/********************************************************************************
** Form generated from reading UI file 'startWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLabel *labelEmail;
    QLineEdit *tbUsername;
    QLineEdit *tbPassword;
    QLineEdit *tbEmail;
    QPushButton *butLogin;
    QPushButton *butRegistation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startWindow)
    {
        if (startWindow->objectName().isEmpty())
            startWindow->setObjectName("startWindow");
        startWindow->resize(732, 600);
        centralwidget = new QWidget(startWindow);
        centralwidget->setObjectName("centralwidget");
        labelUsername = new QLabel(centralwidget);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setGeometry(QRect(260, 160, 141, 20));
        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(290, 230, 61, 20));
        labelEmail = new QLabel(centralwidget);
        labelEmail->setObjectName("labelEmail");
        labelEmail->setGeometry(QRect(300, 300, 51, 20));
        tbUsername = new QLineEdit(centralwidget);
        tbUsername->setObjectName("tbUsername");
        tbUsername->setGeometry(QRect(190, 190, 281, 26));
        tbPassword = new QLineEdit(centralwidget);
        tbPassword->setObjectName("tbPassword");
        tbPassword->setGeometry(QRect(190, 260, 281, 26));
        tbEmail = new QLineEdit(centralwidget);
        tbEmail->setObjectName("tbEmail");
        tbEmail->setGeometry(QRect(190, 330, 281, 26));
        butLogin = new QPushButton(centralwidget);
        butLogin->setObjectName("butLogin");
        butLogin->setGeometry(QRect(250, 370, 161, 29));
        butRegistation = new QPushButton(centralwidget);
        butRegistation->setObjectName("butRegistation");
        butRegistation->setGeometry(QRect(250, 400, 161, 29));
        startWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 732, 26));
        startWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(startWindow);
        statusbar->setObjectName("statusbar");
        startWindow->setStatusBar(statusbar);

        retranslateUi(startWindow);

        QMetaObject::connectSlotsByName(startWindow);
    } // setupUi

    void retranslateUi(QMainWindow *startWindow)
    {
        startWindow->setWindowTitle(QCoreApplication::translate("startWindow", "MainWindow", nullptr));
        labelUsername->setText(QCoreApplication::translate("startWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        labelPassword->setText(QCoreApplication::translate("startWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelEmail->setText(QCoreApplication::translate("startWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        butLogin->setText(QCoreApplication::translate("startWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        butRegistation->setText(QCoreApplication::translate("startWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
