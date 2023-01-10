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
    QPoint *poy=nullptr;
    if((event->modifiers() & Qt::ControlModifier))
    {
        int min=345678, obmen=-1;
        for(int i=0;i<mas.size();i++)
        {
            int x=abs(mas[i]->x()-event->x());
            int y=abs(mas[i]->y()-event->y());
            if(x+y<min)
            {
                min=x+y;
                obmen=i;
            }
        }
        if(obmen == -1)
        {
           mas.append(new QPoint(event->x(), event->y()));
        }
        else
        {
            mas.insert(obmen+1, new QPoint(event->x(), event->y()));
        }
    }
    else if((event->modifiers() & Qt::ShiftModifier))
    {
        mas.removeAt(0);
    }
    else
    {
        mas.append(new QPoint(event->x(), event->y()));
    }

    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0;i<mas.size();i++)
    {
        painter.drawEllipse(*mas[i], 3,3);
    }
    for(int i=0;i<mas.size()-1;i++)
    {
        painter.drawLine(*mas[i],*mas[i+1]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

