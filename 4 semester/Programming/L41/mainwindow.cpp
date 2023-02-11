#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QBrush>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    pim = QPoint(event->x(),event->y());
    press = true;

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    rect = contentsRect();

    for(int i = 0; i < rect.width(); i += 20)
    {
        for(int j = 0; j < rect.height(); j += 20)
        {
            painter.drawRect(i,j,20,20);
            rect_mas.append(QRect(i,j,20,20));
        }
    }
    if(press == true)
    {
        for(int i = 0; i < rect_mas.size(); i++)
        {
            if((qSqrt(qPow(rect_mas[i].x()-pim.x(),2)+qPow(rect_mas[i].y()-pim.y(),2)) <= diametr/2) & (qSqrt(qPow(rect_mas[i].x()+20 - pim.x(),2)+qPow(rect_mas[i].y()-pim.y(),2)) <= diametr/2) & (qSqrt(qPow(rect_mas[i].x()-pim.x(),2)+qPow(rect_mas[i].y() + 20 -pim.y(),2)) <= diametr/2) & (qSqrt(qPow(rect_mas[i].x()+20 - pim.x(),2)+qPow(rect_mas[i].y()+20 - pim.y(),2)) <= diametr/2))
            {
                painter.setBrush(Qt::blue);
                painter.drawRect(rect_mas[i]);
            }
        }
        painter.setBrush(Qt::NoBrush);
        painter.drawEllipse(pim.x()-diametr/2,pim.y()-diametr/2,diametr,diametr);
    }

}
