/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:31:12 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/03 13:30:40 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string t_name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon& t_weapon);
	private:
		std::string name;
		Weapon*	weapon;
};

#endif
