#include "order.h"
#include <QDebug>
#include "Visitor.h"

Order::~Order() {
    delete state;
    delete processingStrategy;  // Освобождаем память
}
Order::Order(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, const QList<Good>& goods)
    : processingStrategy(strategy)
    , state(state)
    , orderId(id)
    , orderDescription(orderDescription)
    , goods(goods)
    , username(username)
{
    // Дополнительная инициализация, если требуется
}
void Order::setState(OrderState* newState) {
    if (newState != nullptr) {
        state = newState;
        qDebug() << "Установлено новое состояние для заказа " << orderId;
    } else {
        qDebug() << "Ошибка: не удалось установить состояние для заказа " << orderId;
    }
}
OrderState* Order::getState()
{
    return state;
}
void Order::setProcessingStrategy(OrderProcessingStrategy* strategy) {
    if (strategy != nullptr) {
        processingStrategy = strategy;
        qDebug() << "Установлена новая стратегия для заказа "<< processingStrategy->name <<" " << orderId;
    } else {
        qDebug() << "Ошибка: не удалось установить стратегию для заказа " << orderId;
    }
}

OrderProcessingStrategy* Order::getProcessingStrategy()
{
    return processingStrategy;
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

void Order::setGoods(const QList<Good>& goods) {
    this->goods = goods;
}

QString Order::getOrderDescription() const {
    return orderDescription; // Возвращаем описание заказа
}

void Order::setOrderDescription(const QString& description) {
    orderDescription = description; // Устанавливаем описание заказа
}

void Order::createOrder(const QString& orderDescription, int stateId, int priorityId, const QList<Good>& goods, QString& username, PaymentSystemAdapter* paymentSystem) {
    if (state) {
        state->Create(this, orderDescription, stateId, priorityId, goods, username, paymentSystem); // Вызываем метод состояния
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

QString Order::processOrderAccordingStrategy() {
    if(processingStrategy != nullptr){
        return processingStrategy->process(this);
    }
    else
    {
        return "";
    }
         // Применяем стратегию для обработки
}

bool Order::pay(PaymentSystemAdapter* adapter, double amount) {
    if (adapter) {
        return adapter->pay(amount); // Вызов метода pay у адаптера
    }
    else
        return false;
}

void Order::Accept(Visitor *visitor){
    visitor->VisitOrder(this);
}

// Реализация методов PhysicalOrder
PhysicalOrder::PhysicalOrder()
    : Order(0, new CreatedState(), nullptr, "", "", {})
{
     setState(new CreatedState());
}

PhysicalOrder::PhysicalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, const QList<Good>& goods)
    : Order(id, state, strategy, orderDescription, username, goods){
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
DigitalOrder::DigitalOrder()
    : Order(0, new CreatedState(), nullptr, "", "", {})
{
    setState(new CreatedState()); // Устанавливаем начальное состояние
}

DigitalOrder::DigitalOrder(int id, OrderState* state, OrderProcessingStrategy* strategy, const QString& orderDescription, const QString& username, const QList<Good>& goods)
    : Order(id, state, strategy, orderDescription, username, goods)
{    setOrderId(id);
    setOrderDescription(orderDescription); // Устанавливаем описание заказа
    setState(state); // Устанавливаем состояние
    setUsername(username);
    setGoods(goods);
    setProcessingStrategy(strategy);
}

QString DigitalOrder::getOrderType() const {
    return "Цифровой"; // Тип заказа
}
