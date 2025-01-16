/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:37:06 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:24:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria	(void)
{
	this->m_type = "";
}

AMateria::AMateria	(std::string const & type)
{
	this->m_type = type;
}

AMateria::AMateria	(AMateria const & src)
{
	*this = src;
}

AMateria&	AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		m_type = rhs.getType();
	return *this;
}

AMateria::~AMateria	(void)
{
}

std::string const &	AMateria::getType(void) const
{
	return this->m_type;
}

void	AMateria::use(ICharacter & target)
{
	std::cout << "Materia of type " << this->getType();
	std::cout << " used on " << target.getName() << std::endl;
}
