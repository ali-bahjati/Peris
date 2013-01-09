#include "point.h"

Point::Point()
{
    x = -1;
    y = -1;
	next = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
	next = 0;
}

Point::Point(int x,int y, Point *next)
{
    this->x = x;
    this->y = y;
    this->next = next;
}

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	next = 0;
}

bool Point::operator ==(const Point& p)
{
	if (x == p.x && y == p.y)
		return true;
	return false;
}

PList::PList()
{
    startPoint = new Point();
	s = 0;

}
PList::PList(const PList& p)
{
	startPoint = new Point();
	Point* np = startPoint;
	Point* np2 = p.startPoint;
	s = p.s;
	for(int i = 0 ;i < p.s ; i++)
	{
		np->next = new Point(np2->next->x,np2->next->y);

		np2 = np2->next;
		np = np->next;
	}
}

void PList::operator =(const PList& p)
{
	while(s != 0)
		popPoint();

	startPoint = new Point();
	Point* np = startPoint;
	Point* np2 = p.startPoint;
	s = p.s;
	for(int i = 0 ;i < p.s ; i++)
	{
		np->next = new Point(*np2->next);

		np2 = np2->next;
		np = np->next;
	}
}

PList::~PList()
{
	while(s != 0 )
		popPoint();
}

void PList::pushPoint(Point p)
{
    Point *lastPoint = startPoint;
	while(lastPoint->next != 0)
        lastPoint = lastPoint->next;

    lastPoint->next = new Point(p);

	s++;
}

Point PList::popPoint()
{
    Point *lastPoint = startPoint;
	Point result;
	if (s==0)
        return *startPoint;

	while(lastPoint->next->next != 0)
        lastPoint = lastPoint->next;

    result = *lastPoint->next;
    delete lastPoint->next;
	lastPoint->next = 0;

	s--;

    return result;
}

Point& PList::getPoint(int index)
{
	Point *lastPoint = startPoint;
	int i = -1;
	while(lastPoint->next != 0)
	{
		i++;
		lastPoint = lastPoint->next;

		if (i == index)
		{
			return *lastPoint;
		}
	}
	return *(new Point());
}

void PList::removeIndex(int index)
{
    Point *lastPoint = startPoint;
    int i = -1;
	while(lastPoint->next != 0)
    {

        if (i == index - 1)
        {
            Point *next = lastPoint->next;
            lastPoint->next = lastPoint->next->next;
            delete next;
			s--;

            break;
        }

        i++;
        lastPoint = lastPoint->next;

	}
}

void PList::replaceIndex(int index, Point p)
{

    Point *lastPoint = startPoint;
    int i = -1;
	while(lastPoint->next != 0)
    {
        i++;
        lastPoint = lastPoint->next;

        if (i == index)
        {
            lastPoint->x = p.x;
            lastPoint->y = p.y;

            break;
        }
    }
}

void PList::setNextIndex(int index, Point p)
{
    Point *lastPoint = startPoint;
    int i = -1;
	if ( index == -1 )
	{
		Point* tmp = new Point(p.x,p.y,startPoint->next);
		startPoint->next = tmp;
		s++;

		return;
	}
	while(lastPoint->next != 0)
    {
        i++;
        lastPoint = lastPoint->next;

        if (i == index)
        {
            Point* tmp = new Point(p.x,p.y,lastPoint->next);
            lastPoint->next = tmp;

            break;
        }
    }

	s++;
}

int PList::getSize()
{
	return this->s;
}

void PList::clear()
{
	while(s != 0 )
		popPoint();
}


PList PList::drawingRect()
{
	PList result;
	int maxX = 0, maxY = 0 ,minX, minY;

	for(int i = 0;i < getSize(); i++)
	{
		Point p = getPoint(i);
		if ( p.x > maxX )
			maxX = p.x;
		if ( p.y > maxY )
			maxY = p.y;
	}

	minX = maxX;
	minY = maxY;

	for(int i =0 ;i < getSize();i++)
	{
		Point p = getPoint(i);
		if ( p.x < minX )
			minX = p.x;
		if (p.y < minY )
			minY = p.y;

	}
	Point p1(minX,minY);
	Point p2(maxX,maxY);
	result.pushPoint(p1);
	result.pushPoint(p2);

	return result;

}

void PList::removeRepetition()
{
	if (getSize() > 1)
		for(int i =1 ;i < getSize(); i++)
			if (getPoint(i) == getPoint(i-1))
			{
				removeIndex(i);
				i--;
			}
}
