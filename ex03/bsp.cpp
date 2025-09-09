#include "Point.hpp"
#define AB 0
#define BC 1
#define CA 2
#define NEGATIVE 0
#define POSITIVE 1
#define X 0
#define Y 1

static bool		point_is_in_triangle(Point const point, Point const a, Point const b, Point const c);
static Fixed	get_sign(Point const point, Point const vertex_one, Point const vertex_two);

bool	bsp( Point const point, Point const a, Point const b, Point const c)

{
	return (point_is_in_triangle(point, a, b, c));
}

static bool		point_is_in_triangle(Point const point, Point const a, Point const b, Point const c)

{
	Fixed	side[3];
	bool	sign[2];

	side[AB] = get_sign(point, a, b);
	side[BC] = get_sign(point, b, c);
	side[CA] = get_sign(point, c, a);

	sign[NEGATIVE] = (side[AB] < 0) || (side[BC] < 0) || (side[CA] < 0);
	sign[POSITIVE] = (side[AB] > 0) || (side[BC] > 0) || (side[CA] > 0);

	if (side[AB] == 0 || side[BC] == 0 || side[CA] == 0)
		return (false);
	return (!(sign[NEGATIVE] && sign[POSITIVE]));
}

static Fixed get_sign(Point const p1, Point const p2, Point const p3)

{
	return (p1.get(X) - p3.get(X)) * (p2.get(Y) - p3.get(Y)) - (p2.get(X) - p3.get(X)) * (p1.get(Y) - p3.get(Y));
}
