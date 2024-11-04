/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:35:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 14:56:02 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const & src) : Animal("Cat")
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const & rhs)
{
	if (this != & rhs)
		this->m_type = rhs.m_type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW 🐱" << std::endl;
}
