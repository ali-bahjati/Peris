#ifndef SCALE_H
#define SCALE_H

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

#endif // SCALE_H
