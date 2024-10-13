#ifndef FACTORY_H
#define FACTORY_H

#include "order.h"
#include "good.h"

class Factory {
public:
    virtual ~Factory() {}

    // Метод для создания нового заказа
    void creationOfOrder(const QString& orderDescription,
                         int stateId, int priorityId, const QList<Good>& goods) {
        Order* order = createOrder(); // Используем чистую виртуальную функцию
        order->createOrder(orderDescription, stateId, priorityId, goods);
        delete order; // Освобождаем память
    }

    // Метод для получения существующего заказа
    Order* getExistOrder(int orderId, OrderState* state, QString& orderDiscription) {
        return createOrder(orderId, state, orderDiscription);
    }

private:
    // Чисто виртуальные функции для создания заказа
    virtual Order* createOrder() = 0;
    virtual Order* createOrder(int orderId, OrderState* state, QString& orderDiscription) = 0;
};

class DigitalFactory : public Factory {
public:
    Order* createOrder() override {
        return new DigitalOrder(); // Создаем новый цифровой заказ
    }

    Order* createOrder(int orderId, OrderState* state, QString& orderDiscription) override {
        return new DigitalOrder(orderId, state, orderDiscription); // Создаем существующий цифровой заказ
    }
};

class PhysicalFactory : public Factory {
public:
    Order* createOrder() override {
        return new PhysicalOrder(); // Создаем новый физический заказ
    }

    Order* createOrder(int orderId, OrderState* state, QString& orderDiscription) override {
        return new PhysicalOrder(orderId, state, orderDiscription); // Создаем существующий физический заказ
    }
};

#endif // FACTORY_H
