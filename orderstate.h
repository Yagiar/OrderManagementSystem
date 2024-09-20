#ifndef ORDERSTATE_H
#define ORDERSTATE_H
#include "order.h"

class OrderState {
public:
    virtual void handle(Order* order) = 0;
};

class NewOrderState : public OrderState {
public:
    void handle(Order* order) override {
        // логика для новых заказов
    }
};

class ProcessingOrderState : public OrderState {
public:
    void handle(Order* order) override {
        // логика для заказов в обработке
    }
};

class CompletedOrderState : public OrderState {
public:
    void handle(Order* order) override {
        // логика для завершённых заказов
    }
};

#endif // ORDERSTATE_H
