#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPainter>
#include <QMouseEvent>
#include "kubik.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QColor GetColor(int n);
    void Edit();
    void Delete_level();
    ~MainWindow();
public slots:
    void update();

private:
    Ui::MainWindow *ui;
    QVector<QVector<Kubik>> mas;
    QVector<Kubik> v1;
    QRect window;
    Kubik igrok;
    int size=50;

};
#endif // MAINWINDOW_H
