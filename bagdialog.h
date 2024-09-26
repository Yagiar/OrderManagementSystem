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
    void removeGood(const Good &good, QWidget *itemWidget); // Изменяем тип параметра

private:
    QList<Good> *goods; // Указатель на список выбранных товаров
    QScrollArea *scrollArea; // ScrollArea для отображения товаров
    QWidget *scrollContent; // Контейнер для ScrollArea
};

#endif // BAGDIALOG_H
