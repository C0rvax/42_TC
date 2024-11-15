/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:01:09 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:26:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice	(void) : AMateria("ice")
{
}

Ice::Ice	(Ice const & src) : AMateria("ice")
{
	*this = src;
}

Ice&	Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		this->m_type = rhs.getType();
	return *this;
}

Ice::~Ice	(void)
{
}

AMateria*	Ice::clone(void) const
{
	AMateria*	clone = new(std::nothrow) Ice();
	return clone;
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}
