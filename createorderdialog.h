#ifndef CREATEORDERDIALOG_H
#define CREATEORDERDIALOG_H

#include <QList>
#include <QDialog>
#include "good.h"

namespace Ui {
class CreateOrderDialog;
}

class CreateOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateOrderDialog(QList<Good> *choosenGoods, QWidget *parent = nullptr);
    ~CreateOrderDialog();

private:
    Ui::CreateOrderDialog *ui;
    QList<Good> *goods;
};

#endif // CREATEORDERDIALOG_H
