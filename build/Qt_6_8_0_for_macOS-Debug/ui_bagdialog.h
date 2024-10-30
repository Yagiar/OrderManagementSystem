/********************************************************************************
** Form generated from reading UI file 'bagdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAGDIALOG_H
#define UI_BAGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_BagDialog
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *BagDialog)
    {
        if (BagDialog->objectName().isEmpty())
            BagDialog->setObjectName("BagDialog");
        BagDialog->resize(757, 586);
        listWidget = new QListWidget(BagDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 80, 731, 491));

        retranslateUi(BagDialog);

        QMetaObject::connectSlotsByName(BagDialog);
    } // setupUi

    void retranslateUi(QDialog *BagDialog)
    {
        BagDialog->setWindowTitle(QCoreApplication::translate("BagDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BagDialog: public Ui_BagDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAGDIALOG_H
