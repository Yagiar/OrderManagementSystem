#ifndef FACTORY_H
#define FACTORY_H
#include "order.h"

// Фабричный класс для создания объектов Order
class Factory {
public:
    virtual ~Factory() {};

    // Чисто виртуальный метод фабричного создания
    virtual Order* CreateOrder() = 0;

    // Метод для выполнения операции с заказом
    std::string SomeOperation() {
        // Используем фабричный метод для создания заказа
        Order* order = this->CreateOrder();
        // Обрабатываем заказ
        std::string msg = order->processOrder();
        // Удаляем заказ, чтобы избежать утечек памяти
        delete order;

        return msg;
    }
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
