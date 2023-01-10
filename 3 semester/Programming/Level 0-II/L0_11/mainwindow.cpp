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
    if((event->modifiers() & Qt::ControlModifier) && (mas.size()!=0))
    {
        poy = new QPoint(event->x(), event->y());
        mas.append(poy);
        mas.remove(0);
    }
    else
    {
        poy = new QPoint(event->x(), event->y());
        mas.append(poy);
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

