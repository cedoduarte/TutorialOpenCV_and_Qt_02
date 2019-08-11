#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MyOpenCV;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionIniciar_OpenCV_triggered();
    void on_actionAbout_Qt_triggered();
private:
    Ui::MainWindow *ui;
    MyOpenCV *mOpenCV;
};

#endif // MAINWINDOW_H
