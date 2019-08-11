#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myopencv.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV = new MyOpenCV("video0", 0, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionIniciar_OpenCV_triggered()
{
    if (mOpenCV->start())
    {
        setCentralWidget(mOpenCV->videoOutput());
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}
