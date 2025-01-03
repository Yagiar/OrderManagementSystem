#include "startWindow.h"
#include "ui_startWindow.h"
#include <QTextEdit>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QCryptographicHash>
#include <QString>
#include <QMessageBox>
#include <database.h>
#include "mainwindow.h"
#include "orderlistwindow.h"

extern QString username;

static QString hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex(); // Преобразуем хэш в шестнадцатеричное представление
}

startWindow::startWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startWindow)
{
      setWindowTitle("Аутентификация");
    ui->setupUi(this);
    ui->tbPassword->setEchoMode(QLineEdit::Password);
}

startWindow::~startWindow()
{
    delete ui;
}


void startWindow::on_butLogin_clicked()
{
    Database db;
    if (db.open()) {
        // Проверяем, что поля не пустые
        if(!ui->tbUsername->text().isEmpty() && !ui->tbPassword->text().isEmpty())
        {
            if (db.loginUser(ui->tbUsername->text(), hashPassword(ui->tbPassword->text()))){
                this->close();
                username = ui->tbUsername->text();
                MainWindow * mForm = new MainWindow();
                mForm->show();
            } else {
                if(db.loginUserWithRole(ui->tbUsername->text(), hashPassword(ui->tbPassword->text())))
                {

                    this->close();
                    username = ui->tbUsername->text();
                    OrderListWindow* orderListWindow = new OrderListWindow(this);
                    orderListWindow->show();

                   // QMessageBox::information(this, "Инфа", "Вы успешно вошли под манагером: " + username);

                }
                else
                {
                    QMessageBox::warning(nullptr, "Login Error", "User does not exist.");
                }
            }

        } else {
            qDebug() << "Please fill in all fields.";
        }
    } else {
        qDebug() << "Failed to open database.";
    }
}

void startWindow::on_butRegistation_clicked()
{
    Database db;
    if (db.open()) {
        // Проверяем, что поля не пустые
        if(!ui->tbUsername->text().isEmpty() && !ui->tbPassword->text().isEmpty() && !ui->tbEmail->text().isEmpty())
        {
            if (db.addUser(ui->tbUsername->text(), hashPassword(ui->tbPassword->text()), ui->tbEmail->text())) {
                this->close();
                username = ui->tbUsername->text();
                MainWindow * mForm = new MainWindow();
                mForm->show();
            } else{
                QMessageBox::warning(nullptr, "Error", "Заполните все поля.");
            }
        } else {
            qDebug() << "Please fill in all fields.";
        }
    } else {
        qDebug() << "Failed to open database.";
    }
}


