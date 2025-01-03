#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <QString>
#include <QList>
#include "good.h"
#include "paymentsystemadapter.h"

class Order;

class OrderState {
public:
    virtual ~OrderState() {}
    QString name;
    // Методы, которые могут быть унаследованы
    virtual void Create(Order* order, const QString& orderDescription,
                        int stateId, int priorityId, const QList<Good>& goods, QString& username, PaymentSystemAdapter* paymentSystem) {}
    virtual void Update(Order* order) {}
    virtual void Finish(Order* order) {}
};

// Класс состояния Created
class CreatedState : public OrderState {
public:
    CreatedState()
    {
        this->name = "Принят";
    }
    void Create(Order* order, const QString& orderDescription,
                int stateId, int priorityId, const QList<Good>& goods, QString& username, PaymentSystemAdapter* paymentSystem) override;
};

// Класс состояния Processing
class ProcessingState : public OrderState {
public:
    ProcessingState()
    {
        this->name = "В обработке";
    }
    void Update(Order* order) override;

};

// Класс состояния Completed
class CompletedState : public OrderState {
public:
    CompletedState()
    {
        this->name = "Выполнен";
    }
    void Finish(Order* order) override;
};

#endif // ORDERSTATE_H
