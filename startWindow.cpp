#include "startWindow.h"
#include "ui_startWindow.h"
#include "factory.h"
#include <QTextEdit>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <database.h>
#include <QCryptographicHash>
#include <QString>

QString hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex(); // Преобразуем хэш в шестнадцатеричное представление
}

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


void startWindow::on_butLogin_clicked()
{

}

void startWindow::on_butRegistation_clicked()
{
    Database db("pgdb.uni-dubna.ru","student25","Io_228_1337","student25");
    if (db.open()) {
        if(ui->tbUsername->text() != "" && ui->tbPassword->text() != "" && ui->tbEmail->text() != "")
        {
            if (db.addUser(ui->tbUsername->text(),hashPassword(ui->tbPassword->text()),ui->tbEmail->text())) {
                qDebug() << "User added successfully!";
            } else {
                qDebug() << "Failed to add user.";
            }
        }
    }
}

