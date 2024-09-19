#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    // настраиваем заголовок окна
    widget.setWindowTitle("Qt на METANIT.COM");
    widget.setMinimumHeight(180);  // высота окна
    widget.setMinimumWidth(300);  // ширина окна

    QLabel label{&widget};      // создаем текстовую метку
    label.setText("Hello METANIT.COM"); // установка текста метки

    widget.show();  // отображаем виджет
    return app.exec();
}
