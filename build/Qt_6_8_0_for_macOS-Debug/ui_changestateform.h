/********************************************************************************
** Form generated from reading UI file 'changestateform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESTATEFORM_H
#define UI_CHANGESTATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_changeStateForm
{
public:

    void setupUi(QDialog *changeStateForm)
    {
        if (changeStateForm->objectName().isEmpty())
            changeStateForm->setObjectName("changeStateForm");
        changeStateForm->resize(400, 300);

        retranslateUi(changeStateForm);

        QMetaObject::connectSlotsByName(changeStateForm);
    } // setupUi

    void retranslateUi(QDialog *changeStateForm)
    {
        changeStateForm->setWindowTitle(QCoreApplication::translate("changeStateForm", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeStateForm: public Ui_changeStateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESTATEFORM_H
