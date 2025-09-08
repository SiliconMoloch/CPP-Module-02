/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/08 19:08:50 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)

{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const value)

{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractional_bits_number;
}

Fixed::Fixed(float const value)

{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractional_bits_number));
}

Fixed::Fixed(const Fixed &old)

{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = old._value;
}

Fixed&	Fixed::operator=(Fixed const &old)

{
	std::cout << "Copy assignment operator called" << std::endl;

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
		{ return (a.getRawBits() > b.getRawBits() ? b : a); }
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
		{ return (a.getRawBits() > b.getRawBits() ? b : a); }

Fixed&			Fixed::max(Fixed& a, Fixed& b)
		{ return (a.getRawBits() < b.getRawBits() ? b : a); }
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
		{ return (a.getRawBits() < b.getRawBits() ? b : a); }

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl ;}

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
