#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
<<<<<<< HEAD
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <vector>

#include "point.h"
#include "scale.h"
#include "linepoints.h"
#include "segmentpoints.h"
#include "database.h"
=======
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <vector>

#include "scale.h"
#include "linepoints.h"

using namespace std;
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent = 0);
    
signals:
<<<<<<< HEAD

public slots:
	void showEvent(QShowEvent *);
	void paintEvent(QPaintEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void resetButton_clicked();
private:
	void startProcess();

	QPixmap *pixmap;
	PList points;
	Point lastPoint;
	int scaleWidth;
=======
    
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
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
};

#endif // DRAWINGAREA_H
