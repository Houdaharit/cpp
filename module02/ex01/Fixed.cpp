/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:06 by hharit            #+#    #+#             */
/*   Updated: 2022/11/17 01:40:55 by hharit           ###   ########.fr       */
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
	std::cout << "Int constructor called!" << std::endl;
	this->value = (int)roundf(i * (1 << fractional_bits)); 
}

Fixed::Fixed(const float &f)
{
	std::cout << "Float constructor called!" << std::endl;
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
	os << (double)fixed.getRawBits() / (double)(1 << fixed.getNbFractalBits());
	return (os);
}
