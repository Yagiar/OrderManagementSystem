#ifndef ORDERPROCESSINGSTRATEGY_H
#define ORDERPROCESSINGSTRATEGY_H

#include <QDebug>
#include "order.h" // Включите здесь header, чтобы избежать недоступности

class OrderProcessingStrategy {
public:
    virtual ~OrderProcessingStrategy() {}
    virtual void process(Order* order) = 0;  // Метод для обработки заказа
};

class RegularOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override;
};

class ExpressOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override;
};

class CourierOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    void process(Order* order) override;
};

#endif // ORDERPROCESSINGSTRATEGY_H
