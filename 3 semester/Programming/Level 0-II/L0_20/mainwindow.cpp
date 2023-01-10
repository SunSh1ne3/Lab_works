#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
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
    QPainter painter(this);

    for(int i=0;i<points.size();i++)
    {
        painter.setPen(QPen(Qt::black,3));
        painter.drawPoint(points[i]);
    }
    painter.setPen(QPen(Qt::black,1,Qt::DotLine));
    painter.drawRect(poy);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    points.append(QPoint(event->pos()));
    int min_x=1000, min_y=1000,max_x=0,max_y=0;
    for(int i=0;i<points.size();i++)
    {
        if(points[i].x()<min_x) min_x=points[i].x();
        if(points[i].y()<min_y) min_y=points[i].y();
        if(points[i].x()>max_x) max_x=points[i].x();
        if(points[i].y()>max_y) max_y=points[i].y();
    }
    poy=QRect(QPoint(min_x-3,min_y-3), QPoint(max_x+3,max_y+3));
    repaint();
}


