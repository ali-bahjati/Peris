#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <vector>

#include "point.h"
#include "scale.h"
#include "linepoints.h"
#include "segmentpoints.h"
#include "database.h"

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent = 0);
    
signals:

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
};

#endif // DRAWINGAREA_H
