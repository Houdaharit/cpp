#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
	int		value;
	static const int nfb;
	public:
	Fixed();
	Fixed(const Fixed&);
	Fixed &operator = (const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	void SetRawBits(int const);
};
#endif
