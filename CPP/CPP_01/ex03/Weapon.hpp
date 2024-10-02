/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:20:47 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/02 16:27:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string& getType();
		void setType(std::string t_type);
	private:
		std::string	type;
};

#endif
