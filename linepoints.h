#ifndef LINEPOINTS_H
#define LINEPOINTS_H

#include <vector>
#include <cmath>
#include "scale.h"
using namespace std;
namespace PreProcessing
{
    class LinePoints
    {
    public:
        LinePoints();
        void linesPoints( vector<float> x , vector<float> y );
        void linePoints( float x1, float y1 , float x2 , float y2 );
        vector<float> getPointsX();
        vector<float> getPointsY();

    private:
        vector<float> pointsX;
        vector<float> pointsY;
        int rate(int xRate, int yRate);
    };
}
#endif // LINEPOINTS_H
