#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _fixedNum;
	static const int _numBits = 8;
	void _ofMsg(void) const;

  public:
	Fixed(void);
	Fixed(int const num);
	Fixed(float const num);
	Fixed(const Fixed &t);
	Fixed &operator=(const Fixed &t);
	bool operator>(const Fixed &t) const;
	bool operator<(const Fixed &t) const;
	bool operator>=(const Fixed &t) const;
	bool operator<=(const Fixed &t) const;
	bool operator==(const Fixed &t) const;
	bool operator!=(const Fixed &t) const;
	Fixed operator+(const Fixed &t) const;
	Fixed operator-(const Fixed &t) const;
	Fixed operator-(void) const;
	Fixed operator*(const Fixed &t) const;
	Fixed operator/(const Fixed &t) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &n1, Fixed &n2);
	static const Fixed &min(Fixed const &n1, Fixed const &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
	static const Fixed &max(Fixed const &n1, Fixed const &n2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
