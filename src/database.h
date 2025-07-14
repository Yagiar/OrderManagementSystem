#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "good.h"
#include "factory.h"
#include "orderstate.h"
#include "orderprocessingstrategy.h"

class Database {
public:
    Database() {
        db = QSqlDatabase::addDatabase("QPSQL");


        db.setHostName("pgdb.uni-dubna.ru");
        db.setUserName("student25"); // удаленно для униковской базы
        db.setPassword("Io_228_1337");
        db.setDatabaseName("student25");


        //  db.setHostName("localhost");
        // db.setUserName("postgres"); // ЛОКАЛЬНО ДЛЯ НОУТБУКА(МАШИНЫ)
        // db.setPassword("Io_228");
        // db.setDatabaseName("postgres");
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
                     int stateId, int priorityId, const QList<Good>& goods, PaymentSystemAdapter* paymentSystem) {
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

        double totalAmount = 0.0;
        for (const Good& curGood : goods) {
            totalAmount += curGood.getPrice();
        }

        // Добавление записи в таблицу payments
        QString paymentSystemName = paymentSystem ? paymentSystem->GetPaymentSystemName() : "Неизвестно";
        // Получаем имя платёжной системы

        query.prepare("INSERT INTO payments (order_id, payment_system, amount, status) "
                      "VALUES (:orderId, :paymentSystem, :amount, 'Оплачено')");
        query.bindValue(":orderId", orderId);
        query.bindValue(":paymentSystem", paymentSystemName);
        query.bindValue(":amount", totalAmount);

        if (!query.exec()) {
            qDebug() << "Ошибка добавления записи в payments: " << query.lastError().text();
            return false; // Или обрабатываем ошибку иначе
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

    QString GetStatusPaidByOrderId(int orderId) {
        QSqlQuery query;
        query.prepare("SELECT status FROM payments WHERE order_id = :orderId");
        query.bindValue(":orderId", orderId);

        if (query.exec() && query.next()) {
            return query.value("status").toString();
        } else {
            qDebug() << "Ошибка получения статуса оплаты для заказа" << orderId << ":"
                     << query.lastError().text();
            return "Статус неизвестен"; // Или верни другое значение по умолчанию
        }
    }

    QList<Order*> getAllOrders() {
        QList<Order*> ordersList;
        QSqlQuery query;

        // Получаем все заказы
        if (!query.exec("SELECT order_id, user_id, order_description, order_type, state_id, priority_id FROM orders")) {
            qWarning() << "Error retrieving orders:" << query.lastError().text();
            return ordersList; // Возвращаем пустой список в случае ошибки
        }

        while (query.next()) {
            int orderId = query.value("order_id").toInt();
            int userId = query.value("user_id").toInt();
            QString orderDescription = query.value("order_description").toString();
            QString orderType = query.value("order_type").toString();
            int stateId = query.value("state_id").toInt();
            int priorityId = query.value("priority_id").toInt();


            // Получаем username из базы данных по userId
            QString curUser;
            QSqlQuery userQuery;
            userQuery.prepare("SELECT username FROM users WHERE user_id = :userId");
            userQuery.bindValue(":userId", userId);

            if (userQuery.exec() && userQuery.next()) {
                curUser = userQuery.value("username").toString();
            } else {
                qDebug() << "Не удалось получить username для user_id:" << userId;
                continue; // Пропускаем этот заказ, если не нашли пользователя
            }

            // Используем фабрику для создания заказа
            Factory* factory = nullptr;

            if (orderType == "Физический") {
                factory = new PhysicalFactory();
            } else if (orderType == "Цифровой") {
                factory = new DigitalFactory();
            }

            if (factory) {
                // Создаем заказ через фабрику
                OrderState* curState;
                OrderProcessingStrategy* curStrategy;

                switch(stateId)
                {

                case 1:
                {
                    curState = new CreatedState();
                    break;
                }
                case 2:
                {
                    curState = new ProcessingState();
                    break;
                }
                case 3:
                {
                    curState = new CompletedState();
                    break;
                }

                }

                switch(priorityId)
                {
                case 1:
                {
                    curStrategy = new RegularOrderProcessingStrategy();
                    break;

                }
                case 2:
                {
                    curStrategy = new ExpressOrderProcessingStrategy();
                    break;
                }
                case 3:
                {
                    curStrategy = new CourierOrderProcessingStrategy();
                    break;
                }

                }
                Order* order = factory->getExistOrder(orderId, curState,curStrategy, orderDescription, curUser,
                                                      getGoodsByOrderId(orderId)); // Укажите правильный начальный state
                //order->setOrder(orderDescription, stateId, priorityId, getGoodsByOrderId(orderId));
                order->setState(curState);
                order->setProcessingStrategy(curStrategy);
                ordersList.append(order); // Добавляем заказ в список
                delete factory; // Удаляем фабрику
            }
        }

        return ordersList; // Возвращаем список заказов
    }
    QList<Good> getGoodsByOrderId(int orderId) {
        QList<Good> goodsList;
        QSqlQuery query;

        // Получаем все good_id для данного order_id
        query.prepare("SELECT good_id FROM goods_orders WHERE order_id = :orderId");
        query.bindValue(":orderId", orderId);

        if (!query.exec()) {
            qWarning() << "Error retrieving goods ids:" << query.lastError().text();
            return goodsList; // Возвращаем пустой список в случае ошибки
        }
        // Для каждого good_id, получаем информацию о товаре
        while (query.next()) {
            int goodId = query.value(0).toInt();

            QSqlQuery goodQuery;
            goodQuery.prepare("SELECT id, name, category_id, price, description, weight FROM goods WHERE id = :goodId");
            goodQuery.bindValue(":goodId", goodId);

            if (!goodQuery.exec()) {
                qWarning() << "Error retrieving good details:" << goodQuery.lastError().text();
                continue; // Переходим к следующему good_id в случае ошибки
            }

            while (goodQuery.next()) {
                // Создаем объект Good с данными из базы
                Good good(
                    goodQuery.value("id").toInt(),
                    goodQuery.value("name").toString(),
                    goodQuery.value("category_id").toInt(),
                    goodQuery.value("price").toDouble(),
                    goodQuery.value("description").toString(),
                    goodQuery.value("weight").toDouble()
                    );

                goodsList.append(good); // Добавляем товар в список
            }
        }
        return goodsList; // Возвращаем список товаров
    }
private:
    QSqlDatabase db;

    QSqlQuery executeQuery(const QString& queryStr) {
        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug() << "Error: Unable to execute query" << query.lastError().text();
        }
        return query;
    }
};

#endif // DATABASE_H
