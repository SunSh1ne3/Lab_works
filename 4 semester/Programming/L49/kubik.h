#ifndef KUBIK_H
#define KUBIK_H
#include <QRect>
#include <QPainter>
#include <QPoint>
#include <QVector>

class Kubik
{
public:
    Kubik();
    Kubik(QPoint point_m, QColor color_m, int size_m);
    void Paint(QPainter &painter);
    void Move();
    void Move_igrok(QVector<Kubik> mas);
    QRect GetRect(){ return kubik_r;}
    int GetSpeed(){return speed;}
    QColor GetColor(){return color;}
    void SetColor(QColor color_m){color=color_m;}
private:
    QRect kubik_r;
    QColor color;
    int size, speed=5;
};

#endif // KUBIK_H
