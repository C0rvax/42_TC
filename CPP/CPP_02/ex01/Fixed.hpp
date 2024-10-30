/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 15:17:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(const int n);
		Fixed(const float f);
		Fixed &operator=(Fixed const & rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		static const int	m_fractBits;
		int					m_fixPointValue;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &rhs);

#endif /* __FIXED_HPP__ */
