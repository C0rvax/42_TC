/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:24:28 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 10:20:46 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA	(std::string t_name, Weapon& t_weapon);
		~HumanA	(void);
		void	attack(void);
	private:
		std::string name;
		Weapon&		m_weapon;
};

#endif
