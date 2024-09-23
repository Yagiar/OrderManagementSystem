#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
#include <QMessageBox>

class Database {
public:
    Database() {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("pgdb.uni-dubna.ru");
        db.setUserName("student25");
        db.setPassword("Io_228_1337");
        db.setDatabaseName("student25");
    }
    ~Database() {
        close();
    }

    bool open() {
        if (!db.open()) {
            qDebug() << "Error: Unable to open database" << db.lastError().text();
            return false;
        }
        qDebug() << "Connection is open!";
        return true;
    }

    void close() {
        if (db.isOpen()) {
            db.close();
        }
    }

    // Метод для проверки существования пользователя по username и email
    bool userExists(const QString& username, const QString& email, QString& result) {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM users WHERE username = :username OR email = :email");
        query.bindValue(":username", username);
        query.bindValue(":email", email);

        if (!query.exec()) {
            qDebug() << "Error: Unable to check user existence" << query.lastError().text();
            return false;
        }

        if (query.next()) {
            int count = query.value(0).toInt();
            if (count > 0) {
                query.prepare("SELECT username, email FROM users WHERE username = :username OR email = :email");
                query.bindValue(":username", username);
                query.bindValue(":email", email);
                if (query.exec() && query.next()) {
                    QString existingUsername = query.value("username").toString();
                    QString existingEmail = query.value("email").toString();

                    if (existingUsername == username && existingEmail == email) {
                        result = "Username and email already exist.";
                    } else if (existingUsername == username) {
                        result = "Username already exists.";
                    } else if (existingEmail == email) {
                        result = "Email already exists.";
                    }
                }
                return true;
            }
        }
        return false;
    }

    // Метод для добавления пользователя
    bool addUser(const QString& username, const QString& passwordHash, const QString& email) {
        QString result;
        if (userExists(username, email, result)) {
            QMessageBox::warning(nullptr, "Registration Error", result);
            return false;
        }

        QString role = "user";
        QSqlQuery query;
        query.prepare("INSERT INTO users (username, password_hash, email, role) VALUES (:username, :password_hash, :email, :role)");
        query.bindValue(":username", username);
        query.bindValue(":password_hash", passwordHash);
        query.bindValue(":email", email);
        query.bindValue(":role", role);

        if (!query.exec()) {
            qDebug() << "Error: Unable to add user" << query.lastError().text();
            return false;
        }
        return true;
    }

    // Метод для логина пользователя
    bool loginUser(const QString& username, const QString& passwordHash) {
        QSqlQuery query;
        query.prepare("SELECT password_hash FROM users WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec()) {
            qDebug() << "Error: Unable to execute login query" << query.lastError().text();
            return false;
        }

        if (query.next()) {
            QString storedPasswordHash = query.value(0).toString();
            if (storedPasswordHash == passwordHash) {
                qDebug() << "Login successful!";
                return true;
            } else {
                QMessageBox::warning(nullptr, "Login Error", "Incorrect password.");
                return false;
            }
        } else {
            QMessageBox::warning(nullptr, "Login Error", "User does not exist.");
            return false;
        }
    }

private:
    QSqlDatabase db;

    // Метод для выполнения SQL-запроса
    QSqlQuery executeQuery(const QString& queryStr) {
        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug() << "Error: Unable to execute query" << query.lastError().text();
        }
        return query;
    }
};

#endif // DATABASE_H
