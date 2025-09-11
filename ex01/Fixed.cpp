/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 13:59:35 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
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
		this->_value = old._value;
	return *this;
}

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
