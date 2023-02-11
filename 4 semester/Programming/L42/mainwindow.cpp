#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    rect = contentsRect();
    QPainter painter(this);
    QString s;
    for(int i=0;i<8;i++)
    {
        painter.drawText(rect.width()/2-size*4.5, i*size+rect.height()/2-size*3.5, s.sprintf("%d", i+1));
        painter.drawText(i*size+rect.width()/2-size*3.5, rect.height()/2+size*4.5, s.sprintf("%c", char(letter[i])));
        for(int j=0;j<8;j++)
        {

            if((i+j)%2==0)
            {
                painter.setBrush(Qt::white);
                painter.drawRect(i*size+rect.width()/2-size*4, j*size+rect.height()/2-size*4, size,size);
            }
            else
            {
                painter.setBrush(Qt::black);
                painter.drawRect(i*size+rect.width()/2-size*4, j*size+rect.height()/2-size*4, size,size);
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x=(event->x()-rect.width()/2+size*4)/size;
    int y=(event->y()-rect.height()/2+size*4)/size;
    QMessageBox msg;
    if((event->x()<rect.width()/2-size*4) || (event->x()>rect.width()/2+size*4) || (event->y()<rect.height()/2-size*4) || (event->y()>rect.height()/2+size*4))
    {
        msg.setText("Вне доски!");
    }
    else
    {
        msg.setText(QString(65+x)+QString(49+y));
    }
    msg.exec();

}

