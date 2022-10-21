#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <math>

class Fixed
{
	double		value;
	static const int nfb = 8;
	public:
	Fixed();
	Fixed(const int&);
	Fixed(const float&);
	Fixed(const Fixed&);
	Fixed &operator = (const Fixed&);
	// (<<) operator
	~Fixed();
	int getRawBits(void) const;
	void SetRawBits(int const);
	float toFloat(void) const;
	int toInt(void) const;
};
#endif
