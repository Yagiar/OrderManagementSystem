#include "orderstate.h"
#include "order.h"
#include "database.h"
#include <QDebug>

void CreatedState::Create(Order* order, const QString& orderDescription,
                                int stateId, int priorityId, const QList<Good>& goods, QString& username, PaymentSystemAdapter* paymentSystem) {
    Database db;
    if (db.open()) {
        if(order->pay(paymentSystem,100.00))
        {
            db.InsertOrder(db.GetUserIdByUsername(username), orderDescription, order->getOrderType(), stateId, priorityId, goods, paymentSystem);
            order->setState(new CreatedState(QString::number(1)));
        }
        else
        {
            qDebug() << "Please paid for order." ;
        }
    } else {
        qDebug() << "Database connection error.";
    }
}

void ProcessingState::Update(Order* order) {
    Database db;
    if (db.open()) {
        db.UpdateOrderState(order->getOrderId(), 2);
        order->setState(new ProcessingState(QString::number(2)));
    } else {
        qDebug() << "Database connection error.";
    }
}

void CompletedState::Finish(Order* order) {
    Database db;
    if (db.open()) {
        db.UpdateOrderState(order->getOrderId(), 3);
        order->setState(new CompletedState(QString::number(3)));
    } else {
        qDebug() << "Database connection error.";
    }
}

