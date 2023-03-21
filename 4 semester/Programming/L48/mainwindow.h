#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Kubik
{
    QColor color;
    QRect rect;
    bool flag=false;
    Kubik(){}
    Kubik(QColor m_color,QRect m_rect,bool m_flag)
    {
        color=m_color;
        rect=m_rect;
        flag=m_flag;

    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    QColor GetColor(int n);
    void Pole(QRect rect);
    void InTable(int k);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Kubik mas[12][12];
    Kubik vibor[6];
    int size=40, n=0;
    QRect rect=contentsRect();
};
#endif // MAINWINDOW_H
