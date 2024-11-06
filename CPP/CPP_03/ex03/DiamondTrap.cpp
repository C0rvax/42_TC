/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:29:32 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 14:34:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), m_name("")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->m_hitPoint = FragTrap::m_fragHP;
	this->m_energyPoint = ScavTrap::m_scavEP;
	this->m_attackDamage = FragTrap::m_fragAD;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), m_name(name)
{
	std::cout << "DiamondTrap " << this->m_name <<  ": Constructor called" << std::endl;
	this->m_hitPoint = FragTrap::m_fragHP;
	this->m_energyPoint = ScavTrap::m_scavEP;
	this->m_attackDamage = FragTrap::m_fragAD;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = src;
	std::cout << "DiamondTrap " << this->m_name << ": Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_hitPoint = rhs.m_hitPoint;
		this->m_energyPoint = rhs.m_energyPoint;
		this->m_attackDamage = rhs.m_attackDamage;
	}
	std::cout << "DiamondTrap " << this->m_name << ": Copy assignment constructor called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->m_name << ": Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->m_name << "\nClapTrap name: " << ClapTrap::m_name << std::endl;
}
