/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:27:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 13:50:34 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern	(void)
{
}

Intern::Intern	(Intern const & src)
{
	*this = src;
}

Intern&	Intern::operator=(Intern const & rhs)
{
	(void)rhs;	
	return *this;
}

Intern::~Intern	(void)
{
}
static AForm*	createShrubbery(std::string & target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	createRobotomy(std::string & target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	createPresidential(std::string & target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(*functions[])(std::string &) = {&createShrubbery, &createRobotomy, &createPresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return functions[i](target);
		}
	}
	std::cout << "Intern cannot create " << name << std::endl;
	return NULL;
}
