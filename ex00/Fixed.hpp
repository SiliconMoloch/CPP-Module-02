/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:12:54 by yabokhar          #+#    #+#             */
/*   Updated: 2025/08/09 19:13:39 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed

{
	private:
		int					_value;
		static const int	_fractional_bits_number = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &old);
		Fixed& operator=(Fixed &old);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
