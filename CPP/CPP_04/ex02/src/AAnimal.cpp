/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:19:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 11:01:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : m_type("")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string const & type) : m_type(type)
{
	std::cout << "AAnimal of type " << type << " constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	*this = src;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const & rhs)
{
	if (this != & rhs)
		this->m_type = rhs.m_type;
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "vocalise! 🐾" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->m_type);
}
