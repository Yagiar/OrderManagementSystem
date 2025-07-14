#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include "good.h"
#include <QGridLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
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
    QGridLayout *gridLayout;

};

#endif // MAINWINDOW_H
