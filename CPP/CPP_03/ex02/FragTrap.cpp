/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:35:10 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 13:35:33 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->m_name <<  ": Constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 50;
	this->m_attackDamage = 20;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "FragTrap " << this->m_name << ": Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_hitPoint = rhs.m_hitPoint;
		this->m_energyPoint = rhs.m_energyPoint;
		this->m_attackDamage = rhs.m_attackDamage;
	}
	std::cout << "FragTrap " << this->m_name << ": Copy constructor called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->m_name << ": Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->m_hitPoint == 0)
		std::cout << "FragTrap " << this->m_name << ": cannot highfive because he's dead ☠️" << std::endl;
	else if (this->m_energyPoint == 0)
		std::cout << "FragTrap " << this->m_name << ": cannot highfive because he's tired 😴" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->m_name << ": ✋" << std::endl;
		this->m_energyPoint--;
	}
}
