#include "orderprocessingstrategy.h"

void RegularOrderProcessingStrategy::process(Order* order) {
    // Логика обработки обычного заказа
    qDebug() << "Обычная стратегия" << order->getOrderId();
}

void ExpressOrderProcessingStrategy::process(Order* order) {
    // Логика обработки экспресс заказа
    qDebug() << "Экспресс стратегия" << order->getOrderId();
}

void CourierOrderProcessingStrategy::process(Order* order) {
    // Логика обработки для заказа курьером
    qDebug() << "Курьер стратегия" << order->getOrderId() << "по почте";
}
