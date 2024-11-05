/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:20:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 16:54:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class	Point
{
	public:
		Point	(void);
		Point	(const float n_x, const float n_y);
		Point	(Point const & src);
		Point	&operator=(Point const & rhs);
		~Point	();

		Fixed const &	getX(void) const;
		Fixed const &	getY(void) const;

	private:
		Fixed const	m_x;
		Fixed const	m_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif  /* __POINT_HPP__ */
