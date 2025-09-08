/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:12:54 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/08 19:09:05 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#define EPSILON 0.00390625f
#include <iostream>

class Fixed

{
	private:
		int					_value;
		static const int	_fractional_bits_number = 8;
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed &old);
		Fixed&	operator=(Fixed const &old);
		Fixed	operator+(Fixed const &to_add) const;
		Fixed	operator-(Fixed const &to_subtract) const;
		Fixed 	operator*(Fixed const &to_multiply) const;
		Fixed	operator/(Fixed const &to_divide) const;
		bool	operator>(Fixed const &to_compare) const;
		bool	operator<(Fixed const &to_compare) const;
		bool	operator>=(Fixed const &to_compare) const;
		bool	operator<=(Fixed const &to_compare) const;
		bool	operator==(Fixed const &to_compare) const;
		bool	operator!=(Fixed const &to_compare) const;
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&		min(Fixed& a, Fixed &b);
		const static Fixed&	min(const Fixed& a, const Fixed &b);
		static Fixed&		max(Fixed& a, Fixed &b);
		const static Fixed&	max(const Fixed& a, const Fixed &b);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &n);

#endif
