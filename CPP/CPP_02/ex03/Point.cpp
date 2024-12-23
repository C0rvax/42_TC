/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:27:34 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/23 11:38:57 by aduvilla         ###   ########.fr       */
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
