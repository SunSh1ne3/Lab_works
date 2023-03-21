#include "kubik.h"

Kubik::Kubik(){}

Kubik::Kubik(QPoint point_m, QColor color_m, int size_m)
{
    kubik_r=QRect(point_m, QSize(size_m, size_m));
    color=color_m;
    size=size_m;
}

void Kubik::Paint(QPainter &painter)
{
    painter.setBrush(QBrush(color));
    painter.drawRect(kubik_r);
}

void Kubik::Move()
{
    if(kubik_r.top()>0)
        kubik_r.moveTop(kubik_r.top()-speed);
    else
        exit(1);
}

void Kubik::Move_igrok(QVector<Kubik> mas)
{
    Move();
    for(int i=0;i<mas.size();i++)
        if(kubik_r.bottom()<mas[i].kubik_r.top())
            kubik_r.moveBottom(mas[i].kubik_r.top()-speed);

}

