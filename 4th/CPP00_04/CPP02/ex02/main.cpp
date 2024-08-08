#include "Fixed.hpp"

int main(void)
{
	// Fixed a((1 << 23) - 2);
	Fixed a(2);
	Fixed b(4);
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// Fixed b(-(1 << 23) + 1);
	Fixed const c(3);
	Fixed const d(10);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	// Tests for operators: >, <, >=, <=, == and !=.
	std::cout << "Operator\">\": " << (a > b) << std::endl;
	std::cout << "Operator\"<\": " << (a < b) << std::endl;
	std::cout << "Operator\">=\": " << (a >= b) << std::endl;
	std::cout << "Operator\"<=\": " << (a <= b) << std::endl;
	std::cout << "Operator\"==\": " << (a == b) << std::endl;
	std::cout << "Operator\"!=\": " << (a != b) << std::endl;
	// Tests for operators: +, -, *, and /.
	std::cout << "Operator\"+\": " << (a + b) << std::endl;
	std::cout << "Operator\"-\": " << (a - b) << std::endl;
	std::cout << "Operator\"*\": " << (a * b) << std::endl;
	std::cout << "Operator\"/\": " << (a / b) << std::endl;
	// Tests for pre-increment, post-increment, pre-decrement and post-decrement
	std::cout << "a: " << a << std::endl;
	std::cout << "Pre \"++\": " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Post \"++\": " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	// Test for min and max
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(c, d) << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "min: " << Fixed::min(c, d) << std::endl;
	return 0;
}
