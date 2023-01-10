#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

int MainWindow::rast(QPoint point_1, QPoint point_mas)
{
    int dx = point_mas.x()-point_1.x();
    int dy = point_mas.y()-point_1.y();
    return qSqrt(qPow(dx,2)+qPow(dy,2));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(event->modifiers() & Qt::ControlModifier)
    {
        mas.append(QPoint(event->x(), event->y()));
    }
    else
    {
       click=true;
       point=QPoint(event->x(), event->y());
    }
    repaint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint d_point(event->x()-point.x(), event->y()-point.y());
    point+=d_point;
    for(int i=0; i<mas.size(); i++)
    {
        if((rast(point, mas[i]) <= 25) && (points.indexOf(i)==-1))
        {
            points.append(i);
        }
    }

    for(int j=0;j<points.size();j++)
    {
        mas[points[j]]+=d_point;
    }

    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    click=false;
    points.clear();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0;i<mas.size()-1;i++)
    {
        painter.drawLine(mas[i],mas[i+1]);
    }
    if(point!=QPoint(0,0))
    {
        painter.setBrush(QColor(255,255,0,100));
        painter.drawEllipse(point, 25,25);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

