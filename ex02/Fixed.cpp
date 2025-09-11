/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 14:06:07 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)

{
	this->_value = 0;
}

Fixed::Fixed(int const value)

{
	this->_value = value << _fractional_bits_number;
}

Fixed::Fixed(float const value)

{
	this->_value = roundf(value * (1 << _fractional_bits_number));
}

Fixed::Fixed(const Fixed &old)

{
	this->_value = old._value;
}

Fixed&	Fixed::operator=(Fixed const &old)

{
	if (this != &old)
		this->_value = old.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &to_add) const
	{	return (Fixed(this->toFloat() + to_add.toFloat()));	}

Fixed	Fixed::operator-(Fixed const &to_subtract) const
	{	return (Fixed(this->toFloat() - to_subtract.toFloat()));	}

Fixed	Fixed::operator*(Fixed const &to_multiply) const
	{	return (Fixed(this->toFloat() * to_multiply.toFloat()));	}

Fixed	Fixed::operator/(Fixed const &to_divide) const
	{	return (Fixed(this->toFloat() / to_divide.toFloat()));	}

bool	Fixed::operator>(Fixed const &to_compare) const
	{ return (this->toFloat() > to_compare.toFloat()) ;}
bool	Fixed::operator<(Fixed const &to_compare) const
	{ return (this->toFloat() < to_compare.toFloat()) ;}
bool	Fixed::operator>=(Fixed const &to_compare) const
	{ return (this->toFloat() >= to_compare.toFloat()) ; }
bool	Fixed::operator<=(Fixed const &to_compare) const
	{ return (this->toFloat() <= to_compare.toFloat()) ; }
bool	Fixed::operator==(Fixed const &to_compare) const
	{ return (this->toFloat() == to_compare.toFloat()) ; }
bool	Fixed::operator!=(Fixed const &to_compare) const
	{ return (this->toFloat() != to_compare.toFloat()) ; }
Fixed&	Fixed::operator++(void)
	{ _value++; return (*this); }
Fixed&	Fixed::operator--(void)
	{ _value--; return (*this); }
Fixed	Fixed::operator++(int)
	{ const Fixed return_value = *this; ++_value; return (return_value) ;}
Fixed	Fixed::operator--(int)
	{ const Fixed return_value = *this; --_value; return (return_value) ;}

Fixed&			Fixed::min(Fixed& a, Fixed& b)
		{ return (a < b ? a : b); }
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
		{ return (a < b ? a : b); }

Fixed&			Fixed::max(Fixed& a, Fixed& b)
		{ return (a > b ? a : b); }
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
		{ return (a > b ? a : b); }

Fixed::~Fixed(void) {}

int	Fixed::getRawBits(void) const

{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)

{
	this->_value = raw;
}

float	Fixed::toFloat(void) const

{
	return ((float)this->_value / (1 << _fractional_bits_number));
}

int Fixed::toInt(void) const

{
	return (this->_value >> _fractional_bits_number);
}

std::ostream&	operator<<(std::ostream &out, Fixed const &n)

{
	out << n.toFloat();
	return (out);
}
