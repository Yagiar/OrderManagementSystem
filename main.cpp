#include <QApplication>
#include <QWidget>
#include <QLabel>
#include "mainwindow.h"

//"Host=pgdb.uni-dubna.ru;Username=student25;Password=Io_228_1337;Database=student25" подключение к базе

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}
