#ifndef GOOD_H
#define GOOD_H

#include <QString>
#include <iostream>

class Good {
public:
    // Конструктор с параметрами для инициализации товара
    Good(int id, const QString& name, int categoryId, double price, const QString& description, double weight)
        : id(id), name(name), categoryId(categoryId), price(price), description(description), weight(weight) {}

    // Геттеры для получения данных
    int getId() const {
        return id;
    }

    QString getName() const {
        return name;
    }

    int getCategoryId() const {
        return categoryId;
    }

    double getPrice() const {
        return price;
    }

    QString getDescription() const {
        return description;
    }

    double getWeight() const {
        return weight;
    }

    bool operator==(const Good &other) const {
        return this->id == other.id;  // Например, сравнение по ID
    }

private:
    int id;               // Уникальный идентификатор товара
    QString name;         // Название товара
    int categoryId;       // Идентификатор категории товара
    double price;         // Цена товара
    QString description;  // Описание товара
    double weight;        // Вес товара
};

#endif // GOOD_H
