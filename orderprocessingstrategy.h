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
    RegularOrderProcessingStrategy(QString name) {
        this->name = name;
        qDebug() << "Создана стратегия обычного заказа";
    }
    QString process(Order* order) override;
};

class ExpressOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    ExpressOrderProcessingStrategy(QString name) {
        this->name = name;

        qDebug() << "Создана стратегия обычного заказа";
    }
    QString process(Order* order) override;
};

class CourierOrderProcessingStrategy: public OrderProcessingStrategy {
public:
    CourierOrderProcessingStrategy(QString name) {
        this->name = name;
        qDebug() << "Создана стратегия обычного заказа";
    }
    QString process(Order* order) override;
};

#endif // ORDERPROCESSINGSTRATEGY_H
