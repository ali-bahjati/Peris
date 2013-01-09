#include "segmentpoints.h"

using namespace Processing;

SegmentPoints::SegmentPoints()
{
}

PList SegmentPoints::getSegmentPoints_FPCAlgorithm(PList points, int reduction) //FPC Algorithm : Four Point in Circle Algorithm :)
{
	PList segmentedPoints;
	for(int i = 0 ; i < points.getSize() ; i++)
		if ( i % reduction == 0 )
			segmentedPoints.pushPoint(points.getPoint(i));

	bool adjacent = true;

	for(int i = 0 ;i < segmentedPoints.getSize(); i++)
	{
		if ( i == 0 || i == segmentedPoints.getSize() - 1 )
			continue;

		Point p1 = segmentedPoints.getPoint(i-1);
		Point p2 = segmentedPoints.getPoint(i);
		Point p3 = segmentedPoints.getPoint(i + 1);

		if ( !( ( p2.x > p1.x && p2.x > p3.x ) || ( p2.y > p1.y && p2.y > p3.y ) ||
				( p2.x < p1.x && p2.x < p3.x ) || ( p2.y < p1.y && p2.y < p3.y ) ) ||
			 adjacent )
		{
			adjacent = false;
			segmentedPoints.removeIndex(i);
			i--;
		}
		else
			adjacent = true;
	}

	return segmentedPoints;
}
