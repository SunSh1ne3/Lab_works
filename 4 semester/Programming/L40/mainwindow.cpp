#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <cmath>

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
    if((event->modifiers() & Qt::ControlModifier))
        major=QPoint(event->x(),event->y());
    else
        mas.append(QPoint(event->x(), event->y()));

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;pen.setWidth(4);
    painter.setPen(4);

    pen.setColor(Qt::blue); painter.setPen(pen);
    painter.drawPoint(major);

    pen.setWidth(3); painter.setPen(pen);
    if(Enter)
    {
        if(!mas[i_min].isNull())
            painter.drawLine(major,mas[i_min]);
    }

    pen.setColor(Qt::black);pen.setWidth(4);
    painter.setPen(pen);
    for(int i=0;i<mas.size();i++)
        painter.drawPoint(mas[i]);

    if(Enter)
    {
        pen.setWidth(2); painter.setPen(pen);
        for(int i=0;i<mas.size();i++)
            painter.drawLine(mas[i_min],mas[i]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int x,y, sum;
    float distance;
    if(event->key()==Qt::Key_Enter)
    {
        qDebug("Enter");
        Enter=true;
        for(int j=0;j<mas.size();j++)
        {
            sum=0;
            for(int i=0;i<mas.size();i++)
            {
                distance=0;
                if(i!=j)
                {
                    x=mas[j].x()-mas[i].x();
                    y=mas[j].y()-mas[i].y();
                    distance=sqrt(x*x+y*y);
                    sum+=distance;
                }
            }
            if(sum<sum_min)
            {
                sum_min=sum;
                i_min=j;
            }
        }
    }
     repaint();
}


