#ifndef RECT_H
#define RECT_H
#include <QPainter>

class Rect
{
public:
    Rect();
    Rect(int x1, int y1, int x2, int y2);//x,y -координат соот. диагональных точек

    bool contains(int x, int y);

    void draw(QPainter *painter);

    int getWidth() {return x2-x1;}
    int getHeight() {return y2-y1;}

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    int getX2() const;
    void setX2(int value);

    int getY2() const;
    void setY2(int value);

private:
    int x1, y1, x2, y2;
};

#endif // RECT_H
