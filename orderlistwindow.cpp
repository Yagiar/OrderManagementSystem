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

    // Устанавливаем размер окна
    resize(800, 600);
    setWindowTitle("Список заказов");

    // Создаем центральный виджет и компоновку
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Создаем таблицу для отображения заказов
    tableView = new QTableView(this);
    model = new QStandardItemModel(this);

    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Username" << "Description" << "Order Type");

    // Устанавливаем модель для таблицы
    tableView->setModel(model);

    // Установка адаптивного размера столбцов
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Добавляем таблицу на компоновку
    layout->addWidget(tableView);

    // Создаем кнопку закрытия
    closeButton = new QPushButton("Закрыть", this);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &QMainWindow::close);

    // Заполняем таблицу данными
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
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных.");
    }
}


