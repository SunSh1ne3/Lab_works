#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // отслеживание без клика //
    /*setMouseTracking(true);
    centralWidget()->setMouseTracking(true);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // L0.4 Нарисовать круг в месте клика. //
    /*painter.setBrush(QColor(255,0,0,100));
    QPen pens;
    pens.setWidth(3);
    pens.setColor(Qt::green);
    painter.setPen(pens);
    painter.drawEllipse(x_1-20, y_1-20, 40,40);*/

    // L0.5 Нарисовать прямоугольник в месте клика. //
    /*painter.setBrush(QColor(0,255,0));
    QPen pens;
    pens.setWidth(5);
    pens.setColor(Qt::red);
    painter.setPen(pens);
    painter.drawRect(x_1-50, y_1-25, 100,50);*/

    // L0.6 Модификаторы линий. //
    /*QPen pens;
    pens.setStyle(Qt::DashLine);
    painter.setPen(pens);
    if(n%2!=1)
        painter.drawLine(x_1,y_1,x_2,y_2);*/

    // L0.7 Рисование картинок. Масштабирование. //
    /*QRect window = contentsRect();
    QImage img("C:/Users/savel/Documents/null_level/flower.png");
    if(!Ctrl_click)
        painter.drawImage(100,100,img);
    else
    {
        painter.drawImage(QRect(window.width()/2-img.width()/2,window.height()/2-img.height()/2, img.width()*2, img.height()*2), img);
    }*/

    // L0.9 Резиновая рамка //
    /*QPen pens;
    pens.setStyle(Qt::DashDotDotLine);
    painter.setPen(pens);
    if(click)
        painter.drawRect(min(x_1, x_2),min(y_1, y_2),abs(x_1-x_2), abs(y_1-y_2));*/

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // L0.0 Попасть в (0,0). //
   /* QMessageBox msgBox;
    qDebug("x = %d, y = %d", event->x(), event->y());
    QString msg=QString("x = %1 y = %2").arg(event->x()).arg(event->y());
    QMessageBox::information(this, "infomation",msg);*/

    // L0.1 Нарисовать крест в месте клика. //
    /*x_1=event->x();
    y_1=event->y();*/

    // L0.2 Mouse buttons. //
    /*if(event->button() == Qt::LeftButton )
    {
        qDebug("LeftButton");
    }
    else if(event->button() == Qt::MiddleButton)
    {
        qDebug("MiddleButton");
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug("RightButton");
    }*/

    // L0.3 Модификаторы клика. //
    /*if((event->modifiers() & Qt::ControlModifier) && (event->modifiers() & Qt::ShiftModifier) && (event->modifiers() & Qt::AltModifier))
        qDebug("Alt+Shift+Ctrl");
    else if((event->modifiers() & Qt::AltModifier) && (event->modifiers() & Qt::ShiftModifier))
        qDebug("Alt+Shift");
    else if((event->modifiers() & Qt::ControlModifier) && (event->modifiers() & Qt::ShiftModifier))
        qDebug("Ctrl+Shift");
    else if((event->modifiers() & Qt::AltModifier) && (event->modifiers() & Qt::ControlModifier))
        qDebug("Alt+Ctrl");
    else if(event->modifiers() & Qt::ControlModifier)
        qDebug("Ctrl-click");
    else if(event->modifiers() & Qt::ShiftModifier)
        qDebug("Shift-click");
    else if(event->modifiers() & Qt::AltModifier)
        qDebug("Alt-click");
    else
        qDebug("click");*/

    // L0.4 Нарисовать круг в месте клика. и L0.5 Нарисовать прямоугольник в месте клика. // //
    /*x_1=event->x();
    y_1=event->y();*/

     // L0.6 Модификаторы линий. //
    /*if(n%2==0)
    {
        x_1=event->x();
        y_1=event->y();
        n++;
    }
    else
    {
        x_2=event->x();
        y_2=event->y();
        n++;
    }*/
    // L0.7 Рисование картинок. Масштабирование. //
    /*if(event->modifiers() & Qt::ControlModifier)
            Ctrl_click=true;
    else
        Ctrl_click=false;*/

    // L0.8 Движение мыши mousePressEvent, mouseReleaseEvent, mouseMoveEvent, setMouseTracking(true) //
    //qDebug("Клавиша нажата x = %d, y = %d",event->x(), event->y());

    // L0.9 Резиновая рамка //
    /*click=true;
    x_1=event->x();
    y_1=event->y();
    x_2=event->x();
    y_2=event->y();*/

    repaint();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // L0.8 Движение мыши mousePressEvent, mouseReleaseEvent, mouseMoveEvent, setMouseTracking(true) //
    //qDebug("Клавиша отжата x = %d, y = %d",event->x(), event->y());

    // L0.9 Резиновая рамка //
    //click=false;
    repaint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // L0.8 Движение мыши mousePressEvent, mouseReleaseEvent, mouseMoveEvent, setMouseTracking(true) //
    //qDebug("Курсор в движении x = %d, y = %d",event->x(), event->y());

    // L0.9 Резиновая рамка //
    /*x_2=event->x();
    y_2=event->y();*/
    repaint();
}

