#ifndef ORDERSTATEHANDLER_H
#define ORDERSTATEHANDLER_H

#include <QString>
#include <QMessageBox>
#include "order.h"
#include "orderstate.h"
#include <QWidget>

class OrderStateHandler {
public:
    virtual ~OrderStateHandler() = default;

    void setNextHandler(OrderStateHandler* next) { successor = next; }

    virtual void handle(Order* order, OrderState *newState, QWidget *widget) {
        if (successor) {
            successor->handle(order, newState, widget);
        }
    }

protected:
    OrderStateHandler* successor = nullptr;
};

class StartedStateHandler : public OrderStateHandler {
public:
    void handle(Order* order, OrderState *newState, QWidget *widget) override {
        if (newState->name == "В обработке") {
            order->setState(new ProcessingState());
            QMessageBox::information(widget, "Статус заказа", "Заказ в обработке!");
        } else if (newState->name == "Выполнен" && order->getState()->name == "Принят") {
            QMessageBox::warning(widget, "Ошибка", "Невозможно изменить состояние заказа на 'Выполнен' из 'Принят'.");
        } else {
            OrderStateHandler::handle(order, newState, widget);
        }
    }
};

class InProgressStateHandler : public OrderStateHandler {
public:
    void handle(Order* order, OrderState *newState, QWidget *widget) override {
        if (order->getState()->name == "В обработке") {
            if (newState->name == "Выполнен") {
                order->setState(new CompletedState());
                QMessageBox::information(widget, "Статус заказа", "Заказ выполнен!");
            } else {
                OrderStateHandler::handle(order, newState, widget);
            }
        } else {
            OrderStateHandler::handle(order, newState, widget);
        }
    }
};

class CompletedStateHandler : public OrderStateHandler {
public:
    void handle(Order* order, OrderState *newState, QWidget *widget) override {
        if (order->getState()->name == "Выполнен") {
            QMessageBox::warning(widget, "Ошибка", "Заказ уже выполнен!");
        } else {
            OrderStateHandler::handle(order, newState, widget);
        }
    }
};

#endif // ORDERSTATEHANDLER_H
