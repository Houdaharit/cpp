/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:06 by hharit            #+#    #+#             */
/*   Updated: 2022/10/25 10:53:08 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->value = (int)roundf(i * (1 << fractional_bits)); 
}

Fixed::Fixed(const float &f)
{
	this->value = (int)roundf(f * (1 << fractional_bits)); 
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
	return (this->value);
}

void Fixed::SetRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::getNbFractalBits() const
{
	return (this->fractional_bits);
}

int	Fixed::toInt(void) const
{
	return ((int)this->value / (int) (1 << fractional_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float) this->value / (float) (1 << fractional_bits));
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	os << (float)fixed.getRawBits() / (float)(1 << fixed.getNbFractalBits());
	return (os);
}

bool operator < (const Fixed &first, const Fixed& second)
{
	return ((float)first.getRawBits() < (float)second.getRawBits());
}

bool operator > (const Fixed &first, const Fixed &second)
{
	return (float)first.getRawBits() > (float)second.getRawBits();
}

bool operator <= (const Fixed &first, const Fixed &second)
{
	return (float)first.getRawBits() <= (float)second.getRawBits();
}

bool operator >= (const Fixed &first, const Fixed& second)
{
	return (float)first.getRawBits() >= (float)second.getRawBits();
}

bool operator == (const Fixed &first, const Fixed& second)
{
	return (float)first.getRawBits() == (float)second.getRawBits();
}

bool operator != (const Fixed &first, const Fixed& second)
{
	return (float)first.getRawBits() != (float)second.getRawBits();
}

float Fixed::operator * (const Fixed& fixed)
{
	return toFloat() * fixed.toFloat();
}

float Fixed::operator + (const Fixed& fixed)
{
	return toFloat() + fixed.toFloat();
}

float Fixed::operator / (const Fixed& fixed)
{
	return toFloat() / fixed.toFloat();
}	

float Fixed::operator - (const Fixed& fixed)
{
	return toFloat() - fixed.toFloat();
}

Fixed& Fixed::operator ++ (void) 
{
	this->value++;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed fixed = *this;
	++(*this);
	return fixed;
}

Fixed& Fixed::operator -- (void)
{
	this->value--;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed fixed = *this;
	--(*this);
	return *this;
}

Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (Fixed&)second;
	else if (first < second)
		return (Fixed&)first;
	else
		return (Fixed&)first;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first > second)
		return second;
	else if (first < second)
		return first;
	else
		return first;
}

Fixed& Fixed::max(const Fixed& first, const Fixed& second)

{
	if (first < second)
		return (Fixed&)second;
	else if (first > second)
		return (Fixed&)first;
	else
		return (Fixed&)first;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first < second)
		return second;
	else if (first > second)
		return first;
	else
		return first;
}
