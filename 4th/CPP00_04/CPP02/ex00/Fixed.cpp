#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedNum = 0;
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
	_fixedNum = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedNum);
}
