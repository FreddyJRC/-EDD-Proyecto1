#include "mainwindow.h"
#include <QApplication>
#include <ortogonal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Matriz * tablero = new Matriz();
    tablero->insertar(0, 1, 2, "a");
    tablero->insertar(0, 2, 5, "c");
    tablero->insertar(1, 1, 2, "d");
    tablero->insertar(1, 2, 3, "e");
    tablero->insertar(1, 2, 5, "f");
    tablero->insertar(1, 2, 4, "g");

    return a.exec();
}
