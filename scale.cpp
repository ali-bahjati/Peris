#include "scale.h"
using namespace PreProcessing;
Scale::Scale()
{
    Scale::scaleWidth = 500;
}

void Scale::rectScale(vector<float> x, vector<float> y)
{
    int* drawingRect = Scale::drawingRect(x,y);
    float ratio;

    Scale::clearPoints();

    if ( drawingRect[0] - drawingRect[1] > drawingRect[2] - drawingRect[3])
        ratio = Scale::scaleWidth / static_cast<float>(drawingRect[0] - drawingRect[1]);
    else
        ratio = Scale::scaleWidth / static_cast<float>(drawingRect[2] - drawingRect[3]);


    for(float i = 0; i < x.size(); i++)
    {
        float newX = static_cast<float>((x[i] - drawingRect[1]) * ratio);

        pointsX.push_back(newX);
    }

    for(float i = 0; i < y.size(); i++)
    {
        float newY = static_cast<float>((y[i] - drawingRect[3]) * ratio);

        pointsY.push_back(newY);
    }

}

void Scale::squareScale(vector<float> x, vector<float> y)
{
    int* drawingRect = Scale::drawingRect(x,y);

    float xRatio = Scale::scaleWidth / static_cast<float>(drawingRect[0] - drawingRect[1]);
    float yRatio = Scale::scaleWidth / static_cast<float>(drawingRect[2] - drawingRect[3]);

    Scale::clearPoints();

    for(float i = 0; i < x.size(); i++)
    {
        float newX = static_cast<float>((x[i] - drawingRect[1]) * xRatio);

        pointsX.push_back(newX);
    }

    for(float i = 0; i < y.size(); i++)
    {
        float newY = static_cast<float>((y[i] - drawingRect[3]) * yRatio);

        pointsY.push_back(newY);
    }
}

int* Scale::drawingRect(vector<float> x, vector<float> y)
{
    int* rect = new int[4];
    float maximum = 0;

    for (float i = 0; i< x.size(); i++)
        if (maximum < x[i])
            maximum = x[i];

    float minimum = maximum;

    for (float i = 0; i< x.size(); i++)
        if (minimum > x[i])
            minimum = x[i];

    rect[0] = maximum;
    rect[1] = minimum;

    maximum = 0;

    for (float i = 0; i< y.size(); i++)
        if (maximum < y[i])
            maximum = y[i];

    minimum = maximum;

    for (float i = 0; i< y.size(); i++)
        if (minimum > y[i])
            minimum = y[i];

    rect[2] = maximum;
    rect[3] = minimum;

    return rect;
}

vector<float> Scale::getPointsX()
{
    return Scale::pointsX;
}

vector<float> Scale::getPointsY()
{
    return Scale::pointsY;
}

void Scale::clearPoints()
{
    Scale::pointsX.clear();
    Scale::pointsY.clear();
}
