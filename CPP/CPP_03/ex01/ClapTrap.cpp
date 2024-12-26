/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:17:17 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 11:07:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : m_hitPoint(10), m_energyPoint(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n_name) : m_name(n_name), m_hitPoint(10), m_energyPoint(10), m_attackDamage(0)
{
	std::cout << "ClapTrap " << this->m_name << ": Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap Copy assignment constructor called" << std::endl;
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_hitPoint = rhs.m_hitPoint;
		this->m_energyPoint = rhs.m_energyPoint;
		this->m_attackDamage = rhs.m_attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->m_name << ": Deconstructor called" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	if (this->m_hitPoint > 0 && this->m_energyPoint > 0)
	{
		std::cout << RED << "ClapTrap " << this->m_name << " attacks " << target;
		std::cout << ", causing " << this->m_attackDamage;
		std::cout << " points of damage!" << RESET << std::endl;
		this->m_energyPoint--;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->m_name;
		std::cout << " cannot attack, because he ";
		if (this->m_hitPoint == 0)
			std::cout << "is dead!" << RESET << std::endl;
		else
			std::cout << "has no energy points!" << RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoint > 0 && this->m_energyPoint > 0)
	{
		if (amount <= this->m_hitPoint)
			this->m_hitPoint -= amount;
		else
			this->m_hitPoint = 0;
		std::cout << RED << "ClapTrap " << this->m_name << " take ";
		std::cout << amount;
		std::cout << " points of damage!" << " New hit points: " << this->m_hitPoint << RESET << std::endl;
		this->m_energyPoint--;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->m_name;
		std::cout << " cannot take damage, because he ";
		if (this->m_hitPoint == 0)
			std::cout << "is dead!" << RESET << std::endl;
		else
			std::cout << "has no energy points!" << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoint > 0 && this->m_energyPoint > 0)
	{
		this->m_hitPoint += amount;
		std::cout << GREEN << "ClapTrap " << this->m_name << " is repaired by ";
		std::cout << amount << " hit points!";
		std::cout << " New hit points: " << this->m_hitPoint << RESET << std::endl;
		this->m_energyPoint--;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->m_name;
		std::cout << " cannot be repaired, because he ";
		if (this->m_hitPoint == 0)
			std::cout << "is dead!" << RESET << std::endl;
		else
			std::cout << "has no energy points!" << RESET << std::endl;
	}
}

void	ClapTrap::printTrap(void)
{
	std::cout << BLUE << "Name: " << this->m_name << std::endl;
	std::cout << "Hit points: " << this->m_hitPoint << std::endl;
	std::cout << "Energy points: " << this->m_energyPoint << std::endl;
	std::cout << "Attack damages: " << this->m_attackDamage << RESET << std::endl;
}
