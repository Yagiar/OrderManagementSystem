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

class Factory
{
public:
	virtual ~Factory() {};
	virtual Order* FactoryMethod() const = 0;

	void SomeOperation() const { // ������ ����� ��������� ������, �� ���� ������������� ��� ������ � ��� ������
		Order* Order = this->FactoryMethod();
		Order->processOrder();
		delete Order;
	}
};


class DigitalFactory : public Factory {
public:
	Order* FactoryMethod() const override {
		return new DigitalOrder();
	}
};

class PhysicalFactory : public Factory {
public:
	Order* FactoryMethod() const override {
		return new PhysicalOrder();
	}
};
