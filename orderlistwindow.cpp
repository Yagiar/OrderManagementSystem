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
    model->setColumnCount(5); // Увеличиваем количество столбцов
    model->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Username" << "Description" << "Order Type" << "Actions");

    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(tableView);

    closeButton = new QPushButton("Закрыть", this);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &QMainWindow::close);

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

            // Создаем кнопку "Показать товары"
            QPushButton *button = new QPushButton("Показать товары");
            tableView->setIndexWidget(model->index(i, 4), button);

            // Подключаем сигнал на нажатие кнопки
            connect(button, &QPushButton::clicked, [this, i]() {
                showOrderGoods(i);
            });
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных.");
    }
}

void OrderListWindow::showOrderGoods(int row) {
    Order* selectedOrder = orders[row];
    QList<Good> goodsList = selectedOrder->getGoods();
    QString goodsDetails = "Товары в заказе:\n";
    for (const Good& good : goodsList) {
        goodsDetails += "- " + good.getName() + "\n";
    }
    if (goodsList.isEmpty()) {
        goodsDetails = "Товары отсутствуют в данном заказе.";
    }
    QMessageBox::information(this, "Товары заказа", goodsDetails);
}
