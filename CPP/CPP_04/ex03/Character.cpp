/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:17:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 14:33:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//static const int	m_inventoryMax = 4;

Character::Character	(void)
{
	this->m_name = "";
	for (size_t i = 0; i < this->m_inventoryMax; i++)
		this->m_inventory[i] = NULL;
}

Character::Character	(std::string const & name)
{
	this->m_name = name;
	for (size_t i = 0; i < this->m_inventoryMax; i++)
		this->m_inventory[i] = NULL;
}

Character::Character	(Character const & src)
{
	*this = src;
}

Character&	Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		return *this;
	this->m_name = rhs.getName();
	for (int i = 0; i < this->m_inventoryMax; i++)
	{
		if (this->m_inventory[i] == NULL)
			this->m_inventory[i] = rhs.m_inventory[i]->clone();
		else
		{
			delete this->m_inventory[i];
			this->m_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character	(void)
{
	for (int i = 0; i < this->m_inventoryMax; i++)
	{
		if (this->m_inventory[i] != NULL)
		{
			delete this->m_inventory[i];
			this->m_inventory[i] = NULL;
		}
	}
}

std::string const& Character::getName(void) const
{
	return this->m_name;
}

void	Character::equip(AMateria * m)
{
	for (int i = 0; i < this->m_inventoryMax; i++)
	{
		if (this->m_inventory[i] == NULL)
		{
			this->m_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > 0 && idx <= this->m_inventoryMax && this->m_inventory[idx] != NULL)
	{
		//stash this->m_inventory[idx];
		this->m_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx > 0 && idx <= this->m_inventoryMax && this->m_inventory[idx] != NULL)
		this->m_inventory[idx]->use(target);
}
