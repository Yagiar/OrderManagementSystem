#include "createorderdialog.h"
#include "ui_createorderdialog.h"
#include "good.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

CreateOrderDialog::CreateOrderDialog(QList<Good> *choosenGoods, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateOrderDialog)
    , goods(choosenGoods)
{
    setWindowTitle("Оформление заказа");
    ui->setupUi(this);

    // Создаем контейнер для товаров
    QWidget *scrollContent = new QWidget(this);
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent);

    double totalPrice = 0.0; // Сумма заказа

    // Заполняем ScrollArea товарами из choosenGoods
    for (int i = 0; i < goods->count(); ++i) {
        const Good &good = goods->at(i);

        // Создаем виджет для отображения товара
        QLabel *goodLabel = new QLabel(QString::number(i + 1) + ". " +
                                           good.getName() + " - " +
                                           QString::number(good.getPrice()) + "₽", this);
        goodsLayout->addWidget(goodLabel);

        // Увеличиваем общую цену
        totalPrice += good.getPrice();
    }

    // Добавляем общий прайс
    QLabel *totalPriceLabel = new QLabel("Общая сумма заказа: " + QString::number(totalPrice) + "₽", this);
    goodsLayout->addWidget(totalPriceLabel);

    // Устанавливаем Layout в scrollAreaGoods
    scrollContent->setLayout(goodsLayout);
    ui->scrollAreaGoods->setWidget(scrollContent); // Используем ваш существующий scrollArea
}

CreateOrderDialog::~CreateOrderDialog()
{
    delete ui;
}
