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
#include <QtWidgets/QGridLayout>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelEmail;
    QLabel *labelUsername;
    QLineEdit *tbPassword;
    QPushButton *butLogin;
    QLabel *labelPassword;
    QLineEdit *tbUsername;
    QLineEdit *tbEmail;
    QPushButton *butRegistation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startWindow)
    {
        if (startWindow->objectName().isEmpty())
            startWindow->setObjectName("startWindow");
        startWindow->resize(730, 611);
        centralwidget = new QWidget(startWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 731, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelEmail = new QLabel(gridLayoutWidget);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 4, 0, 1, 1);

        labelUsername = new QLabel(gridLayoutWidget);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setEnabled(true);

        gridLayout->addWidget(labelUsername, 0, 0, 1, 1);

        tbPassword = new QLineEdit(gridLayoutWidget);
        tbPassword->setObjectName("tbPassword");

        gridLayout->addWidget(tbPassword, 3, 0, 1, 1);

        butLogin = new QPushButton(gridLayoutWidget);
        butLogin->setObjectName("butLogin");

        gridLayout->addWidget(butLogin, 6, 0, 1, 1);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 2, 0, 1, 1);

        tbUsername = new QLineEdit(gridLayoutWidget);
        tbUsername->setObjectName("tbUsername");

        gridLayout->addWidget(tbUsername, 1, 0, 1, 1);

        tbEmail = new QLineEdit(gridLayoutWidget);
        tbEmail->setObjectName("tbEmail");

        gridLayout->addWidget(tbEmail, 5, 0, 1, 1);

        butRegistation = new QPushButton(gridLayoutWidget);
        butRegistation->setObjectName("butRegistation");

        gridLayout->addWidget(butRegistation, 7, 0, 1, 1);

        startWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 26));
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
        labelEmail->setText(QCoreApplication::translate("startWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        labelUsername->setText(QCoreApplication::translate("startWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        butLogin->setText(QCoreApplication::translate("startWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        labelPassword->setText(QCoreApplication::translate("startWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        butRegistation->setText(QCoreApplication::translate("startWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
