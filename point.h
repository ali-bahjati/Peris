#ifndef POINT_H
#define POINT_H

#include <cmath>
class Point
{
public:
	Point();
	Point(int,int);
	Point(int,int,Point*);
	Point(const Point&);
	bool operator==(const Point&);

	double x;
	double y;

	Point* next;
};

class PList
{
public:
	PList();
	PList(const PList&);
	~PList();
	void operator =(const PList&);
	Point& operator [](int);

	int getSize();
	///Functions

	void pushPoint(Point);
	Point popPoint();

	Point& getPoint(int);

	void removeIndex(int);
	void replaceIndex(int, Point);
	void setNextIndex(int, Point);

	void clear();

	//Some Features about points
	PList drawingRect();
	void rotatePoints(double);
	void makeBest();
	void removeRepetition();

private:
	Point *startPoint;
	int s;

};

#endif // POINT_H
