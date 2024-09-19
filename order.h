#ifndef ORDER_H
#define ORDER_H

#include <iostream>

class Order {
public:
    virtual ~Order() {}
    // Чисто виртуальный метод для обработки заказа
    virtual void processOrder() = 0;
};

class PhysicalOrder : public Order {
public:
    // Переопределение метода обработки физического заказа
    void processOrder() override {
        std::cout << "Processing physical order..." << std::endl;
    }
};

class DigitalOrder : public Order {
public:
    // Переопределение метода обработки цифрового заказа
    void processOrder() override {
        std::cout << "Processing digital order..." << std::endl;
    }
};

// Фабричный класс для создания объектов Order
class Factory {
public:
    virtual ~Factory() {};

    // Чисто виртуальный метод фабричного создания
    virtual Order* FactoryMethod() const = 0;

    // Метод для выполнения операции с заказом
    void SomeOperation() const {
        // Используем фабричный метод для создания заказа
        Order* order = this->FactoryMethod();
        // Обрабатываем заказ
        order->processOrder();
        // Удаляем заказ, чтобы избежать утечек памяти
        delete order;
    }
};

// Конкретная фабрика для создания цифровых заказов
class DigitalFactory : public Factory {
public:
    Order* FactoryMethod() const override {
        return new DigitalOrder();
    }
};

// Конкретная фабрика для создания физических заказов
class PhysicalFactory : public Factory {
public:
    Order* FactoryMethod() const override {
        return new PhysicalOrder();
    }
};
#endif // ORDER_H
