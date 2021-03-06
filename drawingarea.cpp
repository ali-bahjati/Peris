#include "drawingarea.h"
using namespace PreProcessing;
using namespace Processing;

using namespace std;

DrawingArea::DrawingArea(QWidget *parent) :
	QWidget(parent),
	pixmap(0),
	points(),
	lastPoint(-1,-1),
	scaleWidth(300)
{
}

void DrawingArea::showEvent(QShowEvent *)
{
	pixmap = new QPixmap(width(),height());

	QPainter painter(pixmap);
	painter.fillRect(0,0,width(),height(),Qt::white);

	update();
}

void DrawingArea::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.drawPixmap(0,0,width(),height(),*pixmap);
}

void DrawingArea::mouseMoveEvent(QMouseEvent *e)
{
	Point p(e->x(),e->y());
	points.pushPoint(p);

	QPainter painter(pixmap);

	if ( lastPoint.x == -1 && lastPoint.y == -1 )
	{
		lastPoint.x = e->x();
		lastPoint.y = e->y();
	}
	painter.drawLine(lastPoint.x,lastPoint.y,p.x,p.y);

	lastPoint = p;

	update();
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *e)
{
	Point p(e->x(),e->y());
	points.pushPoint(p);

	{
		QPainter painter(pixmap);

		if ( lastPoint.x == -1 && lastPoint.y == -1 )
		{
			lastPoint.x = e->x();
			lastPoint.y = e->y();
		}

		painter.drawLine(lastPoint.x,lastPoint.y,p.x,p.y);

		//pixmap->save("/home/ali/1.png");

		//painter.fillRect(0,0,width(),height(),Qt::white);
	}
	update();



	startProcess();
}

void DrawingArea::startProcess()
{
	QPainter painter(pixmap);

	points.makeBest();
	Scale scaler;
	scaler.rectScale(points, scaleWidth);
	LinePoints lp;




	painter.setPen(Qt::red);
	painter.drawRect(0,0,scaleWidth,scaleWidth);
	//painter.drawLine(0,scaleWidth,height(),scaleWidth);
	//painter.drawLine(scaleWidth,0,scaleWidth,width());
	painter.setPen(Qt::blue);

	for(int i =0 ;i < points.getSize(); i++)
	{
		painter.drawEllipse(points.getPoint(i).x,points.getPoint(i).y,1,1);

		//painter.drawLine(points.getPoint(i-1).x, points.getPoint(i-1).y, points.getPoint(i).x,points.getPoint(i).y);
	}


	//pixmap->save("/home/ali/2.png");

	points = lp.getLinesPoints(points);

	for(int i =0 ;i < points.getSize(); i++)
	{
		painter.drawEllipse(points.getPoint(i).x,points.getPoint(i).y,1,1);

		//painter.drawLine(points.getPoint(i-1).x, points.getPoint(i-1).y, points.getPoint(i).x,points.getPoint(i).y);
	}

	//pixmap->save("/home/ali/3.png");

	string result;
	vector<Directions> newPath;
	DataBase db;

	for(int i = 0 ; i < 4; i++)
	{
		points.rotatePoints(90);
		scaler.rectScale(points, scaleWidth);

		SegmentPoints segmentor;

		PList segmentedPoints = segmentor.getSegmentPoints_FPCAlgorithm(points,20);


		vector<Directions> path = db.generatePath(segmentedPoints);
		result = db.findPath(path);
		if ( result != "" )
		{
			painter.drawText(100,300,100,100,0,result.c_str());
			painter.setPen( Qt::red);

			for(int i =0 ;i < segmentedPoints.getSize(); i++)
			{

				//painter.drawEllipse(segmentedPoints.getPoint(i).x-3,segmentedPoints.getPoint(i).y-3,6,6);

				painter.drawLine(segmentedPoints.getPoint(i-1).x, segmentedPoints.getPoint(i-1).y, segmentedPoints.getPoint(i).x,segmentedPoints.getPoint(i).y);
			}
			break;
		}
		else
		{
			newPath = path;
		}


		//If it couldn't find the answer, it will add it to database as shown below

	}
	if ( result == "" )
	{
		db.addPath(newPath,"3");
	}



	update();
}

void DrawingArea::resetButton_clicked()
{
	points.clear();

	lastPoint.x = -1;
	lastPoint.y = -1;


	QPainter painter(pixmap);
	painter.fillRect(0,0,width(),height(),Qt::white);

	update();
}
