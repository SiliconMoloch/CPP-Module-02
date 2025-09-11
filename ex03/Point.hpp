/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:31:18 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/10 15:31:47 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class	Point

{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point &copy);
		Point& operator=(Point const &copy);
		~Point(void);
		void	print(void) const;
		Fixed	get(int coord) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
