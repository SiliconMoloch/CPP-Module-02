/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 13:54:34 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)

{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &old)

{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = old.getRawBits();
}

Fixed&	Fixed::operator=(Fixed const &old)

{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &old)
		this->_value = old.getRawBits();
	return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl ;}

int	Fixed::getRawBits(void) const

{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)

{
	this->_value = raw;
}
