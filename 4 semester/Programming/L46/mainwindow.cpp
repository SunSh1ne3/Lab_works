#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <math.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msg;
    if(n<5)
    {
        mas[n]=(QPoint(event->x(), event->y()));
        if(10-2*(int)sqrt(pow(mas[n].x()-rect.width()/2,2)+pow(mas[n].y()-rect.height()/2,2))/size >= 0)
            sum+=10-2*(int)sqrt(pow(mas[n].x()-rect.width()/2,2)+pow(mas[n].y()-rect.height()/2,2))/size;
        n++;
    }
    else
    {
        msg.setText(QString("%1").arg(sum));
        msg.exec();
    }
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    rect=contentsRect();

    QPen pen;pen.setWidth(3);
    painter.setPen(pen);
    QString s;
    for(int i=1;i<=10;i++)
    {
        painter.drawEllipse(rect.width()/2-i*size/2, rect.height()/2-i*size/2, i*size, i*size);
        painter.drawText(rect.width()/2+2+(i-1)*size/2, rect.height()/2+5,s.sprintf("%d", 11-i));
    }
    for(int i=1;i<10;i++)
    {
        painter.drawText(rect.width()/2-20-(i)*size/2, rect.height()/2+5,s.sprintf("%d", 10-i));
        painter.drawText(rect.width()/2, rect.height()/2-5-(i)*size/2,s.sprintf("%d", 10-i));
        painter.drawText(rect.width()/2, rect.height()/2+15+(i)*size/2,s.sprintf("%d", 10-i));
    }
    pen.setWidth(5);painter.setPen(pen);
        for(int i=0;i<5;i++)
            painter.drawPoint(mas[i]);
}

