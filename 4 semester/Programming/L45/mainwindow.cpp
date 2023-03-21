#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
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

void MainWindow::paintEvent(QPaintEvent *event)
{
    int r = 50;
    int counter = 0;
    QPainter painter(this);
    QPen pen;
    painter.setPen(pen);
    for(int i = 0; i < geometry().width();i++)
    {
        for(int j = 0; j < geometry().height();j++)
        {
            counter = 0;
            for(int k = 0; k < circle.size();k++)
            {
                if((((circle[k].x() - i)*(circle[k].x() - i)) + ((circle[k].y()-j)*(circle[k].y()-j))) < r*r)
                {
                    counter++;
                }
            }

            pen.setColor(GetColor(counter));
            painter.setPen(pen);
            painter.drawPoint(i,j);
        }
    }
    for(int i = 0; i < circle.size();i++)
    {
        pen.setColor(Qt::black);
        painter.setPen(pen);
        painter.drawEllipse(circle[i],r,r);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    circle.append(event->pos());
    repaint();
}

QColor MainWindow::GetColor(int count)
{
    switch(count)
    {
    case(0): return Qt::white; break;
    case(1): return Qt::white; break;
    case(2): return Qt::red; break;
    case(3): return QColor(255,165,0); break;
    case(4): return Qt::yellow;break;
    case(5): return Qt::green;break;
    case(6): return Qt::blue;break;
    case(7): return QColor(75,0,130);break;
    default: return QColor(255,105,180); break;
    }
}
