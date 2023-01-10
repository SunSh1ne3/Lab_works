#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(n<10)
    {
        mas[n].setX(event->x());
        mas[n].setY(event->y());
        n++;
    }
    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0;i<n;i++)
    {
        painter.drawEllipse(mas[i], 3,3);
    }
    for(int i=0;i<n-1;i++)
    {
        painter.drawLine(mas[i],mas[i+1]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
