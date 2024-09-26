/********************************************************************************
** Form generated from reading UI file 'createorderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDERDIALOG_H
#define UI_CREATEORDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateOrderDialog
{
public:
    QScrollArea *scrollAreaGoods;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *CreateOrderDialog)
    {
        if (CreateOrderDialog->objectName().isEmpty())
            CreateOrderDialog->setObjectName("CreateOrderDialog");
        CreateOrderDialog->resize(1059, 637);
        scrollAreaGoods = new QScrollArea(CreateOrderDialog);
        scrollAreaGoods->setObjectName("scrollAreaGoods");
        scrollAreaGoods->setGeometry(QRect(20, 150, 411, 471));
        scrollAreaGoods->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 469));
        scrollAreaGoods->setWidget(scrollAreaWidgetContents);

        retranslateUi(CreateOrderDialog);

        QMetaObject::connectSlotsByName(CreateOrderDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateOrderDialog)
    {
        CreateOrderDialog->setWindowTitle(QCoreApplication::translate("CreateOrderDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderDialog: public Ui_CreateOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDERDIALOG_H
