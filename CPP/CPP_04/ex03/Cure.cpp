/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:34:02 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:06:51 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

cure::cure	(void) : AMateria("cure")
{
}

cure::cure	(cure const & src) : AMateria("cure")
{
	*this = src;
}

cure&	cure::operator=(cure const & rhs)
{
	if (this != &rhs)
		this->m_type = rhs.getType();
	return *this;
}

cure::~cure	(void)
{
}

AMateria*	cure::clone(void) const
{
	AMateria*	clone = new(std::nothrow) cure();
	return clone;
}

void	cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
