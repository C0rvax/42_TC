/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:27:34 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 19:50:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
{
}

Point::Point(const float n_x, const float n_y) : m_x(n_x), m_y(n_y)
{
}

Point::Point(Point const & src)
{
	*this = src;
}

Point	&Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed &>(m_x) = rhs.m_x;
		const_cast<Fixed &>(m_y) = rhs.m_y;
	}
	return *this;
}

Point::~Point(void)
{
}

Fixed	Point::getX(void) const
{
	return this->m_x;
}

Fixed	Point::getY(void) const
{
	return this->m_y;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	// vectorial product between vextor AP and vector AB
    Fixed cross2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	// vectorial product between vextor BP and vector BC
    Fixed cross3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	// vectorial product between vextor CP and vector CA

    return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
	// if the sign of all vectorial product are the same then the point is inside, else is outside
}
