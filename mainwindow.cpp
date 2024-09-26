#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QMessageBox>
#include "bagdialog.h"
#include "createorderdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow), countGoods(0), choosenGoods(new QList<Good>())
{
    ui->setupUi(this);
      setWindowTitle("Основное окно");
    // Устанавливаем ScrollArea
    QScrollArea *scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true); // Позволяем содержимому менять размер

    // Создаем контейнер для товаров
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent); // Используем новый layout для ScrollArea

    scrollContent->setLayout(goodsLayout);
    scrollArea->setWidget(scrollContent); // Устанавливаем новый контейнер в ScrollArea

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

            // Обработка клика по кнопке "Добавить в заказ"
            connect(addToOrderButton, &QPushButton::clicked, [this, good]() {
                // Получаем ID товара
                int goodId = good.getId();

                QString message = "Товар с ID " + QString::number(goodId) + " добавлен в заказ!";
                QMessageBox::information(this, "Добавлено в заказ", message);

                choosenGoods->append(good);
                ui->labelCountGoods->setText(QString::number(choosenGoods->count()));
            });

            // Добавляем контейнер с товаром в макет товаров
            goodsLayout->addWidget(goodContainer);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete choosenGoods;
}

void MainWindow::on_butShowCurBag_clicked() {

    // qDebug() << "Number of items in choosenGoods: " << choosenGoods->count();
    BagDialog *bagDialog = new BagDialog(choosenGoods, this);
    bagDialog->exec();

    // После закрытия обновляем количество товаров в корзине
    ui->labelCountGoods->setText(QString::number(choosenGoods->count()));
}


void MainWindow::on_butCreateOrder_clicked()
{
    CreateOrderDialog *cr = new CreateOrderDialog(choosenGoods, this);
    cr->exec();
}

