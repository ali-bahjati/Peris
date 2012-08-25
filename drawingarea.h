#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <vector>

#include "scale.h"
#include "linepoints.h"

using namespace std;

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent = 0);
    
signals:
    
public slots:
    void on_resetButton_clicked();
private:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void showEvent(QShowEvent *);

    QPixmap *pixmap;
    int lastx;
    int lasty;
    vector<float> pointsX;
    vector<float> pointsY;
};

#endif // DRAWINGAREA_H
