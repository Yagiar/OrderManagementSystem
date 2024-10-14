#include "orderprocessingstrategy.h"
#include <QMessageBox>
QString RegularOrderProcessingStrategy::process(Order* order) {
    // Логика обработки обычного заказа
    return QString("Выполняется обработка обычного заказа");
}

QString ExpressOrderProcessingStrategy::process(Order* order) {
    // Логика обработки экспресс заказа
    return QString( "Выполняется обработка эксрпесс заказа");
}

QString CourierOrderProcessingStrategy::process(Order* order) {
    // Логика обработки для заказа курьером
    return QString("Выполняется обработка закза с курьером");
}
