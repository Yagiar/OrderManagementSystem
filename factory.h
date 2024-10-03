#ifndef FACTORY_H
#define FACTORY_H
#include "order.h"
#include "good.h"
// Фабричный класс для создания объектов Order
class Factory {
public:
    virtual ~Factory() {};

    // Чисто виртуальный метод фабричного создания


    // Метод для выполнения операции с заказом
    void CreationOfOrder(const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) {
        // Используем фабричный метод для создания заказа
        Order* order = this->CreateOrder();
        // Обрабатываем заказ
        order->processOrder(orderDescription, stateId,priorityId,goods);

        delete order;
    }
private:
        virtual Order* CreateOrder() = 0;
};

// Конкретная фабрика для создания цифровых заказов
class DigitalFactory : public Factory {
public:
    Order* CreateOrder() override {
        return new DigitalOrder();
    }
};

// Конкретная фабрика для создания физических заказов
class PhysicalFactory : public Factory {
public:
    Order* CreateOrder() override {
        return new PhysicalOrder();
    }
};
#endif // FACTORY_H
