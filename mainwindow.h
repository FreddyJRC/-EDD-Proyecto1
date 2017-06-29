#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ortogonal.h>
#include <arbol.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateNivel(int nivel);

private slots:
    void on_pushButton_2_clicked();
    void on_actionNivel_0_triggered();

    void on_actionNivel_1_triggered();

    void on_actionNivel_2_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionJugadores_triggered();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
