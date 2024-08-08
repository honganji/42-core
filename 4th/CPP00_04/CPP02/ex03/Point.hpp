#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
  private:
	Fixed _x;
	Fixed _y;

  public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &t);
	Point &operator=(const Point &t);
	float getXValue(void) const;
	float getYValue(void) const;
	Point getVec(const Point &t) const;
	~Point(void);
};

Fixed getArea(Point const a, Point const b, Point const c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
