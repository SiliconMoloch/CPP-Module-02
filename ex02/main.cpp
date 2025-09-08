/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:11:01 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/08 19:09:17 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)

{
	Fixed const	a(1);
	Fixed const	b(1);
	Fixed		result;

	result = a + b;
	std::cout << "🥁 Heeey... 🥁 Heeey... 1 + 1\n" << result << std::endl;
	result = result + result;
	std::cout << "𝄞 2 + 2 𝄞\n" << result << std::endl;
	result = result + result;
	std::cout << "𝄞 4 + 4 𝄞\n" << result << std::endl;
	result = a / b;
	std::cout << " 🥁 8 / 8 🥁\n" <<  result << std::endl;

	const Fixed max(4.99f);
	const Fixed min(5.01f);
	std::cout << (min < max) << std::endl;
	std::cout << (min > max) << std::endl;
	std::cout << (min >= max) << std::endl;
	std::cout << (min <= max) << std::endl;
	std::cout << (min == max) << std::endl;
	std::cout << (min != max) << std::endl;

	Fixed	test;
	std::cout << test.max(max, min) << std::endl;
	return (0);
}
