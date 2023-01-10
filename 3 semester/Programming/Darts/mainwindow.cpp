#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if(n==2)
    {
        poi.draw(&painter);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning!");

    if(n==0)
    {
        poi.setX1(event->x());
        poi.setY1(event->y());
        qDebug("x1 = %d, y1=%d", poi.getX1(), poi.getY1());
        n++;
    }
    else if(n==1)
    {
        poi.setX2(event->x());
        poi.setY2(event->y());
        qDebug("x2=%d, y2 = %d", poi.getX2(), poi.getY2());
        n++;
    }
    else if(n==2)
    {
        poi=Rect(poi.getX1(), poi.getY1(), poi.getX2(), poi.getY2());
        if(poi.contains(event->x(),event->y()))
        {
            msgBox.setText("Попал!");
            msgBox.exec();
        }
        else
        {
            msgBox.setText("Не попал!");
            msgBox.exec();
        }
    }

     repaint();
}
