/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:27:34 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/23 11:37:23 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
}

Point::Point	(const float n_x, const float n_y) : m_x(Fixed(n_x)), m_y(Fixed(n_y))
{
}

Point::Point	(Point const & src) : m_x(src.getX()), m_y(src.getY())
{
}

Point	&Point::operator=(Point const & rhs)
{
	(void)rhs;
	return *this;
}

Point::~Point	(void)
{
}

Fixed const &	Point::getX(void) const
{
	return this->m_x;
}

Fixed const &	Point::getY(void) const
{
	return this->m_y;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	// scalar value of a 2d cross product between vextor AP and vector AB -- if < 0 Point is on the right of AB
    Fixed cross2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed cross3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

    return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
	// if the sign of all vectorial product are the same then the point is inside, else is outside
}
