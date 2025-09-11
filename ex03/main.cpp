/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:11:01 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 13:17:52 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#define X 0
#define Y 1

static float	ft_atof(const char *s);

int	main(int argc, const char *argv[])

{
	if (argc ^ 9)
	{
		std::cout << "BSP: Usage <x1> <x2> ... <x8>" << std::endl;
		return (1);
	}
	Point a(ft_atof(argv[1]), ft_atof(argv[2]));
	Point b(ft_atof(argv[3]), ft_atof(argv[4]));
	Point c(ft_atof(argv[5]), ft_atof(argv[6]));
	Point point(ft_atof(argv[7]), ft_atof(argv[8]));
	if (bsp(a, b, c, point))
		std::cout << "The point is in the triangle." << std::endl;
	else
		std::cout << "The point is not in the triangle." << std::endl;
	std::cout << a.get(X) << " " <<  a.get(Y) << " " <<  b.get(X) << 
	" " << b.get(Y) << " " << c.get(X) << " " << c.get(Y) << " " << point.get(X) << " " << point.get(Y) << " " << std::endl;
}

static float ft_atof(const char *s)

{
	float value = 0.0f;
	float scale = 1.0f;
	bool after_dot = false;
	bool negative = false;

	if (*s == '-')
	{
		negative = true;
		++s;
	}
	while (*s)
	{
		if (*s == '.')
		{
			after_dot = true;
			++s;
			continue;
		}
        if (after_dot)
		{
			scale /= 10.0f;
			value += (*s - '0') * scale;
        }
		else 
            value = value * 10.0f + (*s - '0');
        ++s;
    }
    if (negative)
        return -value;
    return value;
}
