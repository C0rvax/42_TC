/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:42 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 16:49:18 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource	(void)
{
	for (int i = 0; i < this->m_recipesMax; i++)
		this->m_recipes[i] = NULL;
}

MateriaSource::MateriaSource	(MateriaSource const & src)
{
	for (int i = 0; i < this->m_recipesMax; i++)
		this->m_recipes[i] = NULL;
	*this = src;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < this->m_recipesMax; i++)
	{
		if (this->m_recipes[i] == NULL)
			this->m_recipes[i] = rhs.m_recipes[i]->clone();
		else
		{
			delete this->m_recipes[i];
			this->m_recipes[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource	(void)
{
	for (int i = 0; i < this->m_recipesMax; i++)
	{
		if (this->m_recipes[i] != NULL)
		{
			delete this->m_recipes[i];
			this->m_recipes[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < this->m_recipesMax; i++)
	{
		if (this->m_recipes[i] == NULL)
		{
			this->m_recipes[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->m_recipesMax; i++)
	{
		if (this->m_recipes[i] && this->m_recipes[i]->getType() == type)
			return this->m_recipes[i]->clone();
	}
	return NULL;
}
