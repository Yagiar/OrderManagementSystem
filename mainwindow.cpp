#include "mainwindow.h"
#include "database.h"
#include <QPushButton>  // Add this line
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "bagdialog.h"
#include "createorderdialog.h"

extern QString username;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), countGoods(0), choosenGoods(new QList<Good>())
{
    setWindowTitle("Основное окно");

    // Создаем центральный виджет и устанавливаем его для MainWindow
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем главный вертикальный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Создаем QLabel для отображения количества товаров
    QLabel *label = new QLabel("Количество товаров в текущем заказе:", this);
    mainLayout->addWidget(label);

    // QLabel для отображения количества товаров
    QLabel *labelCountGoods = new QLabel("0", this);
    mainLayout->addWidget(labelCountGoods);

    // Создаем ScrollArea для товаров
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);

    // Создаем контейнер для ScrollArea
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(goodsLayout);
    scrollArea->setWidget(scrollContent);

    // Кнопка "Показать корзину"
    QPushButton *butShowCurBag = new QPushButton("Показать корзину", this);
    mainLayout->addWidget(butShowCurBag);

    // Кнопка "Заказать"
    QPushButton *butCreateOrder = new QPushButton("Заказать", this);
    mainLayout->addWidget(butCreateOrder);

    // Подключаем сигналы к слотам
    connect(butShowCurBag, &QPushButton::clicked, this, &MainWindow::on_butShowCurBag_clicked);
    connect(butCreateOrder, &QPushButton::clicked, this, &MainWindow::on_butCreateOrder_clicked);

    // Получаем товары из базы
    Database db;
    if (db.open()) {
        QList<Good> goods = db.getGoods();

        foreach (const Good &good, goods) {
            // Создаем контейнер для товара
            QWidget *goodContainer = new QWidget();
            QVBoxLayout *goodLayout = new QVBoxLayout(goodContainer);

            // Название и цена товара
            QLabel *goodLabel = new QLabel(good.getName() + " - " + QString::number(good.getPrice()) + "₽", this);
            goodLayout->addWidget(goodLabel);

            // Описание товара
            QLabel *descriptionLabel = new QLabel(good.getDescription(), this);
            descriptionLabel->setVisible(false); // Скрываем описание по умолчанию
            goodLayout->addWidget(descriptionLabel);

            // Кнопка для раскрытия/сворачивания описания
            QPushButton *toggleDescriptionButton = new QPushButton("Показать описание", this);
            goodLayout->addWidget(toggleDescriptionButton);

            // Кнопка "Добавить в заказ"
            QPushButton *addToOrderButton = new QPushButton("Добавить в заказ", this);
            goodLayout->addWidget(addToOrderButton);

            // Обработка клика по кнопке для раскрытия/сворачивания описания
            connect(toggleDescriptionButton, &QPushButton::clicked, this, [descriptionLabel, toggleDescriptionButton]() {
                bool isVisible = descriptionLabel->isVisible();
                descriptionLabel->setVisible(!isVisible);
                toggleDescriptionButton->setText(isVisible ? "Показать описание" : "Скрыть описание");
            });

            // Обработка клика по кнопке "Добавить в заказ"
            connect(addToOrderButton, &QPushButton::clicked, [this, good, labelCountGoods]() {
                choosenGoods->append(good);
                labelCountGoods->setText(QString::number(choosenGoods->count()));
                QMessageBox::information(this, "Добавлено в заказ", "Товар с ID " + QString::number(good.getId()) + " добавлен в заказ!");
            });

            // Добавляем контейнер с товаром в макет товаров
            goodsLayout->addWidget(goodContainer);
        }
    }
}

MainWindow::~MainWindow()
{
    delete choosenGoods;
}

void MainWindow::on_butShowCurBag_clicked() {
    BagDialog *bagDialog = new BagDialog(choosenGoods, this);
    bagDialog->exec();
}

void MainWindow::on_butCreateOrder_clicked() {
    CreateOrderDialog *cr = new CreateOrderDialog(choosenGoods, this);
    cr->exec();
}
