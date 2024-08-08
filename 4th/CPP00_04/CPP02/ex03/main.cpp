#include "Point.hpp"

int main(void)
{
	// Setup point a, b, and c
	// Point a(0, 5);
	// Point b(5, 0);
	// Point c(0, 0);
	Point a(100, 100);
	Point b(100, -100);
	Point c(-100, -100);
	Point point(1, 0.5);
	if (bsp(a, b, c, point))
		std::cout << "If the point is inside: " << "Yes!" << std::endl;
	else
		std::cout << "If the point is inside: " << "No..." << std::endl;
	return 0;
}
