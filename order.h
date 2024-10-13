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
    QString orderDescription;  // Исправлено на правильное написание переменной
    QList<Good> goods;
    Order* curOrder;
public:
    virtual ~Order() {
        delete state; // Освобождаем память для состояния
    }

    void setState(OrderState* newState) {
        delete state; // Освобождаем память для предыдущего состояния
        state = newState; // Устанавливаем новое состояние
    }

    int getOrderId() const {
        return orderId; // Получаем ID заказа
    }

    void setOrderId(int id) {
        orderId = id; // Устанавливаем ID заказа
    }

    QString getOrderDescription() const {
        return orderDescription; // Возвращаем описание заказа
    }

    void setOrderDescription(const QString& description) {
        orderDescription = description; // Устанавливаем описание заказа
    }
    // Метод для создания заказа
    void createOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods) {
        if (state) {
            state->Create(this, orderDescription, stateId, priorityId, goods); // Вызываем метод состояния
        }
    }
    void updateOrder() {
        if (state) {
            state->Update(this); // Вызываем метод обновления состояния
        }
    }

    void finishOrder() {
        if (state) {
            state->Finish(this); // Вызываем метод завершения состояния
        }
    }

    virtual QString getOrderType() const = 0; // Сделаем этот метод константным
    QString getUsername() const { return username; } // Получаем имя пользователя
};

class PhysicalOrder : public Order {
public:
    PhysicalOrder() {
        setState(new CreatedState()); // Устанавливаем начальное состояние
    }

    PhysicalOrder(int id, OrderState* state, const QString& orderDescription) {
        setOrderId(id);
        setOrderDescription(orderDescription); // Устанавливаем описание заказа
        setState(state); // Устанавливаем состояние
    }

    QString getOrderType() const override { // Сделаем этот метод константным
        return "Physical"; // Тип заказа
    }
};

class DigitalOrder : public Order {
public:
    DigitalOrder() {
        setState(new CreatedState()); // Устанавливаем начальное состояние
    }

    DigitalOrder(int id, OrderState* state, const QString& orderDescription) {
        setOrderId(id);
        setOrderDescription(orderDescription); // Устанавливаем описание заказа
        setState(state); // Устанавливаем состояние
    }

    QString getOrderType() const override { // Сделаем этот метод константным
        return "Digital"; // Тип заказа
    }
};

#endif // ORDER_H
