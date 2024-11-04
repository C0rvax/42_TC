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

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	m_brain = new Brain;
}

Dog::Dog(Dog const & src) : Animal("Dog")
{
//	this->m_brain = NULL;
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const & rhs)
{
	if (this != & rhs)
	{
		this->m_type = rhs.m_type;
		if (this->m_brain != NULL)
			delete this->m_brain;
		this->m_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF 🐶" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return this->m_brain;
}
