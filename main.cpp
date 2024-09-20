#include <QApplication>
#include <QWidget>
#include <QLabel>
#include "startWindow.h"

//"Host=pgdb.uni-dubna.ru;Username=student25;Password=Io_228_1337;Database=student25" подключение к базе

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::addLibraryPath("C:/Qt/6.7.2/mingw_64/plugins/sqldrivers");

    startWindow w;
    w.show();

    return app.exec();
}
//D:\OrderManagementSystem\build\Desktop_Qt_6_7_2_MinGW_64_bit-Debug\.qtc_clangd\.cache\clangd\index
