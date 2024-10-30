#ifndef CHANGESTATEFORM_H
#define CHANGESTATEFORM_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class changeStateForm;
}

class changeStateForm : public QDialog
{
    Q_OBJECT

public:
   explicit changeStateForm(int orderId, const QString& currentState, QWidget *parent = nullptr);
    ~changeStateForm();

private:
    Ui::changeStateForm *ui;
    QLabel *orderIdLabel;
    QLabel *currentStateLabel;
    QComboBox *stateComboBox;  // Выпадающий список для выбора состояния
    QPushButton *confirmButton;  // Кнопка для подтверждения
    void onConfirmButtonClicked();

signals:
    void stateChanged(const QString& newState);
};

#endif // CHANGESTATEFORM_H
