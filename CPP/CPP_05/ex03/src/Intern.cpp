/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:27:16 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:42:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& src) { *this = src; }

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;	
	return *this;
}

Intern::~Intern() {}

static AForm*	createShrubbery(const std::string & target) { return new ShrubberyCreationForm(target); }

static AForm*	createRobotomy(const std::string & target) { return new RobotomyRequestForm(target); }

static AForm*	createPresidential(const std::string & target) { return new PresidentialPardonForm(target); }

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(*functions[])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return functions[i](target);
		}
	}
	std::cout << "Intern cannot create: " << name << ", form do not exist"<< std::endl;
	return NULL;
}
