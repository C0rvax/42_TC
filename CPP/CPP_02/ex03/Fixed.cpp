/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 12:16:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

const int	Fixed::m_fractBits = 8;

Fixed::Fixed(void) : m_fixPointValue(0)
{
}

Fixed::Fixed(const int n) : m_fixPointValue(n << m_fractBits)
{
}

Fixed::Fixed(const float f) : m_fixPointValue(roundf(f * (1 << m_fractBits)))
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->m_fixPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
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
	return ((float)this->m_fixPointValue / (1 << m_fractBits));
}

int		Fixed::toInt(void) const
{
	int	i = this->m_fixPointValue >> m_fractBits;
	return i;
}

std::ostream&	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

// COMPARISON OPERATOR //

bool	Fixed::operator>(const Fixed & rhs) const
{
	return this->m_fixPointValue > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed & rhs) const
{
	return this->m_fixPointValue < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed & rhs) const
{
	return this->m_fixPointValue >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed & rhs) const
{
	return this->m_fixPointValue <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed & rhs) const
{
	return this->m_fixPointValue == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed & rhs) const
{
	return this->m_fixPointValue != rhs.getRawBits();
}

// ARITHMETIC OPERATOR //

Fixed	Fixed::operator+(const Fixed & rhs) const
{
	return this->toFloat() + rhs.toFloat();
}

Fixed	Fixed::operator-(const Fixed & rhs) const
{
	return this->toFloat() - rhs.toFloat();
}

Fixed	Fixed::operator*(const Fixed & rhs) const
{
	return this->toFloat() * rhs.toFloat();
}

Fixed	Fixed::operator/(const Fixed & rhs) const
{
	return this->toFloat() / rhs.toFloat();
}
// if returning a float like this the float constructor will be called implicitly

// INCREMENT DECREMENT OPERATOR //

Fixed	&Fixed::operator++(void)
{
	++this->m_fixPointValue;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->m_fixPointValue++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	--this->m_fixPointValue;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->m_fixPointValue--;
	return tmp;
}

// MAX MIN //

Fixed	&Fixed::min(Fixed & a, Fixed & b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed	&Fixed::min(const Fixed & a, const Fixed & b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed	&Fixed::max(Fixed & a, Fixed & b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed	&Fixed::max(const Fixed & a, const Fixed & b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}
