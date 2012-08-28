#ifndef SCALE_H
#define SCALE_H

#include <vector>

using namespace std;

namespace PreProcessing
{
    class Scale
    {
    public:
        Scale();
        void rectScale( vector<double> x, vector<double> y);
        void squareScale( vector<double> x, vector<double> y);
        vector<double> getPointsX();
        vector<double> getPointsY();

        double scaleWidth;

    private:
        int* drawingRect(vector<double> x, vector<double> y);
        void clearPoints();

        vector<double> pointsX;
        vector<double> pointsY;
    };
}
#endif // SCALE_H
