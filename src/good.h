#ifndef GOOD_H
#define GOOD_H

#include <QString>
#include <iostream>

class Good {
public:
    // Конструктор по умолчанию
    Good() : id(0), name(""), categoryId(0), price(0.0), description(""), weight(0.0) {}

    // Конструктор с параметрами
    Good(int id, const QString& name, int categoryId, double price, const QString& description, double weight)
        : id(id), name(name), categoryId(categoryId), price(price), description(description), weight(weight) {}

    // Геттеры
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

    // Сеттеры (при необходимости)
    void setId(int id) {
        this->id = id;
    }

    void setName(const QString& name) {
        this->name = name;
    }

    void setCategoryId(int categoryId) {
        this->categoryId = categoryId;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setDescription(const QString& description) {
        this->description = description;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }

    // Оператор сравнения
    bool operator==(const Good &other) const {
        return this->id == other.id;
    }

private:
    int id;
    QString name;
    int categoryId;
    double price;
    QString description;
    double weight;
};

#endif // GOOD_H
