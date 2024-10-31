/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:58:28 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 15:05:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & src) : Animal("Dog")
{
	if (this != &src)
		*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const & rhs)
{
	if (this != & rhs)
		this->m_type = rhs.m_type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF 🐶" << std::endl;
}
