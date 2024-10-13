#ifndef FACTORY_H
#define FACTORY_H

#include "order.h"
#include "good.h"

class Factory {
public:
    virtual ~Factory() {}

    // Метод для создания нового заказа
    void creationOfOrder(const QString& orderDescription,
                         int stateId, int priorityId, const QList<Good>& goods, QString& username) {
        Order* order = createOrder(); // Используем чистую виртуальную функцию
        order->createOrder(orderDescription, stateId, priorityId, goods, username);
        delete order; // Освобождаем память
    }

    // Метод для получения существующего заказа
    Order* getExistOrder(int orderId, OrderState* state, QString& orderDiscription, QString& username) {
        return createOrder(orderId, state, orderDiscription, username);
    }

private:
    // Чисто виртуальные функции для создания заказа
    virtual Order* createOrder() = 0;
    virtual Order* createOrder(int orderId, OrderState* state, QString& orderDiscription, QString& username) = 0;
};

class DigitalFactory : public Factory {
public:
    Order* createOrder() override {
        return new DigitalOrder(); // Создаем новый цифровой заказ
    }

    Order* createOrder(int orderId, OrderState* state, QString& orderDiscription, QString& username) override {
        return new DigitalOrder(orderId, state, orderDiscription, username); // Создаем существующий цифровой заказ
    }
};

class PhysicalFactory : public Factory {
public:
    Order* createOrder() override {
        return new PhysicalOrder(); // Создаем новый физический заказ
    }

    Order* createOrder(int orderId, OrderState* state, QString& orderDiscription, QString& username) override {
        return new PhysicalOrder(orderId, state, orderDiscription, username); // Создаем существующий физический заказ
    }
};

#endif // FACTORY_H
