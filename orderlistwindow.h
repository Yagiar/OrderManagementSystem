#ifndef ORDERLISTWINDOW_H
#define ORDERLISTWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QTableView>
#include <QPushButton>
#include <QStandardItemModel>
#include "order.h"  // Убедитесь, что этот файл правильно определен
#include "database.h" // Убедитесь, что этот файл правильно определен

namespace Ui {
class OrderListWindow;
}

class OrderListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderListWindow(QWidget *parent = nullptr);
    ~OrderListWindow();

private:
    void loadOrders(); // Метод для загрузки заказов из базы данных

private:
    Ui::OrderListWindow *ui;
    QTableView *tableView; // Изменено на QTableView
    QStandardItemModel *model; // Модель для таблицы
    QPushButton *closeButton; // Кнопка закрытия
    QList<Order*> orders; // Список заказов
};

#endif // ORDERLISTWINDOW_H
