#ifndef SEGMENTPOINTS_H
#define SEGMENTPOINTS_H
#include "point.h"

namespace Processing
{
	class SegmentPoints
	{
	public:
		SegmentPoints();
		PList getSegmentPoints_FPCAlgorithm(PList, int);
	};
}

#endif // SEGMENTPOINTS_H
