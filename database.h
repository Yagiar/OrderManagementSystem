#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>

class Database {
public:
    Database(const QString& host, const QString& user, const QString& password, const QString& dbName) {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName(host);
        db.setUserName(user);
        db.setPassword(password);
        db.setDatabaseName(dbName);
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

    QSqlQuery executeQuery(const QString& queryStr) {
        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug() << "Error: Unable to execute query" << query.lastError().text();
        }
        return query;
    }

    // Метод для добавления пользователя
    bool addUser(const QString& username, const QString& passwordHash, const QString& email) {
        QSqlQuery query;
        query.prepare("INSERT INTO users (username, password_hash, email) VALUES (:username, :password_hash, :email)");
        query.bindValue(":username", username);
        query.bindValue(":password_hash", passwordHash);
        query.bindValue(":email", email);

        if (!query.exec()) {
            qDebug() << "Error: Unable to add user" << query.lastError().text();
            return false;
        }
        return true;
    }

    // Метод для получения всех пользователей (пример)
    QList<QString> getUsers() {
        QList<QString> users;
        QSqlQuery query = executeQuery("SELECT username FROM users");

        while (query.next()) {
            users.append(query.value(0).toString());
        }

        return users;
    }

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
