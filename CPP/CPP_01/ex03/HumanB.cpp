/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:22:55 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 10:42:36 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string t_name) : name(t_name), m_weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void	HumanB::attack(void)
{
	if (!m_weapon)
		std::cout << name << " attacks with their bare fists" << std::endl;
	else
		std::cout << name << " attacks with their " << m_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& t_weapon)
{
	m_weapon = &t_weapon;
}
