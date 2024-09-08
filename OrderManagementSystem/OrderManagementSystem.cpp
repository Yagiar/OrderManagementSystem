#include <iostream>

#include "Order.h"

int main()
{
    // Создание фабрики для цифровых заказов
    Creator* digitalFactory = new DigitalFactory();
    digitalFactory->SomeOperation();  // Обрабатываем цифровой заказ

    // Создание фабрики для физических заказов
    Creator* physicalFactory = new PhysicalFactory();
    physicalFactory->SomeOperation();  // Обрабатываем физический заказ

    // Очистка ресурсов
    delete digitalFactory;
    delete physicalFactory;

    return 0;
}
