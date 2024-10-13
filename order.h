#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>
#include "good.h"
#include "orderstate.h"

class OrderState;

extern QString username;

class Order {
private:
    OrderState* state;
     int orderId;

public:
    virtual ~Order() {
        delete state;
    }

    void setState(OrderState* newState) {
        delete state;
        state = newState;
    }

    int getOrderId() const {
        return orderId;
    }

    void setOrderId(int id) {
        orderId = id;
    }
    void processOrder() {

    }
    void CreateOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods){
        if (state) {
            state->Create(this, orderDescription, stateId, priorityId, goods);
        }
    }
    void UpdateOrder(){
        if(state)
        {
            state->Update(this);
        }
    }
    void FinishOrder(){
        if(state)
        {
            state->Finish(this);
        }
    }

    virtual QString getOrderType() = 0;
    QString getUsername() const { return username; }
};

class PhysicalOrder : public Order {
public:
    PhysicalOrder() {
        setState(new CreatedState());
    }

    PhysicalOrder(int id, OrderState* state) {
        setOrderId(id);
        setState(state);
    }

    QString getOrderType() override {
        return "Physical";
    }
};

// Digital order class
class DigitalOrder : public Order {
public:
    DigitalOrder() {
        setState(new CreatedState());
    }

    DigitalOrder(int id, OrderState* state) {
        setOrderId(id);
        setState(state);
    }
    QString getOrderType() override {
        return "Digital";
    }
};

#endif // ORDER_H
