#include "Fixed.hpp"

void Fixed::_ofMsg(void) const
{
	std::cerr << "Overflow happens!!" << std::endl;
	exit(1);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Constructor for integer number called" << std::endl;
	if (num >= (1 << 23) || num < -(1 << 23))
		_ofMsg();
	_fixedNum = num << _numBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Constructor for float number called" << std::endl;
	if (num >= (1 << 23) || num < -(1 << 23))
		_ofMsg();
	_fixedNum = roundf(num * (1 << _numBits));
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedNum = t._fixedNum;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		_fixedNum = t._fixedNum;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	if (raw >= (1 << 23) || raw < -(1 << 23))
		_ofMsg();
	_fixedNum = raw;
}

int Fixed::getRawBits(void) const
{
	return (_fixedNum);
}

float Fixed::toFloat(void) const
{
	return ((float)(_fixedNum / (float)(1 << _numBits)));
}

int Fixed::toInt(void) const
{
	return (_fixedNum >> _numBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
