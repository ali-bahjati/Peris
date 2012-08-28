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
        void linesPoints( vector<double> x , vector<double> y );
        void linePoints( double x1, double y1 , double x2 , double y2 );
        void pointOfLine ( double i, vector<double> lineX, vector<double> lineY);
        vector<double> getPointsX();
        vector<double> getPointsY();
    private:
        vector<double> pointsX;
        vector<double> pointsY;
        int rate(int xRate, int yRate);
    };
}
#endif // LINEPOINTS_H
