#include "Point.hpp"

Fixed getArea(Point const a, Point const b, Point const c)
{
	Point vec1 = a.getVec(b);
	Point vec2 = a.getVec(c);
	Fixed area((vec1.getXValue() * vec2.getYValue() - vec1.getYValue() * vec2.getXValue()) / 2);

	if (area < 0)
	{
		std::cout << "area: " << -area << std::endl;
		return (-area);
	}
	std::cout << "area: " << area << std::endl;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC;
	Fixed areaABP;
	(void)point;
	areaABC = getArea(a, b, c);
	if (areaABC == 0 || getArea(point, a, b) == 0 || getArea(point, b, c) == 0 || getArea(point, c, a) == 0)
	{
		std::cout << "the point is a vertex or on edge" << std::endl;
		return (false);
	}
	areaABP = getArea(point, a, b) + getArea(point, b, c) + getArea(point, c, a);
	std::cout << "area ABC: " << areaABC << std::endl;
	std::cout << "area ABP: " << areaABP << std::endl;
	return (areaABC == areaABP);
}
