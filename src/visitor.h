#ifndef VISITOR_H
#define VISITOR_H

#include "order.h"
#include <QMessageBox>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QXmlStreamWriter>
#include <QFile>
#include <qDebug>

class Visitor {
public:
    virtual void VisitOrder(Order *order) = 0;
    virtual ~Visitor() = default; // Add a virtual destructor
};

class JsonVisitor : public Visitor {
public:
    JsonVisitor(); // Constructor declaration
    void VisitOrder(Order *order) override;
};

class XmlVisitor : public Visitor {
public:
    XmlVisitor(); // Constructor declaration
    void VisitOrder(Order *order) override;
};

#endif // VISITOR_H
