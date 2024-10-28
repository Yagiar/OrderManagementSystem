#ifndef PAYMENTSYSTEMADAPTER_H
#define PAYMENTSYSTEMADAPTER_H

#include <QString>
#include <QDebug>

class PaymentSystemAdapter {
public:
    virtual ~PaymentSystemAdapter() = default;
    virtual bool pay(double amount) = 0;
    virtual QString GetPaymentSystemName() = 0;
};

// Адаптер для СБП
class SBPAdapter : public PaymentSystemAdapter {
public:

    bool pay(double amount) override {
        if(true)         // Здесь должна быть логика взаимодействия с API SBP
            return true;
        else
            return false;
        qDebug() << "SBPAdapter: Платеж " + QString::number(amount, 'f', 2) + " руб. через СБП успешно проведен!";
    }

    QString GetPaymentSystemName() override {
        return "СБП";
    }
};

// Адаптер для СберPay
class SberPayAdapter : public PaymentSystemAdapter {
public:

    bool pay(double amount) override {
        if(true)         // Здесь должна быть логика взаимодействия с API SBERPAY
            return true;
        else
            return false;
        qDebug() << "SberPayAdapter: Платеж " + QString::number(amount, 'f', 2) + " руб. через СберPay успешно проведен!";
    }

    QString GetPaymentSystemName() override {
        return "СБЕР";
    }
};

// Адаптер для Яндекс.Pay
class YandexPayAdapter : public PaymentSystemAdapter {
public:

    bool pay(double amount) override {
        if(true)         // Здесь должна быть логика взаимодействия с API YANDEXPAY
            return true;
        else
            return false;
         qDebug() << "YandexPayAdapter: Платеж " + QString::number(amount, 'f', 2) + " руб. через Яндекс.Pay успешно проведен!";
    }

    QString GetPaymentSystemName() override {
        return "ЯНДЕКС";
    }
};

#endif // PAYMENTSYSTEMADAPTER_H
