#ifndef ORDERPROCESSINGSTRATEGY_H
#define ORDERPROCESSINGSTRATEGY_H
#include "order.h"
#include <QDebug>
class OrderProcessingStrategy {
public:
    virtual ~OrderProcessingStrategy() {}
    virtual void process(Order* order) = 0;  // Метод для обработки заказа
};

class RegularOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override {
        // Логика обработки обычного заказа
        qDebug() << "Обычная стратегия" << order->getOrderId();
    }
};

class ExpressOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override {
        // Логика обработки экспресс заказа
        qDebug() << "Экспресс стратегия" << order->getOrderId();
    }
};

class CourierOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override {
        // Логика обработки для заказа курьером
        qDebug() << "Курьер стратегия" << order->getOrderId() << "по почте";
    }
};

#endif // ORDERPROCESSINGSTRATEGY_H
