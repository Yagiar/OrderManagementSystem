#include "orderlistwindow.h"
#include "ui_orderlistwindow.h"
#include "database.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItem>
#include "changestateform.h"
#include <QCloseEvent>
#include <QCoreApplication>
#include "orderstatehandler.h"
#include "visitor.h"

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

    // Создаем и настраиваем комбобокс
    exportVariantComboBox = new QComboBox(this);
    exportVariantComboBox->addItem("XML");
    exportVariantComboBox->addItem("JSON");

    // Создаем и настраиваем кнопку экспорта
    exportOrdersButton = new QPushButton("Экспортировать заказы", this);
    connect(exportOrdersButton, &QPushButton::clicked, this, &OrderListWindow::exportOrdersOnForm);

    // Добавляем комбобокс и кнопку в макет
    layout->addWidget(exportVariantComboBox);
    layout->addWidget(exportOrdersButton);

    tableView = new QTableView(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(11); // Увеличиваем количество столбцов
    model->setHorizontalHeaderLabels(QStringList() << "Флаг" << "Номер заказа" << "Пользователь" << "Описание" << "Тип заказа"
                                                   << "Состояние" << "Стратегия" << "Оплата" << "Показать товары" << "Обработать" << "Поменять состояние");

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

            QStandardItem *checkBoxItem = new QStandardItem();
            checkBoxItem->setCheckable(true);
            model->setItem(i, 0, checkBoxItem);

            model->setItem(i, 1, new QStandardItem(QString::number(order->getOrderId())));
            model->setItem(i, 2, new QStandardItem(order->getUsername()));
            model->setItem(i, 3, new QStandardItem(order->getOrderDescription()));
            model->setItem(i, 4, new QStandardItem(order->getOrderType()));
            model->setItem(i, 5, new QStandardItem(order->getState()->name));
            model->setItem(i, 6, new QStandardItem(order->getProcessingStrategy()->name));
            model->setItem(i, 7, new QStandardItem(db.GetStatusPaidByOrderId(order->getOrderId())));

            // Создаем кнопку "Показать товары"
            QPushButton *button = new QPushButton("Показать товары");
            tableView->setIndexWidget(model->index(i, 8), button);

            // Подключаем сигнал на нажатие кнопки
            connect(button, &QPushButton::clicked, [this, i]() {
                showOrderGoods(i);
            });

            // Создаем кнопку "Обработать заказ по стратегии"
            QPushButton *proccessOrderButton = new QPushButton("Обработать заказ");
            tableView->setIndexWidget(model->index(i, 9), proccessOrderButton);

            connect(proccessOrderButton, &QPushButton::clicked, [this, i]() {
                processOrderForStrategyOnForm(i);
            });

            QPushButton *changeStateButton = new QPushButton("Поменять");
            tableView->setIndexWidget(model->index(i, 10), changeStateButton);

            connect(changeStateButton, &QPushButton::clicked, [this, i]() {
                changeStateOnForm(i);
            });
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных.");
    }
}
void OrderListWindow::changeStateOnForm(int row) {

    Order* order = orders[row];
    int orderId = order->getOrderId(); // Получаем ID заказа
    QString currentState = order->getState()->name; // Получаем текущее состояние

    changeStateForm *stfrm = new changeStateForm(orderId, currentState, this);

    connect(stfrm, &changeStateForm::stateChanged, this, [this, row](const QString& newState) {
        updateOrderState(row, newState);
    });

    stfrm->setModal(true);
    stfrm->exec();
}


// orderlistwindow.cpp
void OrderListWindow::updateOrderState(int row, const QString& newStateStr) {
    Order* order = orders[row];
    // Создаем цепочку обработчиков

    OrderState *newState;
    if(newStateStr == "Принят")
    {
        newState = new CreatedState();
    }
    else if(newStateStr == "В обработке")
    {
        newState = new ProcessingState();
    }
    else if(newStateStr == "Выполнен")
    {
        newState = new CompletedState();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка", "Неизвестое состояние для заказа");
    }
    OrderStateHandler* startHandler = new StartedStateHandler();
    OrderStateHandler* inProgressHandler = new InProgressStateHandler();
    OrderStateHandler* completedHandler = new CompletedStateHandler();

    // Настраиваем цепочку
    startHandler->setNextHandler(inProgressHandler);
    inProgressHandler->setNextHandler(completedHandler);

    // Обрабатываем изменение состояния
    startHandler->handle(order, newState, this);

    if(typeid(*newState) ==  typeid(ProcessingState))
    {
        order->updateOrder();
    }
    else if(typeid(*newState) == typeid(CompletedStateHandler))
    {
        order->finishOrder();
    }
    model->setItem(row, 4, new QStandardItem(order->getState()->name));// Обновляем отображение в таблице

    delete newState;
}

void OrderListWindow::processOrderForStrategyOnForm(int row) {
    Order* selectedOrder = orders[row];

        // Обрабатываем заказ с использованием стратегии
        if (selectedOrder) {
            QString response = selectedOrder->processOrderAccordingStrategy();
            QMessageBox::information(this, "Стратегия", response);
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

void OrderListWindow::closeEvent(QCloseEvent *event) {
    QApplication::quit();
    event->accept(); // Принять событие закрытия
}

void OrderListWindow::exportOrdersOnForm() {
    Visitor* visitor;
    if(exportVariantComboBox->currentText() == "XML")
    {
        visitor = new XmlVisitor();
    }
    else if(exportVariantComboBox->currentText() == "JSON")
    {
        visitor = new JsonVisitor();
    }

    QString exportedOrders; // Для хранения информации об экспортированных заказах
    bool atLeastOneExported = false; // Флаг для проверки, были ли экспортированы заказы

    for (int i = 0; i < orders.count(); ++i) {
        QStandardItem* checkBoxItem = model->item(i, 0); // Получаем элемент чекбокса
        if (checkBoxItem && checkBoxItem->checkState() == Qt::Checked) {
            Order* order = orders[i]; // Получаем текущий заказ
            order->Accept(visitor); // Экспортируем заказ через посетителя
            exportedOrders += QString("Заказ %1 экспортирован.\n").arg(order->getOrderId());
            atLeastOneExported = true;
        }
    }

    if (atLeastOneExported) {
        QMessageBox::information(this, "Экспорт заказов", exportedOrders);
    } else {
        QMessageBox::warning(this, "Экспорт заказов", "Нет выбранных заказов для экспорта.");
    }
}


