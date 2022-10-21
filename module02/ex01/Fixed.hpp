#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class Fixed
{
	int		value;
	static const int nfb = 8;
	public:
	Fixed();
	Fixed(const int&);
	Fixed(const float&);
	Fixed(const Fixed&);
	Fixed &operator = (const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	int	getNbFractalBits() const;
	void SetRawBits(int const);
	float toFloat(void) const;
	int toInt(void) const;
	friend std::ostream& operator << (std::ostream& os, const Fixed&);
};
#endif
