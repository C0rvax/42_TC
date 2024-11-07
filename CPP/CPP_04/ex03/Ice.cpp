/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:01:09 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:05:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

ice::ice	(void) : AMateria("ice")
{
}

ice::ice	(ice const & src) : AMateria("ice")
{
	*this = src;
}

ice&	ice::operator=(ice const & rhs)
{
	if (this != &rhs)
		this->m_type = rhs.getType();
	return *this;
}

ice::~ice	(void)
{
}

AMateria*	ice::clone(void) const
{
	AMateria*	clone = new(std::nothrow) ice();
	return clone;
}

void	ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bot at " << target.getName() << std::endl;
}
