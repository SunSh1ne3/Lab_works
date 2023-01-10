#include "rect.h"

Rect::Rect()
{

}

Rect::Rect(int x1, int y1, int x2, int y2)
{
    //с 1 индексом меньший, со 2 индексом - больший, меняем если это не так
    this->x1=x1 < x2 ? x1:x2;//если x1 меньше x2 то x1=x1, иначе x1=x2
    this->y1=y1 < y2 ? y1:y2;//если y1 меньше y2 то y1=y1, иначе y1=y2
    this->x2=x2 > x1 ? x2:x1;//если x2 больше x1 то x2=x2, иначе x2=x1
    this->y2=y2 > y1 ? y2:y1;//если y2 больше y1 то y2=y2, иначе y2=y1
}

bool Rect::contains(int x, int y)
{
    if(x<x1) return false;
    if(x>x2) return false;
    if(y<y1) return false;
    if(y>y2) return false;

    return true;
}

void Rect::draw(QPainter *painter)
{
    painter->drawRect(x1,y1, getWidth(),getHeight());
}


int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int value)
{
    x1 = value;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int value)
{
    y1 = value;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int value)
{
    x2 = value;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int value)
{
    y2 = value;
}

