/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:35:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:12:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	m_brain = new Brain;
}

Cat::Cat(Cat const & src) : AAnimal("Cat")
{
	this->m_brain = NULL;
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this != & rhs)
	{
		this->m_type = rhs.m_type;
		if (this->m_brain)
			delete this->m_brain;
		this->m_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW 🐱" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return this->m_brain;
}
