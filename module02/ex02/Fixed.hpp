/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:34:09 by hharit            #+#    #+#             */
/*   Updated: 2022/10/25 10:52:59 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Fixed(const int&);
	Fixed(const float&);
	Fixed(const Fixed&);
	~Fixed();
	Fixed &operator = (const Fixed&);
	bool operator > (const Fixed&);
	bool operator < (const Fixed&);
	bool operator <= (const Fixed&);
	bool operator >= (const Fixed&);
	bool operator == (const Fixed&);
	bool operator != (const Fixed&);
	int getRawBits(void) const;
	int	getNbFractalBits() const;
	void SetRawBits(int const);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator << (std::ostream& os, const Fixed&);
#endif
