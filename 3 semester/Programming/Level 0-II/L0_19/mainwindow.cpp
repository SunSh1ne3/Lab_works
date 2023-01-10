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

    for(int i=0;i<mas.size();i++)
    {
        painter.setPen(QPen(Qt::black, 4));
        painter.drawPoint(mas[i]);
    }
    if(click)
    {
        painter.setPen(Qt::DashDotDotLine);
        painter.drawRect(poy);
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    click=true;
    poy=QRect(QPoint(event->pos()),QPoint(event->pos()));
    if(event->modifiers() & Qt::ControlModifier)
        mas.append(event->pos());

    repaint();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    click=false;
    for(int i=0;i<mas.size();i++)
    {
        if((poy.contains(mas[i])) && (poy.width()>=2) && (poy.height()>=2))
        {
           mas.removeAt(i);
           i--;
        }
    }

    repaint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    poy=QRect(poy.topLeft(),QPoint(event->pos()));
    repaint();
}

