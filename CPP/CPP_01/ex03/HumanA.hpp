/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:24:28 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/03 13:28:21 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string t_name, Weapon& t_weapon);
		~HumanA();
		void	attack();
	private:
		std::string name;
		Weapon&	weapon;
};

#endif
