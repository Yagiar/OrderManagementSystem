#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <QString>
#include "good.h"

// Forward declaration of the Order class to avoid circular dependency
class Order;

// Base class for order states
class OrderState {
public:
    virtual ~OrderState() {}

    // Virtual method to process an order
    virtual void changeState(Order* order, const QString& orderDescription,
                              int stateId, int priorityId, const QList<Good>& goods) = 0;
};

// Forward declaration of other states
class ProcessingState;
class CompletedState;

class CreatedState : public OrderState {
public:
    void changeState(Order* order, const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override;
};

class ProcessingState : public OrderState {
public:
    void changeState(Order* order, const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override;
};

class CompletedState : public OrderState {
public:
    void changeState(Order* order, const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override;
};

#endif // ORDERSTATE_H
