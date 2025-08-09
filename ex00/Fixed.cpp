/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yabokhar          #+#    #+#             */
/*   Updated: 2025/08/09 19:18:52 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
using std::cout;
using std::endl;

Fixed::Fixed(void)

{
	cout << "Default constructor called" << endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &old)

{
	cout << "Copy constructor called" << endl;
	this->_value = old.getRawBits();
}

Fixed&	Fixed::operator=(Fixed &old)

{
	cout << "Copy assignment operator called" << endl;

	if (this != &old)
		this->_value = old.getRawBits();
	return *this;
}

Fixed::~Fixed(void) { cout << "Destructor called" << endl ;}

int	Fixed::getRawBits(void) const

{
	cout << "getRawBits member function called" << endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)

{
	this->_value = raw;
}
