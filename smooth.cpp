#include "smooth.h"
using namespace PreProcessing;

Smooth::Smooth()
{
    Smooth::ratio = 1;
}

void Smooth::smoothPoints(vector<double> x, vector<double> y)
{
    Smooth::pointsX.clear();
    Smooth::pointsY.clear();

    if (x.size() > 2)
    {
        Smooth::pointsX.push_back(x[0]);
        Smooth::pointsY.push_back(y[0]);

        for (unsigned int i = 1; i < x.size() - 1; i++)
        {
            vector<double> pointAroundX;
            vector<double> pointAroundY;
            for (unsigned int j = i -1 ; j < i + 2 ; j++)
            {
                pointAroundX.push_back(x[j]);
                pointAroundY.push_back(y[j]);
            }

            Smooth::smoothPoint(pointAroundX, pointAroundY);
        }

        Smooth::pointsX.push_back(x[x.size() -1]);
        Smooth::pointsY.push_back(y[y.size() -1]);
    }
    else
    {
        Smooth::pointsX = x;
        Smooth::pointsY = y;
    }
}

void Smooth::smoothPoint(vector<double> x, vector<double> y)
{
    double newPointX = (x[0] + x[2])/2;
    double newPointY = (y[0] + y[2])/2;

    if (!(newPointX == x[1] && newPointY == y[1]))
    {
        vector<double> linePointX,linePointY;

        linePointX.push_back(x[1]);
        linePointY.push_back(y[1]);
        linePointX.push_back(newPointX);
        linePointY.push_back(newPointY);

        LinePoints linePoints;

        linePoints.pointOfLine(Smooth::ratio,linePointX, linePointY);
        linePointX = linePoints.getPointsX();
        linePointY = linePoints.getPointsY();

        newPointX = linePointX[0];
        newPointY = linePointY[0];
    }

    Smooth::pointsX.push_back(newPointX);
    Smooth::pointsY.push_back(newPointY);
}
vector<double> Smooth::getPointsX()
{
    return Smooth::pointsX;
}

vector<double> Smooth::getPointsY()
{
    return Smooth::pointsY;
}
