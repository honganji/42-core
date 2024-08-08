#include "Fixed.hpp"

void Fixed::_ofMsg(void) const
{
	std::cerr << "Overflow happens!!" << std::endl;
	exit(1);
}

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	_fixedNum = 0;
}

Fixed::Fixed(int const num)
{
	// std::cout << "Constructor for integer number called" << std::endl;
	if (num >= (1 << 23) || num < -(1 << 23))
		_ofMsg();
	_fixedNum = num << _numBits;
}

Fixed::Fixed(float const num)
{
	// std::cout << "Constructor for float number called" << std::endl;
	if (num >= (1 << 23) || num < -(1 << 23))
		_ofMsg();
	_fixedNum = roundf(num * (1 << _numBits));
}

Fixed::Fixed(const Fixed &t)
{
	// std::cout << "Copy constructor called" << std::endl;
	_fixedNum = t._fixedNum;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		_fixedNum = t._fixedNum;
	return *this;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	if (raw >= (1 << 23) || raw < -(1 << 23))
		_ofMsg();
	_fixedNum = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

// Functions for operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed &t) const
{
	return (this->toFloat() > t.toFloat());
}

bool Fixed::operator<(const Fixed &t) const
{
	return (this->toFloat() < t.toFloat());
}

bool Fixed::operator>=(const Fixed &t) const
{
	return (this->toFloat() >= t.toFloat());
}

bool Fixed::operator<=(const Fixed &t) const
{
	return (this->toFloat() <= t.toFloat());
}

bool Fixed::operator==(const Fixed &t) const
{
	return (this->toFloat() == t.toFloat());
}

bool Fixed::operator!=(const Fixed &t) const
{
	return (this->toFloat() != t.toFloat());
}

// Functions for operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed &t) const
{
	if (((1 << 23) - t.toFloat() <= this->toFloat()) || (-(1 << 23) - t.toFloat() > this->toFloat()))
		_ofMsg();
	return (Fixed(this->toFloat() + t.toFloat()));
}

Fixed Fixed::operator-(const Fixed &t) const
{
	if ((1 << 23) + t.toFloat() <= this->toFloat() || -(1 << 23) + t.toFloat() > this->toFloat())
		_ofMsg();
	return (Fixed(this->toFloat() - t.toFloat()));
}

Fixed Fixed::operator*(const Fixed &t) const
{
	if (t.toFloat() == 0)
		return (Fixed(0));
	if ((1 << 23) / t.toFloat() <= this->toFloat() || -(1 << 23) / t.toFloat() > this->toFloat())
		_ofMsg();
	return (Fixed(this->toFloat() * t.toFloat()));
}

Fixed Fixed::operator/(const Fixed &t) const
{
	if (t.toFloat() == 0)
		_ofMsg();
	if ((1 << 23) * t.toFloat() <= this->toFloat() || -(1 << 23) * t.toFloat() > this->toFloat())
		_ofMsg();
	return (Fixed(this->toFloat() / t.toFloat()));
}

// Functions for pre-increment, post-increment, pre-decrement and post-decrement
Fixed &Fixed::operator++(void)
{
	if (((1 << 23) - 1 <= this->toFloat()) || (-(1 << 23) - 1 > this->toFloat()))
		_ofMsg();
	_fixedNum++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	if (((1 << 23) - 1 <= this->toFloat()) || (-(1 << 23) - 1 > this->toFloat()))
		_ofMsg();
	Fixed tmp(*this);
	_fixedNum++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	if (((1 << 23) + 1 <= this->toFloat()) || (-(1 << 23) + 1 > this->toFloat()))
		_ofMsg();
	_fixedNum++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	if (((1 << 23) + 1 <= this->toFloat()) || (-(1 << 23) + 1 > this->toFloat()))
		_ofMsg();
	Fixed tmp(*this);
	_fixedNum++;
	return (tmp);
}

// Functions for min and max
Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed &Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	return (n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed &Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	return (n2);
}
