/********************************************************************************
** Form generated from reading UI file 'createorderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDERDIALOG_H
#define UI_CREATEORDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateOrderDialog
{
public:
    QScrollArea *scrollAreaGoods;
    QWidget *scrollAreaWidgetContents;
    QComboBox *comboBoxTypeOrder;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxPriorityOrder;
    QTextEdit *textEditDescriptionOrder;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *CreateOrderDialog)
    {
        if (CreateOrderDialog->objectName().isEmpty())
            CreateOrderDialog->setObjectName("CreateOrderDialog");
        CreateOrderDialog->resize(950, 637);
        scrollAreaGoods = new QScrollArea(CreateOrderDialog);
        scrollAreaGoods->setObjectName("scrollAreaGoods");
        scrollAreaGoods->setGeometry(QRect(20, 40, 411, 471));
        scrollAreaGoods->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 469));
        scrollAreaGoods->setWidget(scrollAreaWidgetContents);
        comboBoxTypeOrder = new QComboBox(CreateOrderDialog);
        comboBoxTypeOrder->addItem(QString());
        comboBoxTypeOrder->addItem(QString());
        comboBoxTypeOrder->setObjectName("comboBoxTypeOrder");
        comboBoxTypeOrder->setGeometry(QRect(460, 80, 161, 26));
        label = new QLabel(CreateOrderDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 50, 161, 20));
        label_2 = new QLabel(CreateOrderDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(650, 50, 161, 20));
        comboBoxPriorityOrder = new QComboBox(CreateOrderDialog);
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->setObjectName("comboBoxPriorityOrder");
        comboBoxPriorityOrder->setGeometry(QRect(650, 80, 161, 26));
        textEditDescriptionOrder = new QTextEdit(CreateOrderDialog);
        textEditDescriptionOrder->setObjectName("textEditDescriptionOrder");
        textEditDescriptionOrder->setGeometry(QRect(460, 160, 471, 351));
        label_3 = new QLabel(CreateOrderDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 130, 161, 20));
        pushButton = new QPushButton(CreateOrderDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(780, 570, 151, 61));

        retranslateUi(CreateOrderDialog);

        QMetaObject::connectSlotsByName(CreateOrderDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateOrderDialog)
    {
        CreateOrderDialog->setWindowTitle(QCoreApplication::translate("CreateOrderDialog", "Dialog", nullptr));
        comboBoxTypeOrder->setItemText(0, QCoreApplication::translate("CreateOrderDialog", "\320\246\320\270\321\204\321\200\320\276\320\262\320\276\320\271", nullptr));
        comboBoxTypeOrder->setItemText(1, QCoreApplication::translate("CreateOrderDialog", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));

        label->setText(QCoreApplication::translate("CreateOrderDialog", "\320\242\320\270\320\277 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("CreateOrderDialog", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        comboBoxPriorityOrder->setItemText(0, QCoreApplication::translate("CreateOrderDialog", "\320\236\320\261\321\213\321\207\321\207\320\275\321\213\320\271", nullptr));
        comboBoxPriorityOrder->setItemText(1, QCoreApplication::translate("CreateOrderDialog", "\320\255\320\272\321\201\320\277\321\200\320\265\321\201\321\201", nullptr));
        comboBoxPriorityOrder->setItemText(2, QCoreApplication::translate("CreateOrderDialog", "\320\232\321\203\321\200\321\214\320\265\321\200", nullptr));

        label_3->setText(QCoreApplication::translate("CreateOrderDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\272 \320\267\320\260\320\272\320\260\320\267\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateOrderDialog", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\276\320\277\320\273\320\260\321\202\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderDialog: public Ui_CreateOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDERDIALOG_H
