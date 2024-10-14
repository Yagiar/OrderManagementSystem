#include "orderlistwindow.h"
#include "ui_orderlistwindow.h"
#include "database.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItem>

OrderListWindow::OrderListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrderListWindow)
{
    ui->setupUi(this);
    resize(800, 600);
    setWindowTitle("Список заказов");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    tableView = new QTableView(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(8); // Увеличиваем количество столбцов
    model->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Username" << "Description" << "Order Type" << "ShowGoods" << "Strategy");

    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(tableView);

    closeButton = new QPushButton("Закрыть", this);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &QCoreApplication::quit);

    loadOrders();
}

OrderListWindow::~OrderListWindow()
{
    delete ui;
}

void OrderListWindow::loadOrders() {
    Database db;
    if (db.open()) {
        orders = db.getAllOrders(); // Получаем все заказы

        model->setRowCount(orders.size()); // Устанавливаем количество строк

        for (int i = 0; i < orders.size(); ++i) {
            Order* order = orders[i];
            model->setItem(i, 0, new QStandardItem(QString::number(order->getOrderId())));
            model->setItem(i, 1, new QStandardItem(order->getUsername()));
            model->setItem(i, 2, new QStandardItem(order->getOrderDescription()));
            model->setItem(i, 3, new QStandardItem(order->getOrderType()));
            model->setItem(i, 4, new QStandardItem(order->getState()->name));
            model->setItem(i, 5, new QStandardItem(order->getProcessingStrategy()->name));

            // Создаем кнопку "Показать товары"
            QPushButton *button = new QPushButton("Показать товары");
            tableView->setIndexWidget(model->index(i, 6), button);

            // Подключаем сигнал на нажатие кнопки
            connect(button, &QPushButton::clicked, [this, i]() {
                showOrderGoods(i);
            });

            // Создаем кнопку "Обработать заказ по стратегии"
            QPushButton *proccessOrderButton = new QPushButton("Обработать заказ по стратегии");
            tableView->setIndexWidget(model->index(i, 7), proccessOrderButton);

            connect(proccessOrderButton, &QPushButton::clicked, [this, i]() {
                processOrderForStrategyOnForm(i);
            });
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных.");
    }
}
void OrderListWindow::processOrderForStrategyOnForm(int row) {
    Order* selectedOrder = orders[row];

    // Инициализация фабрики в зависимости от типа заказа
    Factory* factory = nullptr;
    if (selectedOrder->getOrderType() == "Физический") {
        factory = new PhysicalFactory();
    } else if (selectedOrder->getOrderType() == "Цифровой") {
        factory = new DigitalFactory();
    }

    // Проверка фабрики
    if (factory) {
        // Создание заказа через фабрику
        OrderState* curState = selectedOrder->getState(); // Получаем текущее состояние заказа
        OrderProcessingStrategy* curStrategy = selectedOrder->getProcessingStrategy(); // Получаем текущую стратегию

        Order* order = factory->getExistOrder(
            selectedOrder->getOrderId(),
            curState,
            curStrategy,
            selectedOrder->getOrderDescription(),
            selectedOrder->getUsername(),
            selectedOrder->getGoods()
            );

        // Обрабатываем заказ с использованием стратегии
        if (order) {
            QString response = order->processOrderAccordingStrategy();
            QMessageBox::information(this, "Стратегия", response);
        }

        delete factory; // Освобождаем память
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать заказ через фабрику.");
    }
}


void OrderListWindow::showOrderGoods(int row) {
    Order* selectedOrder = orders[row];
    QList<Good> goodsList = selectedOrder->getGoods();
    QString goodsDetails = QString("Товары в заказе %1:\n").arg(selectedOrder->getOrderId());
    for (const Good& good : goodsList) {
        goodsDetails += "- " + good.getName() + "\n";
    }
    if (goodsList.isEmpty()) {
        goodsDetails = "Товары отсутствуют в данном заказе.";
    }
    QMessageBox::information(this, "Товары заказа", goodsDetails);
}
