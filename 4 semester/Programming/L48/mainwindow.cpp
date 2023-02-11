#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>

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
    for(int k=0;k<6;k++)
        if(vibor[k].rect.contains(event->pos()))
            InTable(k);
    n++;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect rect=contentsRect();
    if(n<1)
        Pole(rect);
    QPainter painter(this);
    painter.drawText(rect.width()-2*size,size,QString::number(n));

    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
        {
            painter.setBrush(QBrush(mas[i][j].color));
            painter.drawRect(QRect(mas[i][j].rect));
        }

    for(int i=0;i<6;i++)
    {
        painter.setBrush(QBrush(vibor[i].color));
        painter.drawRect(QRect(vibor[i].rect));
    }

}

QColor MainWindow::GetColor(int n)
{
    if(n==1)
        return  QColor(245,209,143);
    else if(n==2)
        return QColor(91,150,245);
    else if(n==3)
        return QColor(195,246,155);
    else if(n==4)
        return QColor(207,89,85);
    else if(n==5)
        return QColor(199,159,239);
    else
        return QColor(245,141,91);
}

void MainWindow::Pole(QRect rect)
{

    for(int i=0;i<12*size;i+=size)
    {
        for(int j=0;j<12*size;j+=size)
        {
            mas[i/size][j/size]=Kubik(GetColor(rand()%6+1),QRect(i,j,size,size),false);
        }
    }
    mas[0][0].flag=true;
    for(int i=0;i<6;i++)
    {
        vibor[i]=Kubik(GetColor(i+1),QRect(rect.width()-2*size,(i+2)*size,size,size), false);
    }
}

void MainWindow::InTable(int k)
{
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
        {
            if(mas[i][j].flag)
            {
                if(!mas[i+1][j].flag && mas[i+1][j].color==vibor[k].color)
                    mas[i+1][j].flag=true;
                if(!mas[i][j+1].flag && mas[i][j+1].color==vibor[k].color)
                    mas[i][j+1].flag=true;
                mas[i][j].color=vibor[k].color;
            }

        }
}

