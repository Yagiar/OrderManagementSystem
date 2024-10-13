#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>
#include "orderstate.h"
#include "orderprocessingstrategy.h"

// Вперед объявляем классы OrderProcessingStrategy и OrderState
class OrderProcessingStrategy;
class OrderState;

extern QString username;

class Order {
private:
    OrderProcessingStrategy* processingStrategy;  // Стратегия для обработки заказа
    OrderState* state;
    int orderId;
    QString orderDescription;  // Исправлено на правильное написание переменной
    QList<Good> goods;
    QString username;

public:
    virtual ~Order();

    void setState(OrderState* newState);
    void setProcessingStrategy(OrderProcessingStrategy* strategy);
    int getOrderId() const;
    QString getUsername() const;
    void setUsername(const QString& username);
    void setOrderId(int id);
    QList<Good> getGoods() const;
    void setGoods(QList<Good>& goods);
    QString getOrderDescription() const;
    void setOrderDescription(const QString& description);
    void createOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods, QString& username);
    void updateOrder();
    void finishOrder();
    void processOrderAccordingStrategy();
    virtual QString getOrderType() const = 0; // Чисто виртуальный метод
};

class PhysicalOrder : public Order {
public:
    PhysicalOrder();
    PhysicalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, QList<Good> goods);
    QString getOrderType() const override; // Сделаем этот метод константным
};

class DigitalOrder : public Order {
public:
    DigitalOrder();
    DigitalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, QList<Good> goods);
    QString getOrderType() const override; // Сделаем этот метод константным
};

#endif // ORDER_H
