#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <QString>
#include "database.h"
#include "good.h"

extern QString username;
class Order {
public:
    virtual ~Order() {}
    // Чисто виртуальный метод для обработки заказа
    virtual void processOrder(const QString& orderDescription,
                              int stateId, int priorityId, const QList<Good>& goods) = 0;
};

class PhysicalOrder : public Order {
public:
    // Переопределение метода обработки физического заказа
    void processOrder(const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override {
        Database db;
        if(db.open())
        {
            db.InsertOrder(db.GetUserIdByUsername(username), orderDescription, "Физический", stateId, priorityId, goods);
        }
        else
        {
            // какой-нибудь QDebug
        }
    }
};

class DigitalOrder : public Order {
public:
    // Переопределение метода обработки цифрового заказа
    void processOrder(const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override {
        Database db;
        if(db.open())
        {
            db.InsertOrder(db.GetUserIdByUsername(username), orderDescription, "Цифровой", stateId, priorityId, goods);
        }
        else
        {
            // какой-нибудь QDebug
        }

    }
};

#endif // ORDER_H
