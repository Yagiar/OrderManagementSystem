#include "bagdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

BagDialog::BagDialog(QList<Good> *choosenGoods, QWidget *parent)
    : QDialog(parent), goods(choosenGoods)
{
      setWindowTitle("Корзина");

    // Создаем основной вертикальный layout для диалога
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Создаем ScrollArea
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true); // Позволяем содержимому менять размер

    // Создаем контейнер для товаров
    scrollContent = new QWidget();
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent); // Используем новый layout для ScrollArea

    // Заполняем список товаров в QListWidget
    for (const Good &good : *goods) {
        // Создаем контейнер для элемента списка и кнопки
        QWidget *itemWidget = new QWidget();
        QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);
        itemLayout->addWidget(new QLabel(good.getName() + " - " + QString::number(good.getPrice()) + "₽"));

        // Создаем кнопку "Удалить"
        QPushButton *removeButton = new QPushButton("Удалить", this);
        itemLayout->addWidget(removeButton);
        itemWidget->setLayout(itemLayout);

        // Добавляем контейнер в макет товаров
        goodsLayout->addWidget(itemWidget);

        // Обрабатываем удаление товара
        connect(removeButton, &QPushButton::clicked, [this, good, itemWidget]() {
            removeGood(good, itemWidget);
        });
    }

    scrollContent->setLayout(goodsLayout);
    scrollArea->setWidget(scrollContent); // Устанавливаем новый контейнер в ScrollArea

    // Добавляем ScrollArea в основной layout
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}

BagDialog::~BagDialog() {
    // Деструктор
}

void BagDialog::removeGood(const Good &good, QWidget *itemWidget) {
    // Удаляем товар из корзины
    goods->removeOne(good);

    // Удаляем элемент из ScrollArea
    delete itemWidget;
}
