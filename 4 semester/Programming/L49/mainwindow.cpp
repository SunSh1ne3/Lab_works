#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>
#include <QTimer>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QWidget::resize(size*5, QWidget::height());

    Edit();
    Delete_level();

    for(int i=0;i<mas.size();i++)
        for(int j=0;j<mas[i].size();j++)
            mas[i][j].Paint(painter);

    igrok.Paint(painter);
}

void MainWindow::Edit()
{
    srand(time(NULL));
    if(v1.empty())
    {
        for(int j=0;j<window.width();j+=size)
            v1.append(Kubik(QPoint(j, window.height()), GetColor(rand()%5+1), size));

        if(!v1.empty())
        {
            mas.append(v1);
            igrok=Kubik(QPoint(window.width()/2-size/2,v1[0].GetRect().top()-size-v1[0].GetSpeed()),v1[rand()%4+0].GetColor(), size);
        }
    }

    if(!v1.empty() )
    {
        if(mas[mas.size()-1][0].GetRect().bottom()<=window.height())
        {
            v1.clear();
            for(int j=0;j<window.width();j+=size)
                v1.append(Kubik(QPoint(j, window.height()), GetColor(rand()%5+1), size));
            mas.append(v1);
        }
    }
}

void MainWindow::Delete_level()
{
    if(!mas.empty())
        for(int i=0;i<mas.first().size();i++)
        {
            if((mas.first()[i].GetColor()==igrok.GetColor())&& (abs(mas.first()[i].GetRect().center().x()-igrok.GetRect().center().x())<size/2) && (mas.size()>1))
            {
                while(mas.first()[i].GetColor()==igrok.GetColor() && mas.size()>1)
                    mas.removeFirst();

                igrok.SetColor(mas[0][rand()%4+0].GetColor());
            }

        }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(!mas.empty())
        for(int i=0;i<mas.first().size();i++)
            if(abs(event->x()-mas[0][i].GetRect().center().x())<size/2)
                igrok=Kubik(QPoint(mas.first()[i].GetRect().topLeft().x(),mas.first()[i].GetRect().top()-mas.first()[i].GetSpeed()-size),igrok.GetColor(), size);

    repaint();
}

QColor MainWindow::GetColor(int n)
{
    switch(n)
    {
    case 1: return Qt::green; break;
    case 2: return Qt::yellow; break;
    case 3: return Qt::blue; break;
    case 4: return Qt::red; break;
    case 5: return Qt::magenta; break;
    default: return Qt::white; break;
    }
}

void MainWindow::update()
{
    window=contentsRect();
    if(!mas.empty())
            igrok.Move_igrok(mas.first());

    for(int i=0;i<mas.size();i++)
        for(int j=0;j<mas[i].size();j++)
            mas[i][j].Move();

    repaint();
}


