#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QList>
#include "good.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_butShowCurBag_clicked();

    void on_butCreateOrder_clicked();

private:
    Ui::MainWindow *ui;
    int countGoods;
    QList<Good> *choosenGoods;
};

#endif // MAINWINDOW_H
