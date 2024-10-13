#ifndef FACTORY_H
#define FACTORY_H
#include "order.h"
#include "good.h"

class Factory {
public:
    virtual ~Factory() {};

    void CreationOfOrder(const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) {
        Order* order = this->CreateOrder();
        order->CreateOrder(orderDescription, stateId,priorityId,goods);

        delete order;
    }
    Order* GetExistOrder(const int OrderId, OrderState* state) {
        return this->CreateOrder(OrderId, state);
    }
private:
        virtual Order* CreateOrder() = 0;
        virtual Order* CreateOrder(const int OrderId, OrderState* state) = 0;
       // virtual Order* GetOrder(const int  OrderId, const int stateId, const int priorityId,const QString& OrderType,
       //                            const QString& orderDescription, const QList<Good>& goods );
};

class DigitalFactory : public Factory {
public:
    Order* CreateOrder() override {
        return new DigitalOrder();
    }
    Order* CreateOrder(const int OrderId, OrderState* state) override
    {
        return new DigitalOrder(OrderId,state);
    }
};

class PhysicalFactory : public Factory {
public:
    Order* CreateOrder() override {
        return new PhysicalOrder();
    }
    Order* CreateOrder(const int OrderId, OrderState* state) override
    {
        return new DigitalOrder(OrderId, state);
    }
};
#endif // FACTORY_H
