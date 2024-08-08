#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
  private:
	int _fixedNum;
	static const int _numBits = 8;

  public:
	Fixed(void);
	Fixed(const Fixed &t);
	Fixed &operator=(const Fixed &t);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
