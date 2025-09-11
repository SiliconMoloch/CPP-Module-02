/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:31:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/10 17:40:09 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#define AB 0
#define BC 1
#define CA 2
#define NEGATIVE 0
#define POSITIVE 1
#define X 0
#define Y 1

static Fixed get_sign(Point const point, \
	Point const vertex_one, Point const vertex_two);
static bool		point_is_in_triangle(Point const point, \
	Point const a, Point const b, Point const c);

bool	bsp(Point const a, Point const b, Point const c, Point const point)

{
	return (point_is_in_triangle(point, a, b, c));
}

static bool point_is_in_triangle(Point const point, 
                                Point const a, Point const b, Point const c)
{
    const Fixed side_ab = get_sign(point, a, b);
    const Fixed	side_bc = get_sign(point, b, c);
	const Fixed	side_ca = get_sign(point, c, a);

	if (side_ab == 0 || side_bc == 0 || side_ca == 0)
		return (false);

	bool all_positive = (side_ab > 0) && (side_bc > 0) && (side_ca > 0);
	bool all_negative = (side_ab < 0) && (side_bc < 0) && (side_ca < 0);

	return (all_positive || all_negative);
}
static Fixed get_sign(Point const point, \
	Point const vertex_one, Point const vertex_two)

{
	return (point.get(X) - vertex_two.get(X)) * (vertex_one.get(Y) - vertex_two.get(Y)) - (vertex_one.get(X) - vertex_two.get(X)) * (point.get(Y) - vertex_two.get(Y));
}
