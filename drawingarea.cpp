#include "drawingarea.h"
<<<<<<< HEAD
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
=======
#include "ui_drawingform.h"


DrawingArea::DrawingArea(QWidget *parent) :
    QWidget(parent)
{

>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}

void DrawingArea::paintEvent(QPaintEvent *)
{
<<<<<<< HEAD
	QPainter painter(this);

	painter.drawPixmap(0,0,width(),height(),*pixmap);
=======

    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),*(DrawingArea::pixmap));
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}

void DrawingArea::mouseMoveEvent(QMouseEvent *e)
{
<<<<<<< HEAD
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
	Scale scaler;
	scaler.rectScale(points, scaleWidth);
	LinePoints lp;



	QPainter painter(pixmap);

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

	SegmentPoints segmentor;

	PList segmentedPoints = segmentor.getSegmentPoints_FPCAlgorithm(points,20);

	DataBase db;
	vector<Directions> path = db.generatePath(segmentedPoints);
	string result = db.findPath(path);


	//If it couldn't find the answer, it will add it to database as shown below
	if ( result == "" )
	{
		db.addPath(path,"m");
	}

	else
	{
		painter.drawText(100,100,100,100,0,result.c_str());
	}

	painter.setPen(Qt::red);
	for(int i =0 ;i < segmentedPoints.getSize(); i++)
	{

		painter.drawEllipse(segmentedPoints.getPoint(i).x-3,segmentedPoints.getPoint(i).y-3,6,6);

		//painter.drawLine(points.getPoint(i-1).x, points.getPoint(i-1).y, points.getPoint(i).x,points.getPoint(i).y);
	}

	//pixmap->save("/home/ali/4.png");

	//painter.fillRect(0,0,width(),height(),Qt::white);

	for(int i =0 ;i < segmentedPoints.getSize(); i++)
	{

		painter.drawEllipse(segmentedPoints.getPoint(i).x-3,segmentedPoints.getPoint(i).y-3,6,6);

		//painter.drawLine(points.getPoint(i-1).x, points.getPoint(i-1).y, points.getPoint(i).x,points.getPoint(i).y);
	}

	//pixmap->save("/home/ali/5.png");


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
=======
    if ( e->x() < width() && e->y() < height())
    {
        if (DrawingArea::lastx == 0 && DrawingArea::lasty == 0)
        {
            DrawingArea::lastx = e->x();
            DrawingArea::lasty = e->y();
        }
        QPainter painter(DrawingArea::pixmap);
        painter.setPen(Qt::black);
        painter.drawLine( DrawingArea::lastx , DrawingArea::lasty , e->x() , e->y() );


        DrawingArea::pointsX.push_back(e->x());
        DrawingArea::pointsY.push_back(e->y());


        DrawingArea::lastx = e->x();
        DrawingArea::lasty = e->y();
        update();
    }
    else
    {
        DrawingArea::lastx = 0;
        DrawingArea::lasty = 0;
    }
}
void DrawingArea::mouseReleaseEvent(QMouseEvent *)
{
    DrawingArea::lastx = 0;
    DrawingArea::lasty = 0;

    //just for testing, we will have a tester class later ;)

    PreProcessing::Scale scale;
    scale.scaleWidth = 400;
    scale.rectScale(DrawingArea::pointsX, DrawingArea::pointsY);


    DrawingArea::pointsX = scale.getPointsX();
    DrawingArea::pointsY = scale.getPointsY();

    PreProcessing::LinePoints linePoints;
    linePoints.linesPoints(DrawingArea::pointsX, DrawingArea::pointsY);

    DrawingArea::pointsX = linePoints.getPointsX();
    DrawingArea::pointsY = linePoints.getPointsY();

    QPainter painter(DrawingArea::pixmap);
    painter.setPen(Qt::red);
    painter.drawRect(0,0,400 ,400 - 1);
    painter.setPen(Qt::blue);

    for (unsigned int i = 0; i < DrawingArea::pointsX.size() ; i++)
    {
        painter.drawEllipse(DrawingArea::pointsX[i], DrawingArea::pointsY[i],1,0);
    }  

    update();
}

void DrawingArea::showEvent(QShowEvent *)
{
    DrawingArea::lastx = 0;
    DrawingArea::lasty = 0;

    DrawingArea::pixmap =  new QPixmap(width(),height());
    QPainter painter(DrawingArea::pixmap);

    painter.fillRect(0,0,width(),height(),Qt::white);
    update();
}

void DrawingArea::on_resetButton_clicked()
{
    DrawingArea::pointsX.clear();
    DrawingArea::pointsY.clear();

    QPainter painter(DrawingArea::pixmap);
    painter.fillRect(0,0,width(),height(),Qt::white);
    update();
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}
