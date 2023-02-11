#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

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

    QVector<QPoint> tree;
    int N=10,size=40;

    Podchet(tree,N, size);

    for(float i=size;i<=N*size;i+=size)
        for(float j=size;j<=N*size;j+=size)
        {
            painter.setPen(QPen(Qt::black, 1));
            painter.drawRect(QRect(i,j,size,size));
        }

    painter.setPen(QPen(Qt::blue,9));
    for(int i=0;i<tree.size();i++)
        painter.drawPoint(tree.at(i));

    painter.setPen(QPen(Qt::green,9));
    painter.drawPoint(size,size);
}

void MainWindow::Podchet( QVector<QPoint> &tree, int N, int size)
{
    QVector <float> k;
    for(float i=size;i<N*size;i+=size)
        for(float j=size;j<N*size;j+=size)
            if(k.lastIndexOf(i/j) == -1)
            {
                k.append(i/j);
                tree.append(QPoint(i+size,j+size));
            }
}

