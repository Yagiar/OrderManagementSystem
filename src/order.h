#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>
#include "orderstate.h"
#include "orderprocessingstrategy.h"
#include "good.h"
#include "PaymentSystemAdapter.h"

class Visitor;
// Вперед объявляем классы OrderProcessingStrategy и OrderState
class OrderProcessingStrategy;
class OrderState;

extern QString username;

class Order {
private:
    OrderProcessingStrategy* processingStrategy;
    OrderState* state;
    int orderId;
    QString orderDescription;
    QList<Good> goods;
    QString username;

public:
    virtual ~Order();

    void setState(OrderState* newState);
    OrderState* getState();
    void setProcessingStrategy(OrderProcessingStrategy* strategy);
    OrderProcessingStrategy* getProcessingStrategy();
    int getOrderId() const;
    QString getUsername() const;
    void setUsername(const QString& username);
    void setOrderId(int id);
    QList<Good> getGoods() const;
    void setGoods(const QList<Good>& goods);
    QString getOrderDescription() const;
    void setOrderDescription(const QString& description);
    void createOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods, QString& username, PaymentSystemAdapter* paymentSystem);
    void updateOrder();
    void finishOrder();
    QString processOrderAccordingStrategy();
    virtual QString getOrderType() const = 0;
    bool pay(PaymentSystemAdapter* adapter, double amount);
    void Accept(Visitor *visitor);
    // Конструктор базового класса
    Order(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username,  const QList<Good>& goods);
};

class PhysicalOrder : public Order {
public:
    PhysicalOrder();
    PhysicalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, const QList<Good>& goods);
    QString getOrderType() const override;
};

class DigitalOrder : public Order {
public:
    DigitalOrder();
    DigitalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, const QList<Good>& goods);
    QString getOrderType() const override;
};

#endif // ORDER_H
