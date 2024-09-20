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

#endif // ORDER_H
