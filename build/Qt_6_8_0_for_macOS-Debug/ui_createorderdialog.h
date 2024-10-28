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
    QComboBox *comboBoxPaymentSystem;
    QLabel *label_4;

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
        comboBoxTypeOrder->setGeometry(QRect(440, 80, 161, 26));
        label = new QLabel(CreateOrderDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 60, 71, 20));
        label_2 = new QLabel(CreateOrderDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(610, 60, 121, 20));
        comboBoxPriorityOrder = new QComboBox(CreateOrderDialog);
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->addItem(QString());
        comboBoxPriorityOrder->setObjectName("comboBoxPriorityOrder");
        comboBoxPriorityOrder->setGeometry(QRect(590, 80, 161, 26));
        textEditDescriptionOrder = new QTextEdit(CreateOrderDialog);
        textEditDescriptionOrder->setObjectName("textEditDescriptionOrder");
        textEditDescriptionOrder->setGeometry(QRect(460, 160, 471, 351));
        label_3 = new QLabel(CreateOrderDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 130, 161, 20));
        pushButton = new QPushButton(CreateOrderDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(780, 570, 151, 61));
        comboBoxPaymentSystem = new QComboBox(CreateOrderDialog);
        comboBoxPaymentSystem->addItem(QString());
        comboBoxPaymentSystem->addItem(QString());
        comboBoxPaymentSystem->addItem(QString());
        comboBoxPaymentSystem->setObjectName("comboBoxPaymentSystem");
        comboBoxPaymentSystem->setGeometry(QRect(760, 80, 161, 26));
        label_4 = new QLabel(CreateOrderDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(780, 60, 121, 20));

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
        comboBoxPaymentSystem->setItemText(0, QCoreApplication::translate("CreateOrderDialog", "\320\241\320\221\320\237", nullptr));
        comboBoxPaymentSystem->setItemText(1, QCoreApplication::translate("CreateOrderDialog", "\320\241\320\221\320\225\320\240", nullptr));
        comboBoxPaymentSystem->setItemText(2, QCoreApplication::translate("CreateOrderDialog", "\320\257\320\235\320\224\320\225\320\232\320\241", nullptr));

        label_4->setText(QCoreApplication::translate("CreateOrderDialog", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\276\320\277\320\273\320\260\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderDialog: public Ui_CreateOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDERDIALOG_H
