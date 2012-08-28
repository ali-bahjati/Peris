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
#include "smooth.h"

using namespace std;

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent = 0);
    
signals:
    
public slots:
    void on_resetButton_clicked();
    void on_closeButton_clicked();
private:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void showEvent(QShowEvent *);

    QPixmap *pixmap;
    int lastx;
    int lasty;
    vector<double> pointsX;
    vector<double> pointsY;
};

#endif // DRAWINGAREA_H
