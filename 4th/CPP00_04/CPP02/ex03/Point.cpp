#include "Point.hpp"

Point::Point(void)
{
	_x = Fixed(0);
	_y = Fixed(0);
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	// // TODO remove
	// std::cout << "x: " << _x << std::endl;
	// std::cout << "y: " << _y << std::endl;
}

Point::Point(const Point &t) : _x(t._x), _y(Fixed(t._y))
{
}

Point &Point::operator=(const Point &t)
{
	if (this != &t)
	{
		_x = t._x;
		_y = t._y;
	}
	return (*this);
}

Point::~Point(void)
{
}

float Point::getXValue(void) const
{
	return (_x.toFloat());
}

float Point::getYValue(void) const
{
	return (_y.toFloat());
}

Point Point::getVec(const Point &t) const
{
	Point vec(t.getXValue() - this->getXValue(), t.getYValue() - this->getYValue());
	return (vec);
}
