#include "order.h"
#include <QDebug>

Order::~Order() {
    delete state;
    delete processingStrategy;  // Освобождаем память
}

void Order::setState(OrderState* newState) {
    if (newState != nullptr) {
        // delete state;  // Удаление предыдущего состояния, если нужно, следует сделать перед установкой нового
        state = newState;
    }
}

void Order::setProcessingStrategy(OrderProcessingStrategy* strategy) {
    if (processingStrategy != nullptr) {
        //delete processingStrategy;  // Освобождаем предыдущую стратегию
    }
    processingStrategy = strategy;
}

int Order::getOrderId() const {
    return orderId; // Получаем ID заказа
}

QString Order::getUsername() const {
    return username;
}

void Order::setUsername(const QString& username) {
    this->username = username;
}

void Order::setOrderId(int id) {
    orderId = id; // Устанавливаем ID заказа
}

QList<Good> Order::getGoods() const {
    return this->goods;
}

void Order::setGoods(QList<Good>& goods) {
    this->goods = goods;
}

QString Order::getOrderDescription() const {
    return orderDescription; // Возвращаем описание заказа
}

void Order::setOrderDescription(const QString& description) {
    orderDescription = description; // Устанавливаем описание заказа
}

void Order::createOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods, QString& username) {
    if (state) {
        state->Create(this, orderDescription, stateId, priorityId, goods, username); // Вызываем метод состояния
    }
}

void Order::updateOrder() {
    if (state) {
        state->Update(this); // Вызываем метод обновления состояния
    }
}

void Order::finishOrder() {
    if (state) {
        state->Finish(this); // Вызываем метод завершения состояния
    }
}

void Order::processOrderAccordingStrategy() {
    if (processingStrategy != nullptr) {
        processingStrategy->process(this);  // Применяем стратегию для обработки
    }
}

// Реализация методов PhysicalOrder
PhysicalOrder::PhysicalOrder() {
    setState(new CreatedState()); // Устанавливаем начальное состояние
}

PhysicalOrder::PhysicalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, QList<Good> goods) {
    setOrderId(id);
    setOrderDescription(orderDescription); // Устанавливаем описание заказа
    setState(state); // Устанавливаем состояние
    setUsername(username);
    setGoods(goods);
    setProcessingStrategy(strategy);
}

QString PhysicalOrder::getOrderType() const {
    return "Физический"; // Тип заказа
}

// Реализация методов DigitalOrder
DigitalOrder::DigitalOrder() {
    setState(new CreatedState()); // Устанавливаем начальное состояние
}

DigitalOrder::DigitalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, QList<Good> goods) {
    setOrderId(id);
    setOrderDescription(orderDescription); // Устанавливаем описание заказа
    setState(state); // Устанавливаем состояние
    setUsername(username);
    setGoods(goods);
    setProcessingStrategy(strategy);
}

QString DigitalOrder::getOrderType() const {
    return "Цифровой"; // Тип заказа
}
