#include "startWindow.h"
#include "ui_startWindow.h"
#include "factory.h"
#include <QTextEdit>
#include <QKeyEvent>
#include <QVBoxLayout>

startWindow::startWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startWindow)
{
    ui->setupUi(this);
    ui->tbPassword->setEchoMode(QLineEdit::Password);
}

startWindow::~startWindow()
{
    delete ui;
}

void startWindow::on_ButProcessOrder_clicked()
{
    /*
    Factory *digitalFactory = new DigitalFactory();
    ui->labelDigOrder->setText(QString::fromStdString(digitalFactory->SomeOperation()));
    delete digitalFactory;

    Factory *physicalFactory = new PhysicalFactory();
    ui->labelPhOrder->setText(QString::fromStdString(physicalFactory->SomeOperation()));

    delete physicalFactory;

*/
}

