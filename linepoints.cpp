#include "linepoints.h"
using namespace PreProcessing;
using namespace std;

LinePoints::LinePoints()
{
}

Point LinePoints::pointOfLine(double i, PList points)
{
	Scale scaler;
	Point p = points.getPoint(0);

	scaler.rectScale(points,i);

	Point newPoint;
	newPoint.x = points.getPoint(1).x + p.x - points.getPoint(0).x;
	newPoint.y = points.getPoint(1).y + p.y - points.getPoint(0).y;

	return newPoint;
}

PList LinePoints::getLinesPoints(PList points)
{

	PList result;
	for(int i = 1; i < points.getSize(); i++)
	{
		double rate;
		if ( abs(points.getPoint(i-1).x - points.getPoint(i).x) > abs(points.getPoint(i-1).y - points.getPoint(i).y))
			rate = abs(points.getPoint(i-1).x - points.getPoint(i).x);
		else
			rate = abs(points.getPoint(i-1).y - points.getPoint(i).y);



		PList p;
		p.pushPoint(points.getPoint(i-1));
		p.pushPoint(points.getPoint(i));

		for (int j = 0; j < rate; j++)
		{

			result.pushPoint(pointOfLine(j,p));
		}
	}

	return result;
}
