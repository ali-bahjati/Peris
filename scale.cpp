#include "scale.h"
using namespace PreProcessing;
<<<<<<< HEAD

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
		p.x =( points.getPoint(i).x - dRect.getPoint(0).x) * ratio;
		p.y =( points.getPoint(i).y - dRect.getPoint(0).y) * ratio;

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
=======
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


    for(unsigned int i = 0; i < x.size(); i++)
    {
        float newX = static_cast<float>((x[i] - drawingRect[1]) * ratio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
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

    for(unsigned int i = 0; i < x.size(); i++)
    {
        float newX = static_cast<float>((x[i] - drawingRect[1]) * xRatio);

        pointsX.push_back(newX);
    }

    for(unsigned int i = 0; i < y.size(); i++)
    {
        float newY = static_cast<float>((y[i] - drawingRect[3]) * yRatio);

        pointsY.push_back(newY);
    }
}

int* Scale::drawingRect(vector<float> x, vector<float> y)
{
    int* rect = new int[4];
    float maximum = 0;

    for (unsigned int i = 0; i< x.size(); i++)
        if (maximum < x[i])
            maximum = x[i];

    float minimum = maximum;

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
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}
