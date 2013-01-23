#include "scale.h"
using namespace PreProcessing;
using namespace std;
Scale::Scale()
{
}

void Scale::rectScale(PList& points, double scaleWidth)
{
	PList dRect = points.drawingRect();
	double ratio;

	if ( dRect.getPoint(1).x - dRect.getPoint(0).x > dRect.getPoint(1).y - dRect.getPoint(0).y )
		ratio = scaleWidth / static_cast<double>(dRect.getPoint(1).x - dRect.getPoint(0).x) ;
	else
		ratio = scaleWidth / static_cast<double>(dRect.getPoint(1).y - dRect.getPoint(0).y) ;

	for (int i = 0 ; i < points.getSize(); i++)
	{
		Point p;
		p.x = abs(points.getPoint(i).x - dRect.getPoint(0).x) * ratio;
		p.y = abs(points.getPoint(i).y - dRect.getPoint(0).y) * ratio;

		points.replaceIndex(i,p);
	}

	points.removeRepetition();
}

void Scale::squareScale(PList& points, double scaleWidth)
{
	PList dRect = points.drawingRect();
	double ratioX = scaleWidth / static_cast<double>(dRect.getPoint(1).x - dRect.getPoint(0).x );
	double ratioY = scaleWidth / static_cast<double>(dRect.getPoint(1).y - dRect.getPoint(0).y );

	for (int i = 0 ; i < points.getSize(); i++)
	{
		Point p;
		p.x =( points.getPoint(i).x - dRect.getPoint(0).x) * ratioX;
		p.y =( points.getPoint(i).y - dRect.getPoint(0).y) * ratioY;

		points.replaceIndex(i,p);
	}

	points.removeRepetition();
}
