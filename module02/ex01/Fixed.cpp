#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called!" << std::endl;
	this->value = fixed.value;
}

Fixed::Fixed(const int &i)
{
	this->value = (int)roundf(i * (1 << nfb)); 
}

Fixed::Fixed(const float &f)
{
	this->value = (int)roundf(f * (1 << nfb)); 
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called!"<< std::endl;
	if (this != &fixed)
	{
		this->value = fixed.value;
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
	return (this->value);
}

void Fixed::SetRawBits(int const raw)
{
	std::cout << "SetRawBits function called!" << std::endl;
	this->value = raw;
}

int	Fixed::getNbFractalBits() const
{
	return (this->nfb);
}

int	Fixed::toInt(void) const
{
	return ((int)this->value / (int) (1 << nfb));	
}

float	Fixed::toFloat(void) const
{
	return ((float) this->value / (float) (1 << nfb));
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	os << (double)fixed.getRawBits() / (double)(1 << fixed.getNbFractalBits());
	return (os);
}
