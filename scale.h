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
        void rectScale( vector<float> x, vector<float> y);
        void squareScale( vector<float> x, vector<float> y);
        vector<float> getPointsX();
        vector<float> getPointsY();

        int scaleWidth;

    private:
        int* drawingRect(vector<float> x, vector<float> y);
        void clearPoints();

        vector<float> pointsX;
        vector<float> pointsY;
    };
}
#endif // SCALE_H
