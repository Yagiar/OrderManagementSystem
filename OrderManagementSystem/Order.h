

#include <iostream>
class Order {
public:
	virtual ~Order() {}
	virtual void processOrder() = 0;
};

class PhysicalOrder : public Order {
public:
	void processOrder() override {
		std::cout << "Processing physical order..." << std::endl;
	}
};

class DigitalOrder : public Order {
public:
	void processOrder() override {
		std::cout << "Processing digital order..." << std::endl;
	}
};

class Creator
{
public:
	virtual ~Creator() {};
	virtual Order* FactoryMethod() const = 0;

	void SomeOperation() const { // просто метод обработки заказа, то есть инкапсулируем наш объект и его методы
		Order* Order = this->FactoryMethod();
		Order->processOrder();
		delete Order;
	}
};


class DigitalFactory : public Creator {
public:
	Order* FactoryMethod() const override {
		return new DigitalOrder();
	}
};

class PhysicalFactory : public Creator {
public:
	Order* FactoryMethod() const override {
		return new PhysicalOrder();
	}
};
