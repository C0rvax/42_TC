/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:34:02 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/12 15:01:18 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure	(void) : AMateria("cure")
{
}

Cure::Cure	(Cure const & src) : AMateria("cure")
{
	*this = src;
}

Cure&	Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
		this->m_type = rhs.getType();
	return *this;
}

Cure::~Cure	(void)
{
}

AMateria*	Cure::clone(void) const
{
	AMateria*	clone = new(std::nothrow) Cure();
	return clone;
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
