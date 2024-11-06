/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:32:12 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 14:38:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & rhs);
		~ScavTrap(void);
		
		void	attack(std::string const & target);
		void	guardGate() const;
	protected:
		static const unsigned int	m_scavHP = 100;
		static const unsigned int	m_scavEP = 50;
		static const unsigned int	m_scavAD = 20;
};

#endif  /* __SCAVTRAP_HPP__ */
