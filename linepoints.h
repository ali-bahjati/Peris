#ifndef LINEPOINTS_H
#define LINEPOINTS_H

#include <cmath>
#include "point.h"
#include "scale.h"

namespace PreProcessing
{
	class LinePoints
	{
	public:
		LinePoints();
		PList getLinesPoints(PList);
		Point pointOfLine(double,PList);
	};
}

#endif // LINEPOINTS_H
