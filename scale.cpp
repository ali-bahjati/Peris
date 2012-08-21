#include "scale.h"
using namespace PreProcessing;
Scale::Scale()
{
    Scale::scaleWidth = 500;
}

void Scale::rectScale(vector<unsigned int> x, vector<unsigned int> y)
{
    int* drawingRect = Scale::drawingRect(x,y);
    float ratio;

    if ( drawingRect[0] - drawingRect[1] > drawingRect[2] - drawingRect[3])
        ratio = Scale::scaleWidth / static_cast<float>(drawingRect[0] - drawingRect[1]);
    else
        ratio = Scale::scaleWidth / static_cast<float>(drawingRect[2] - drawingRect[3]);


    for(unsigned int i = 0; i < x.size(); i++)
    {
        int newX = static_cast<int>((x[i] - drawingRect[1]) * ratio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
    {
        int newY = static_cast<int>((y[i] - drawingRect[3]) * ratio);

        pointsY.push_back(newY);
    }

}

void Scale::squareScale(vector<unsigned int> x, vector<unsigned int> y)
{
    int* drawingRect = Scale::drawingRect(x,y);

    float xRatio = Scale::scaleWidth / static_cast<float>(drawingRect[0] - drawingRect[1]);
    float yRatio = Scale::scaleWidth / static_cast<float>(drawingRect[2] - drawingRect[3]);

    for(unsigned int i = 0; i < x.size(); i++)
    {
        int newX = static_cast<int>((x[i] - drawingRect[1]) * xRatio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
    {
        int newY = static_cast<int>((y[i] - drawingRect[3]) * yRatio);

        pointsY.push_back(newY);
    }
}

int* Scale::drawingRect(vector<unsigned int> x, vector<unsigned int> y)
{
    int* rect = new int[4];
    unsigned int maximum = 0;

    for (unsigned int i = 0; i< x.size(); i++)
        if (maximum < x[i])
            maximum = x[i];

    unsigned int minimum = maximum;

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

vector<unsigned int> Scale::getPointsX()
{
    return pointsX;
}

vector<unsigned int> Scale::getPointsY()
{
    return pointsY;
}

