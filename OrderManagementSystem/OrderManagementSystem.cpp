#include <iostream>

#include "Order.h"

int main()
{
    // Создание фабрики для цифровых заказов
    Factory* digitalFactory = new DigitalFactory();
    digitalFactory->SomeOperation();  // Обрабатываем цифровой заказ

    // Создание фабрики для физических заказов
    Factory* physicalFactory = new PhysicalFactory();
    physicalFactory->SomeOperation();  // Обрабатываем физический заказ

    // Очистка ресурсов
    delete digitalFactory;
    delete physicalFactory;

    return 0;
}
