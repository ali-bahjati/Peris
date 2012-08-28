#include "scale.h"
using namespace PreProcessing;
Scale::Scale()
{
    Scale::scaleWidth = 500;
}

void Scale::rectScale(vector<double> x, vector<double> y)
{
    int* drawingRect = Scale::drawingRect(x,y);
    double ratio;

    Scale::clearPoints();

    if ( drawingRect[0] - drawingRect[1] > drawingRect[2] - drawingRect[3])
        ratio = Scale::scaleWidth / static_cast<double>(drawingRect[0] - drawingRect[1]);
    else
        ratio = Scale::scaleWidth / static_cast<double>(drawingRect[2] - drawingRect[3]);


    for(unsigned int i = 0; i < x.size(); i++)
    {
        double newX = static_cast<double>((x[i] - drawingRect[1]) * ratio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
    {
        double newY = static_cast<double>((y[i] - drawingRect[3]) * ratio);

        pointsY.push_back(newY);
    }

}

void Scale::squareScale(vector<double> x, vector<double> y)
{
    int* drawingRect = Scale::drawingRect(x,y);

    double xRatio = Scale::scaleWidth / static_cast<double>(drawingRect[0] - drawingRect[1]);
    double yRatio = Scale::scaleWidth / static_cast<double>(drawingRect[2] - drawingRect[3]);

    Scale::clearPoints();

    for(unsigned int i = 0; i < x.size(); i++)
    {
        double newX = static_cast<double>((x[i] - drawingRect[1]) * xRatio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
    {
        double newY = static_cast<double>((y[i] - drawingRect[3]) * yRatio);

        pointsY.push_back(newY);
    }
}

int* Scale::drawingRect(vector<double> x, vector<double> y)
{
    int* rect = new int[4];
    double maximum = 0;

    for (unsigned int i = 0; i< x.size(); i++)
        if (maximum < x[i])
            maximum = x[i];

    double minimum = maximum;

    for (unsigned int i = 0; i< x.size(); i++)
        if (minimum > x[i])
            minimum = x[i];

    rect[0] = maximum;
    rect[1] = minimum;

    maximum = 0;

    for (unsigned int i = 0; i< y.size(); i++)
        if (maximum < y[i])
            maximum = y[i];

    minimum = maximum;

    for (unsigned int i = 0; i< y.size(); i++)
        if (minimum > y[i])
            minimum = y[i];

    rect[2] = maximum;
    rect[3] = minimum;

    return rect;
}

vector<double> Scale::getPointsX()
{
    return Scale::pointsX;
}

vector<double> Scale::getPointsY()
{
    return Scale::pointsY;
}

void Scale::clearPoints()
{
    Scale::pointsX.clear();
    Scale::pointsY.clear();
}
