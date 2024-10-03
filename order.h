#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>
#include "good.h"
#include "orderstate.h"

// Forward declaration of the OrderState class
class OrderState;

extern QString username;  // Using a global variable, but better to refactor

class Order {
private:
    OrderState* state;  // Raw pointer for managing state
     int orderId;

public:
    virtual ~Order() {
        delete state;  // Don't forget to delete the state
    }

    void setState(OrderState* newState) {
        delete state;  // Delete the previous state
        state = newState;  // Set the new state
    }

    int getOrderId() const {
        return orderId;
    }

    // Метод для установки идентификатора заказа
    void setOrderId(int id) {
        orderId = id;
    }
    void processOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods) {
        if (state) {
            state->processOrder(this, orderDescription, stateId, priorityId, goods);
        }
    }

    virtual QString getOrderType() = 0;
    QString getUsername() const { return username; }
};

// Physical order class
class PhysicalOrder : public Order {
public:
    PhysicalOrder() {
        setState(new CreatedState());  // Set the initial state
    }

    PhysicalOrder(int id) {
        setOrderId(id); // Устанавливаем идентификатор заказа
        setState(new CreatedState());
    }

    QString getOrderType() override {
        return "Physical";
    }
};

// Digital order class
class DigitalOrder : public Order {
public:
    DigitalOrder() {
        setState(new CreatedState());  // Set the initial state
    }

    DigitalOrder(int id) {
        setOrderId(id); // Устанавливаем идентификатор заказа
        setState(new CreatedState());
    }
    QString getOrderType() override {
        return "Digital";
    }
};

#endif // ORDER_H
