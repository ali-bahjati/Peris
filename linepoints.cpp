#include "linepoints.h"

using namespace PreProcessing;

LinePoints::LinePoints()
{
}

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

        Xdiff = lineX[0] - x1;
        Ydiff = lineY[0] - y1;
        newX = lineX[1] - Xdiff;
        newY = lineY[1] - Ydiff;

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
}
