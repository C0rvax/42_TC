/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:08:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 22:47:50 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__
#include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string n_name);
		ClapTrap(ClapTrap const & src);
		ClapTrap &operator=(ClapTrap const & rhs);
		~ClapTrap(void);

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	protected:
		std::string	m_name;
		int			m_hitPoint;
		int			m_energyPoint;
		int			m_attackDamage;
};

#endif  /* __CLAPTRAP_HPP__ */
