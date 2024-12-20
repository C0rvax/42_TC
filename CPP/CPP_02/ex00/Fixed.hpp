/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:01:36 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/20 12:18:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed &operator=(Fixed const & rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static const int	m_fractBits;
		int					m_fixPointValue;
};
#endif /* __FIXED_HPP__ */
