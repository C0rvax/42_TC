/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:31:36 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 23:33:45 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		FragTrap &operator=(FragTrap const & rhs);
		~FragTrap(void);
		
		void	highFivesGuys(void);
};

#endif  /* __FRAGTRAP_HPP__ */
