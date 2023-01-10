#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mas.append(QPoint(event->x(),event->y()));
    repaint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    mas.append(QPoint(event->x(),event->y()));
    repaint();
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pens;
    pens.setWidth(2);
    painter.setPen(pens);
      for(int i=0;i<mas.size();i++)
      {
          painter.drawPoint(mas[i]);
      }

}

MainWindow::~MainWindow()
{
    delete ui;
}

