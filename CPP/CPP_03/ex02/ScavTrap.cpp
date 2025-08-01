/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:38:12 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 13:28:46 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->m_name <<  ": Constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "ScavTrap " << this->m_name << ": Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_hitPoint = rhs.m_hitPoint;
		this->m_energyPoint = rhs.m_energyPoint;
		this->m_attackDamage = rhs.m_attackDamage;
	}
	std::cout << "ScavTrap " << this->m_name << ": Copy assignment constructor called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->m_name << ": Destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->m_hitPoint == 0)
		std::cout << YELLOW << "ScavTrap " << this->m_name << ": cannot attack because he's dead" << RESET << std::endl;
	else if (this->m_energyPoint == 0)
		std::cout << YELLOW << "ScavTrap " << this->m_name << ": cannot attack because he's tired" << RESET << std::endl;
	else
	{
		std::cout << RED << "ScavTrap " << this->m_name << " attacks " << target;
		std::cout << ", causing " << this->m_attackDamage;
		std::cout << " points of damage!" << RESET << std::endl;
		this->m_energyPoint--;
	}
}

void	ScavTrap::guardGate(void) const
{
	if (this->m_hitPoint == 0)
		std::cout << YELLOW << "ScavTrap " << this->m_name << ": cannot keep gate because he's dead" << RESET << std::endl;
	else if (this->m_energyPoint == 0)
		std::cout << YELLOW << "ScavTrap " << this->m_name << ": cannot keep gate because he's tired" << RESET << std::endl;
	else
		std::cout << BLUE << "ScavTrap " << this->m_name << ": Is now in Gate keeper mode!" << RESET << std::endl;
}
