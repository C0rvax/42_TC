/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:31:36 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 14:38:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		FragTrap &operator=(FragTrap const & rhs);
		~FragTrap(void);
		
		void	highFivesGuys(void);
	protected:
		static const unsigned int	m_fragHP = 100;
		static const unsigned int	m_fragEP = 100;
		static const unsigned int	m_fragAD = 30;
};

#endif  /* __FRAGTRAP_HPP__ */
