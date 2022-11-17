#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>
class Fixed
{
	int		value;
	static const int fractional_bits = 8;
	public:
	Fixed();
	Fixed(const Fixed&);
	Fixed &operator = (const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	void SetRawBits(int const);
};
#endif
