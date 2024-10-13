#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <QString>
#include "good.h"

class Order;

class OrderState {
public:
    virtual ~OrderState() {}

    virtual void Create(Order* order, const QString& orderDescription,
                              int stateId, int priorityId, const QList<Good>& goods) = 0;
    virtual void Update(Order* order) = 0;
    virtual void Finish(Order* order) = 0;
};

class ProcessingState;
class CompletedState;

class CreatedState : public OrderState {
public:
    void Create(Order* order, const QString& orderDescription,
                      int stateId, int priorityId, const QList<Good>& goods) override;
    void Update(Order* order) override;
    virtual void Finish(Order* order) override;

};

class ProcessingState : public OrderState {
public:
    void Create(Order* order, const QString& orderDescription,
                int stateId, int priorityId, const QList<Good>& goods) override;
    void Update(Order* order) override;
    virtual void Finish(Order* order) override;};

class CompletedState : public OrderState {
public:
    void Create(Order* order, const QString& orderDescription,
                int stateId, int priorityId, const QList<Good>& goods) override;
    void Update(Order* order) override;
    virtual void Finish(Order* order) override;};

#endif // ORDERSTATE_H
