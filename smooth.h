#ifndef SMOOTH_H
#define SMOOTH_H

#include <vector>
#include "linepoints.h"
using namespace std;

namespace PreProcessing
{
    class Smooth
    {
    public:
        Smooth();
        void smoothPoints(vector<double> x, vector<double> y);
        void smoothPoint(vector<double> x, vector<double> y);
        vector<double> getPointsX();
        vector<double> getPointsY();

        double ratio;

    private:
        vector<double> pointsX;
        vector<double> pointsY;
    };
}
#endif // SMOOTH_H
