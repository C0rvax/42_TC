/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:27 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class	Fixed
{
	public:
		Fixed	(void);
		Fixed	(Fixed const & src);
		Fixed	(const int n);
		Fixed	(const float f);
		Fixed&	operator=(Fixed const & rhs);
		~Fixed	();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed & rhs) const;
		bool	operator<(const Fixed & rhs) const;
		bool	operator>=(const Fixed & rhs) const;
		bool	operator<=(const Fixed & rhs) const;
		bool	operator==(const Fixed & rhs) const;
		bool	operator!=(const Fixed & rhs) const;
		Fixed	operator+(const Fixed & rhs) const;
		Fixed	operator-(const Fixed & rhs) const;
		Fixed	operator*(const Fixed & rhs) const;
		Fixed	operator/(const Fixed & rhs) const;
		Fixed&	operator++(void);
		Fixed	operator++(int n);
		Fixed&	operator--(void);
		Fixed	operator--(int n);
		
		static Fixed&		min(Fixed & a, Fixed & b);
		static Fixed&		max(Fixed & a, Fixed & b);
		static Fixed const&	min(Fixed const & a, Fixed const & b);
		static Fixed const&	max(Fixed const & a, Fixed const & b);
		
	private:
		static const int	m_fractBits;
		int					m_fixPointValue;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &rhs);

#endif /* __FIXED_HPP__ */
