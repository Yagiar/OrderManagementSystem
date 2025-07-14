#include "changestateform.h"
#include "ui_changestateform.h"
#include <QVBoxLayout>
#include <QMessageBox>

changeStateForm::changeStateForm(int orderId, const QString& currentState, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeStateForm)
{
    ui->setupUi(this);

    // Инициализируем элементы
    stateComboBox = new QComboBox(this);
    confirmButton = new QPushButton("Подтвердить", this);
    orderIdLabel = new QLabel(QString("ID заказа: %1").arg(orderId), this);
    currentStateLabel = new QLabel(QString("Текущее состояние: %1").arg(currentState), this);

    // Устанавливаем состояния в выпадающем списке
    stateComboBox->addItems({"Принят", "В обработке", "Выполнен"});

    // Создаем компоновку
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(orderIdLabel);
    layout->addWidget(currentStateLabel);
    layout->addWidget(stateComboBox);
    layout->addWidget(confirmButton);

    // Устанавливаем компоновку в диалог
    setLayout(layout);

    // Подключаем кнопку подтверждения к сигналу
    connect(confirmButton, &QPushButton::clicked, this, &changeStateForm::onConfirmButtonClicked);
}


void changeStateForm::onConfirmButtonClicked() {
    QString selectedState = stateComboBox->currentText();
    emit stateChanged(selectedState);
    accept();
}

changeStateForm::~changeStateForm()
{
    delete ui;
}
