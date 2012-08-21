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
        void rectScale( vector<unsigned int> x, vector<unsigned int> y);
        void squareScale( vector<unsigned int> x, vector<unsigned int> y);
        vector<unsigned int> getPointsX();
        vector<unsigned int> getPointsY();

        int scaleWidth;

    private:
        int* drawingRect(vector<unsigned int> x, vector<unsigned int> y);
        vector<unsigned int> pointsX;
        vector<unsigned int> pointsY;
    };
}
#endif // SCALE_H
