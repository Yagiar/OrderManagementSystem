#ifndef BAGDIALOG_H
#define BAGDIALOG_H

#include <QDialog>
#include <QList>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QListWidget>
#include "good.h"

class BagDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BagDialog(QList<Good> *choosenGoods, QWidget *parent = nullptr);
    ~BagDialog();

private slots:
    void removeGood(const Good &good, QWidget *itemWidget);

private:
    QList<Good> *goods;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
};

#endif // BAGDIALOG_H
