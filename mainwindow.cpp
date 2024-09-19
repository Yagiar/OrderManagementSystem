#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButProcessOrder_clicked()
{
    Factory *digitalFactory = new DigitalFactory();
    ui->labelDigOrder->setText(QString::fromStdString(digitalFactory->SomeOperation()));
    delete digitalFactory;

    Factory *physicalFactory = new PhysicalFactory();
    ui->labelPhOrder->setText(QString::fromStdString(physicalFactory->SomeOperation()));

    delete physicalFactory;
}

