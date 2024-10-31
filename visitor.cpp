#include "visitor.h"

JsonVisitor::JsonVisitor() {
    // Initialization code (if needed)
}

void JsonVisitor::VisitOrder(Order *order) {
    QString fileName = QString("order_%1.json").arg(order->getOrderId());
    std::ofstream file(fileName.toStdString());    if (file.is_open()) {
        QJsonObject jsonOrder;
        jsonOrder["id"] = order->getOrderId();
        jsonOrder["username"] = order->getUsername();
        jsonOrder["description"] = order->getOrderDescription();

        QJsonArray jsonGoods;
        for (const Good &good : order->getGoods()) {
            QJsonObject jsonGood;
            jsonGood["id"] = good.getId();
            jsonGood["name"] = good.getName();
            jsonGood["price"] = good.getPrice();
            jsonGoods.append(jsonGood);
        }
        jsonOrder["goods"] = jsonGoods;

        QJsonDocument jsonDoc(jsonOrder);
        file << jsonDoc.toJson().toStdString(); // Save to file
        file.close();
        qDebug() << "Order saved to <<" << fileName << ".json\n";
    } else {
        qDebug() << "Unable to open file for writing: order<<"<< fileName <<".json\n";
    }
}

XmlVisitor::XmlVisitor() {
    // Initialization code (if needed)
}

void XmlVisitor::VisitOrder(Order *order) {
    QString fileName = QString("order_%1.xml").arg(order->getOrderId());
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("Order");
        xmlWriter.writeTextElement("id", QString::number(order->getOrderId()));
        xmlWriter.writeTextElement("username", order->getUsername());
        xmlWriter.writeTextElement("description", order->getOrderDescription());

        xmlWriter.writeStartElement("Goods");
        for (const Good &good : order->getGoods()) {
            xmlWriter.writeStartElement("Good");
            xmlWriter.writeTextElement("id", QString::number(good.getId()));
            xmlWriter.writeTextElement("name", good.getName());
            xmlWriter.writeTextElement("price", QString::number(good.getPrice()));
            xmlWriter.writeEndElement(); // Close Good
        }
        xmlWriter.writeEndElement(); // Close Goods
        xmlWriter.writeEndElement(); // Close Order
        xmlWriter.writeEndDocument();
        file.close();
        qDebug() << "Order saved to <<" << fileName << ".xml\n";
    } else {
        qDebug() << "Unable to open file for writing: order<<"<< fileName <<".xml\n";
    }
}
