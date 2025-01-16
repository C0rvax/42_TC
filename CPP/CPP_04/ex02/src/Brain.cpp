/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:06:39 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:42 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain copy assignment constructor called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string const & idea, int index)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 &&  index < 100)
		return this->ideas[index];
	return NULL;
}
