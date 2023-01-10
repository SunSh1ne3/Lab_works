#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    //centralWidget()->setMouseTracking(true);
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier)
    {
        mas.append(QPoint(event->x(), event->y()));
    }
    else
    {
       point=QPoint(event->x(), event->y());
    }
    repaint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    dx=event->x()-point.x();
    dy=event->y()-point.y();
    QPoint d_point(dx, dy);
    point+=d_point;

    for(int i=0;i<mas.size();i++)
    {
        mas[i]+=d_point;
    }

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0;i<mas.size()-1;i++)
    {
        painter.drawLine(mas[i],mas[i+1]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

