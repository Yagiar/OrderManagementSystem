#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем ScrollArea
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true); // Позволяем содержимому менять размер

    // Создаем контейнер для товаров
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent); // Используем новый layout для ScrollArea

    scrollContent->setLayout(goodsLayout);

    Database db;
    if (db.open()) {
        QList<Good> goods = db.getGoods();  // Получаем товары из базы

        foreach (const Good &good, goods) {
            // Создаем контейнер для товара
            QWidget *goodContainer = new QWidget();
            QVBoxLayout *goodLayout = new QVBoxLayout(goodContainer);

            // Название и цена товара
            QLabel *goodLabel = new QLabel(good.getName() + " - " + QString::number(good.getPrice()) + "₽");
            goodLayout->addWidget(goodLabel);

            // Описание товара
            QLabel *descriptionLabel = new QLabel(good.getDescription());
            descriptionLabel->setVisible(false); // Скрываем описание по умолчанию
            goodLayout->addWidget(descriptionLabel);

            // Кнопка для раскрытия/сворачивания описания
            QPushButton *toggleDescriptionButton = new QPushButton("Показать описание", this);
            toggleDescriptionButton->setFixedHeight(30);  // Устанавливаем фиксированную высоту
            goodLayout->addWidget(toggleDescriptionButton);

            // Кнопка "Добавить в заказ"
            QPushButton *addToOrderButton = new QPushButton("Добавить в заказ", this);
            addToOrderButton->setFixedHeight(30); // Устанавливаем фиксированную высоту
            goodLayout->addWidget(addToOrderButton);

            // Обработка клика по кнопке для раскрытия/сворачивания описания
            connect(toggleDescriptionButton, &QPushButton::clicked, this, [descriptionLabel, toggleDescriptionButton]() {
                bool isVisible = descriptionLabel->isVisible();
                descriptionLabel->setVisible(!isVisible);
                toggleDescriptionButton->setText(isVisible ? "Показать описание" : "Скрыть описание");
            });


            // Добавляем контейнер с товаром в макет товаров
            goodsLayout->addWidget(goodContainer);
        }
    }

    // Устанавливаем новый контейнер в ScrollArea
    scrollArea->setWidget(scrollContent);

    // Создаем основной макет для окна и добавляем ScrollArea в него
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea); // Добавляем ScrollArea в основной макет

}

MainWindow::~MainWindow()
{
    delete ui;
}
