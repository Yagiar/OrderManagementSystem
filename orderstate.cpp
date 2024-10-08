#include "orderstate.h"
#include "order.h"
#include "database.h"
#include <QDebug>

void CreatedState::changeState(Order* order, const QString& orderDescription,
                                int stateId, int priorityId, const QList<Good>& goods) {
    Database db;
    if (db.open()) {
        db.InsertOrder(db.GetUserIdByUsername(order->getUsername()), orderDescription, order->getOrderType(), stateId, priorityId, goods);
        order->setState(new CreatedState ());
    } else {
        qDebug() << "Database connection error.";
    }
}

// Implementation of ProcessingState
void ProcessingState::changeState(Order* order, const QString& orderDescription,
                                   int stateId, int priorityId, const QList<Good>& goods) {
    Database db;
    if (db.open()) {
        db.UpdateOrderState(order->getOrderId(), 2);
        order->setState(new ProcessingState());
    } else {
        qDebug() << "Database connection error.";
    }
}

// Implementation of CompletedState
void CompletedState::changeState(Order* order, const QString& orderDescription,
                                  int stateId, int priorityId, const QList<Good>& goods) {
    Database db;
    if (db.open()) {
        db.UpdateOrderState(order->getOrderId(), 3);
        order->setState(new CompletedState());
    } else {
        qDebug() << "Database connection error.";
    }
}

