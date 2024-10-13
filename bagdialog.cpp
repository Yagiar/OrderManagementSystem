#include "bagdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

BagDialog::BagDialog(QList<Good> *choosenGoods, QWidget *parent)
    : QDialog(parent), goods(choosenGoods)
{
      setWindowTitle("Корзина");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // Создаем контейнер для товаров
    scrollContent = new QWidget();
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent);

    for (const Good &good : *goods) {

        QWidget *itemWidget = new QWidget();
        QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);
        itemLayout->addWidget(new QLabel(good.getName() + " - " + QString::number(good.getPrice()) + "₽"));

        QPushButton *removeButton = new QPushButton("Удалить", this);
        itemLayout->addWidget(removeButton);
        itemWidget->setLayout(itemLayout);

        goodsLayout->addWidget(itemWidget);

        connect(removeButton, &QPushButton::clicked, [this, good, itemWidget]() {
            removeGood(good, itemWidget);
        });
    }

    scrollContent->setLayout(goodsLayout);
    scrollArea->setWidget(scrollContent);

    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}

BagDialog::~BagDialog() {

}

void BagDialog::removeGood(const Good &good, QWidget *itemWidget) {

    goods->removeOne(good);

    delete itemWidget;
}
