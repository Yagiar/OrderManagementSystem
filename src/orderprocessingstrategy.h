#ifndef ORDERPROCESSINGSTRATEGY_H
#define ORDERPROCESSINGSTRATEGY_H

#include <QDebug>
#include <QWidget>
 // Включите здесь header, чтобы избежать недоступности

class Order;
class OrderProcessingStrategy {
public:
    QString name;
    virtual ~OrderProcessingStrategy() {}
    virtual QString process(Order* order) = 0;  // Метод для обработки заказа
};

class RegularOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    RegularOrderProcessingStrategy() {
        this->name = "Обычная";
    }
    QString process(Order* order) override;
};

class ExpressOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    ExpressOrderProcessingStrategy() {
        this->name = "Экспресс";

    }
    QString process(Order* order) override;
};

class CourierOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    CourierOrderProcessingStrategy() {
        this->name = "Курьером";
    }
    QString process(Order* order) override;
};

#endif // ORDERPROCESSINGSTRATEGY_H
