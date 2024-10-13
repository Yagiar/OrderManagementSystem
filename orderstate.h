#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <QString>
#include <QList>
#include "good.h"

class Order;

class OrderState {
public:
    virtual ~OrderState() {}

    // Методы, которые могут быть унаследованы
    virtual void Create(Order* order, const QString& orderDescription,
                        int stateId, int priorityId, const QList<Good>& goods, QString& username) {}
    virtual void Update(Order* order) {}
    virtual void Finish(Order* order) {}
};

// Класс состояния Created
class CreatedState : public OrderState {
public:
    void Create(Order* order, const QString& orderDescription,
                int stateId, int priorityId, const QList<Good>& goods, QString& username) override;
};

// Класс состояния Processing
class ProcessingState : public OrderState {
public:
    void Update(Order* order) override;
};

// Класс состояния Completed
class CompletedState : public OrderState {
public:
    void Finish(Order* order) override;
};

#endif // ORDERSTATE_H
