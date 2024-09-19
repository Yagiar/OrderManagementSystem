#ifndef ORDER_H
#define ORDER_H

#include <iostream>

class Order {
public:
    virtual ~Order() {}
    // Чисто виртуальный метод для обработки заказа
    virtual std::string processOrder() = 0;
};

class PhysicalOrder : public Order {
public:
    // Переопределение метода обработки физического заказа
    std::string processOrder() override {
        return "Processing physical order...";
    }
};

class DigitalOrder : public Order {
public:
    // Переопределение метода обработки цифрового заказа
    std::string processOrder() override {
        return "Processing Digital order...";
    }
};

// Фабричный класс для создания объектов Order
class Factory {
public:
    virtual ~Factory() {};

    // Чисто виртуальный метод фабричного создания
    virtual Order* FactoryMethod() = 0;

    // Метод для выполнения операции с заказом
    std::string SomeOperation() {
        // Используем фабричный метод для создания заказа
        Order* order = this->FactoryMethod();
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
    Order* FactoryMethod() override {
        return new DigitalOrder();
    }
};

// Конкретная фабрика для создания физических заказов
class PhysicalFactory : public Factory {
public:
    Order* FactoryMethod() override {
        return new PhysicalOrder();
    }
};
#endif // ORDER_H
