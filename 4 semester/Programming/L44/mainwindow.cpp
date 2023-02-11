#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QCursor>
#include <QPoint>
using namespace  std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCursor cursi(Qt::OpenHandCursor);

    setMouseTracking(true);
    centralWidget()->setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(n>1)
        painter.drawRect(min(x_1, x_2),min(y_1, y_2),abs(x_1-x_2), abs(y_1-y_2));

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(n==0)
    {
        x_1=event->x();
        y_1=event->y();
        n++;
    }
    else if(n==1)
    {
        x_2=event->x();
        y_2=event->y();
        n++;
    }
    click=true;

    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int a=3;
    QWidget::setCursor(QCursor());

    if(n>1)
    {
        if(abs(event->x()-x_1)<=a)
        {
            if((abs(event->y()-y_1)<=a))
            {
                QWidget::setCursor(QCursor(Qt::SizeFDiagCursor));
                if(click)
                {
                    x_1=event->x();
                    y_1=event->y();
                }
            }
            else if(abs(event->y()-y_2)<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeBDiagCursor));
                if(click)
                {
                    x_1=event->x();
                    y_2=event->y();
                }
            }
            else
            {
                QWidget::setCursor(QCursor(Qt::SizeHorCursor));
                if(click)
                    x_1=event->x();
            }
        }

        else if(abs(event->x()-x_2)<=a)
        {
            if(abs(event->y()-y_2)<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeFDiagCursor));
                if(click)
                {
                    x_2=event->x();
                    y_2=event->y();
                }
            }
            else if(abs(event->y()-y_1)<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeBDiagCursor));
                if(click)
                {
                    x_2=event->x();
                    y_1=event->y();
                }
            }
            else
            {
                QWidget::setCursor(QCursor(Qt::SizeHorCursor));
                if(click)
                    x_2=event->x();
            }

        }
        else if(abs(event->y()-y_1)<=a)
        {
            QWidget::setCursor(QCursor(Qt::SizeVerCursor));
            if(click)
                y_1=event->y();
        }
        else if(abs(event->y()-y_2)<=a)
        {
            QWidget::setCursor(QCursor(Qt::SizeVerCursor));
            if(click)
                y_2=event->y();
        }
    }
    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    click=false;
}

