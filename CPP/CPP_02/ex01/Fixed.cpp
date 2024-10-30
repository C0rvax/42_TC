/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 15:35:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

const int	Fixed::m_fractBits = 8;

Fixed::Fixed(void) : m_fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : m_fixPointValue(n << m_fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : m_fixPointValue(roundf(f * (1 << m_fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &rhs)
		this->m_fixPointValue = rhs.getRawBits();

	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return this->m_fixPointValue;
}

void	Fixed::setRawBits(int const n)
{
	this->m_fixPointValue = n;
}

float	Fixed::toFloat(void) const
{
	return ((float)m_fixPointValue / (1 << m_fractBits));
}

int		Fixed::toInt(void) const
{
	return (m_fixPointValue >> m_fractBits);
}

std::ostream&	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
