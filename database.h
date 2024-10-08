#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "good.h"

class Database {
public:
    Database() {
        db = QSqlDatabase::addDatabase("QPSQL");

        /*
         * db.setHostName("pgdb.uni-dubna.ru");
        db.setUserName("student25"); // удаленно для униковской базы
        db.setPassword("Io_228_1337");
        db.setDatabaseName("student25");
        */
         db.setHostName("localhost");
        db.setUserName("postgres"); // ЛОКАЛЬНО ДЛЯ НОУТБУКА(МАШИНЫ)
        db.setPassword("Io_228");
        db.setDatabaseName("postgres");
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
    int GetUserIdByUsername(const QString& username) {
        // Предполагаем, что у вас есть открытое соединение с базой данных
        QSqlQuery query;

        query.prepare("SELECT user_id FROM users WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec()) {
            qDebug() << "Ошибка выполнения запроса:" << query.lastError();
            return -1;
        }

        if (query.next()) {
            return query.value(0).toInt();
        }

        return -1;
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
        query.prepare("SELECT password_hash FROM users WHERE username = :username AND role = 'user'");
        query.bindValue(":username", username);

        if (!query.exec()) {
            qDebug() << "Error: Unable to execute login query" << query.lastError().text();
            return false;
        }

        if (query.next()) {
            QString storedPasswordHash = query.value(0).toString();
            if (storedPasswordHash == passwordHash) {
                qDebug() << "Login user successful!";
                return true;
            } else {
                QMessageBox::warning(nullptr, "Login Error", "Incorrect password.");
                return false;
            }
        } else {
            return false;
        }
    }
    bool loginUserWithRole(const QString& username, const QString& passwordHash) {
        QSqlQuery query;
        query.prepare("SELECT password_hash FROM users WHERE username = :username and role = 'manager'");
        query.bindValue(":username", username);

        if (!query.exec()) {
            qDebug() << "Error: Unable to execute login query" << query.lastError().text();
            return false;
        }

        if (query.next()) {
            QString storedPasswordHash = query.value(0).toString();
            if (storedPasswordHash == passwordHash )
            {
                qDebug() << "Login manager successful!";
                return true;
            } else {
                QMessageBox::warning(nullptr, "Login manager Error", "Incorrect password.");
                return false;
            }
        } else {
            return false;
        }
    }
    QList<Good> getGoods() {
        QList<Good> goods;
        QSqlQuery query("SELECT id, name, category_id, price, description, weight FROM goods");

        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            int categoryId = query.value(2).toInt();
            double price = query.value(3).toDouble();
            QString description = query.value(4).toString();
            double weight = query.value(5).toDouble();

            Good good(id, name, categoryId, price, description, weight);
            goods.append(good);
        }

        return goods;
    }

    bool InsertOrder(int userId, const QString& orderDescription, const QString& orderType,
                     int stateId, int priorityId, const QList<Good>& goods) {
        // Вставляем заказ в таблицу orders
        QSqlQuery query;
        query.prepare("INSERT INTO orders (user_id, order_description, order_type, state_id, priority_id) "
                      "VALUES (:userId, :orderDescription, :orderType, :stateId, :priorityId)");
        query.bindValue(":userId", userId);
        query.bindValue(":orderDescription", orderDescription);
        query.bindValue(":orderType", orderType);
        query.bindValue(":stateId", stateId);
        query.bindValue(":priorityId", priorityId);

        if (!query.exec()) {
            qDebug() << "Ошибка вставки заказа: " << query.lastError().text();
            return false;
        }

        // Получаем order_id для нового заказа
        int orderId = query.lastInsertId().toInt();

        // Разбиваем goodsIds (предполагается, что это строка с идентификаторами товаров, разделёнными запятыми)

        // Вставляем данные в связующую таблицу goods_orders
        for (const Good& curGood : goods) {
            query.prepare("INSERT INTO goods_orders (good_id, order_id) VALUES (:goodId, :orderId)");
            query.bindValue(":goodId", curGood.getId());
            query.bindValue(":orderId", orderId);

            if (!query.exec()) {
                qDebug() << "Ошибка вставки товара в goods_orders: " << query.lastError().text();
                return false;
            }
        }
        qDebug() << "Заказ успешно добавлен, order_id: " << orderId;
        return true;
    }

    void UpdateOrderState(int orderId, int newStateId) {
        QSqlQuery query;
        query.prepare("UPDATE orders SET state_id = :newStateId WHERE order_id = :orderId");
        query.bindValue(":newStateId", newStateId);
        query.bindValue(":orderId", orderId);

        if (!query.exec()) {
            qDebug() << "Ошибка при обновлении состояния заказа:" << query.lastError().text();
        } else {
            qDebug() << "Состояние заказа с ID" << orderId << "обновлено на" << newStateId;
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
