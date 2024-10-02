/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:31:57 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/02 16:27:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon()
{}

std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string t_type)
{
	type = t_type;
}
