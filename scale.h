#ifndef SCALE_H
#define SCALE_H

<<<<<<< HEAD
#include "point.h"

namespace PreProcessing
{
	class Scale
	{
	public:
		Scale();
		void rectScale(PList&,double);
		void squareScale(PList&,double);


	};

}

=======
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
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
#endif // SCALE_H
