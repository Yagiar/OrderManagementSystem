#include "createorderdialog.h"
#include "ui_createorderdialog.h"
#include "good.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include "factory.h"

CreateOrderDialog::CreateOrderDialog(QList<Good> *choosenGoods, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateOrderDialog)
    , goods(choosenGoods)
{
    setWindowTitle("Оформление заказа");
    ui->setupUi(this);

    QWidget *scrollContent = new QWidget(this);
    QVBoxLayout *goodsLayout = new QVBoxLayout(scrollContent);

    double totalPrice = 0.0; // Сумма заказа

    for (int i = 0; i < goods->count(); ++i) {
        const Good &good = goods->at(i);

        QLabel *goodLabel = new QLabel(QString::number(i + 1) + ". " +
                                           good.getName() + " - " +
                                           QString::number(good.getPrice()) + "₽", this);
        goodsLayout->addWidget(goodLabel);

        totalPrice += good.getPrice();
    }

    QLabel *totalPriceLabel = new QLabel("Общая сумма заказа: " + QString::number(totalPrice) + "₽", this);
    goodsLayout->addWidget(totalPriceLabel);

    scrollContent->setLayout(goodsLayout);
    ui->scrollAreaGoods->setWidget(scrollContent);
}

CreateOrderDialog::~CreateOrderDialog()
{
    delete ui;
}

void CreateOrderDialog::on_pushButton_clicked()
{
    switch(ui->comboBoxTypeOrder->currentIndex())
    {
    case 0:
        {
            Factory* factory = new DigitalFactory();
            factory->creationOfOrder(ui->textEditDescriptionOrder->toPlainText(), 1,
                                     ui->comboBoxPriorityOrder->currentIndex()+1, *goods, username);

            delete factory;
            break;
        }

    case 1:
        {
            Factory* factory = new PhysicalFactory();
            factory->creationOfOrder(ui->textEditDescriptionOrder->toPlainText(), 1,
                                     ui->comboBoxPriorityOrder->currentIndex()+1, *goods, username);

            delete factory;
            break;
        }
    }
}

