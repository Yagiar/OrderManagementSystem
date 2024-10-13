#ifndef GOOD_H
#define GOOD_H

#include <QString>
#include <iostream>

class Good {
public:
    Good(int id, const QString& name, int categoryId, double price, const QString& description, double weight)
        : id(id), name(name), categoryId(categoryId), price(price), description(description), weight(weight) {}

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
