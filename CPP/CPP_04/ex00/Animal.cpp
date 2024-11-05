/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:19:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 12:48:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : m_type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const & type) : m_type(type)
{
	std::cout << "Animal of type " << type << " constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const & rhs)
{
	if (this != & rhs)
		this->m_type = rhs.m_type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "vocalise! 🐾" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->m_type);
}
