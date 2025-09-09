#include "Point.hpp"
#include <iostream>

#define X 0
#define Y 1

Point::Point(void) : _x(0), _y(0) {}
Point::Point(float const x, float const y) : _x(x), _y(y) {}
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {} 
Point&	Point::operator=(Point const &copy) { (void)copy; return (*this); }
Point::~Point(void) { }

Fixed	Point::get(int coords) const { if (coords ^ 0) return (_y); return (_x); }
