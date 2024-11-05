/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 17:59:48 by aduvilla         ###   ########.fr       */
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
	return this->m_fixPointValue >> m_fractBits;
}

std::ostream&	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

// COMPARISON OPERATOR //


bool	Fixed::operator>(const Fixed & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

/*
bool	Fixed::operator>(const Fixed & rhs) const
{
	bool	res = this->getRawBits() > rhs.getRawBits();
	return res;
}

bool	Fixed::operator>(const Fixed & rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

*/
bool	Fixed::operator<(const Fixed & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

// ARITHMETIC OPERATOR //

Fixed	Fixed::operator+(const Fixed & rhs) const
{
	return this->toFloat() + rhs.toFloat();
}

Fixed	Fixed::operator-(const Fixed & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}
/*
Fixed	Fixed::operator/(const Fixed & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}
*/
// if returning a float like this the float constructor will be called implicitly

// INCREMENT DECREMENT OPERATOR //

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() + 1);
//	this->m_fixPointValue++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
//	this->m_fixPointValue--;
	return tmp;
}

// MAX MIN //

Fixed	&Fixed::min(Fixed & a, Fixed & b)
{
	// return (a.getRawBits() < b.getRawBits() ? a : b);
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
