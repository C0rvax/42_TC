/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:08:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 13:17:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__
#include <string>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

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

		void	printTrap(void);
	protected:
		std::string		m_name;
		unsigned int	m_hitPoint;
		unsigned int	m_energyPoint;
		unsigned int	m_attackDamage;
};

#endif  /* __CLAPTRAP_HPP__ */
