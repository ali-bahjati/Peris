#include "linepoints.h"
<<<<<<< HEAD
using namespace PreProcessing;
using namespace std;
=======

using namespace PreProcessing;
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482

LinePoints::LinePoints()
{
}

<<<<<<< HEAD
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
=======
void LinePoints::linesPoints(vector<float> x, vector<float> y)
{
    if (x.size() > 1)
    {
        LinePoints::pointsX.push_back(x[0]);
        LinePoints::pointsY.push_back(y[0]);

        for (unsigned int i = 1; i < x.size(); i++)
        {
            LinePoints::linePoints(x[i-1],y[i-1],x[i],y[i]);
            LinePoints::pointsX.push_back(x[i]);
            LinePoints::pointsY.push_back(y[i]);
        }
    }
}

void LinePoints::linePoints(float x1, float y1, float x2, float y2)
{
    Scale scaler;

    vector<float> lineX(2);
    vector<float> lineY(2);

    lineX[0] = x1;
    lineX[1] = x2;
    lineY[0] = y1;
    lineY[1] = y2;

    int rate = LinePoints::rate( abs( x1 - x2 ) , abs ( y1 - y2 ) );

    for (int i = 1; i < rate + 1; i++)
    {
        scaler.scaleWidth = i;
        scaler.rectScale(lineX,lineY);
        lineX = scaler.getPointsX();
        lineY = scaler.getPointsY();

        int Xdiff,Ydiff;
        int newX, newY;

        Xdiff = x1 - lineX[0];
        Ydiff = y1 - lineY[0];
        newX = lineX[1] + Xdiff;
        newY = lineY[1] + Ydiff;

        LinePoints::pointsX.push_back(newX);
        LinePoints::pointsY.push_back(newY);

    }
}

int LinePoints::rate(int xRate, int yRate)
{
    int rate;
    if (xRate > yRate)
        rate = xRate;
    else
        rate = yRate;

    return rate;
}

vector<float> LinePoints::getPointsX()
{
    return LinePoints::pointsX;
}

vector<float> LinePoints::getPointsY()
{
    return LinePoints::pointsY;
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}
