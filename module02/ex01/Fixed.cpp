#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called!" << std::endl;
	value = fixed.value;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called!"<< std::endl;
	if (this != &fixed)
	{
		value = fixed.value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called!" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called!" << std::endl;
	return (value);
}

void Fixed::SetRawBits(int const raw)
{
	std::cout << "SetRawBits function called!" << std::endl;
	this->value = raw;
}

int	toInt(void) const
{
	return ((int)value / (int) (1 << nfb));	
}

float	toFloat(void) const
{
	return ((float) value / (float) (1 << nfs))
}
