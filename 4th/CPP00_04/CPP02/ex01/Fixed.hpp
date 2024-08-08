#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>
#include <limits>

class Fixed
{
  private:
	int _fixedNum;
	static const int _numBits = 8;
	void _ofMsg(void) const;

  public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &t);
	Fixed &operator=(const Fixed &t);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
