/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/08/09 21:18:22 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

Fixed::Fixed(void)

{
	cout << "Default constructor called" << endl;
	this->_value = 0;
}

Fixed::Fixed(int const value)

{
	cout << "Int constructor called" << endl;
	this->_value = value << _fractional_bits_number;
}

Fixed::Fixed(float const value)

{
	cout << "Float constructor called" << endl;
	this->_value = roundf(value * (1 << _fractional_bits_number));
}

Fixed::Fixed(const Fixed &old)

{
	cout << "Copy constructor called" << endl;
	this->_value = old._value;
}

Fixed&	Fixed::operator=(Fixed const &old)

{
	cout << "Copy assignment operator called" << endl;

	if (this != &old)
		this->_value = old.getRawBits();
	return *this;
}

Fixed::~Fixed(void) { cout << "Destructor called" << endl ;}

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
