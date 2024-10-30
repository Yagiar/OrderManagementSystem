#ifndef ORDERLISTWINDOW_H
#define ORDERLISTWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QTableView>
#include <QPushButton>
#include <QStandardItemModel>
#include "order.h"  // Убедитесь, что этот файл правильно определен

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
private slots:
    void showOrderGoods(int row); // Добавьте это
    void processOrderForStrategyOnForm(int row);
    void changeStateOnForm(int row);

private:
    Ui::OrderListWindow *ui;
    QTableView *tableView; // Изменено на QTableView
    QStandardItemModel *model; // Модель для таблицы
    QPushButton *closeButton; // Кнопка закрытия
    QList<Order*> orders; // Список заказов
    // orderlistwindow.h
private slots:
    void updateOrderState(int row, const QString& newState);
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // ORDERLISTWINDOW_H
