/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:35:10 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 12:53:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 100;
	this->m_attackDamage = 30;
}

FragTrap::FragTrap(std::string const & name)
{
	std::cout << "FragTrap " << this->m_name <<  ": Constructor called" << std::endl;
	this->m_hitPoint = 100;
	this->m_energyPoint = 100;
	this->m_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	std::cout << "FragTrap " << this->m_name << ": Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const & value)
{
	if (this != &value)
		ClapTrap::operator=(value);
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
