/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:12:54 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 13:53:24 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed

{
	private:
		int					_value;
		static const int	_fractional_bits_number = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &old);
		Fixed& operator=(Fixed const &old);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
