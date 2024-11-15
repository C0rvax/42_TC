/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:13:22 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:33:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon",
	   PresidentialPardonForm::signGrade,
	   PresidentialPardonForm::executeGrade)
{
	this->m_target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("Presidential Pardon",
	   PresidentialPardonForm::signGrade,
	   PresidentialPardonForm::executeGrade)
{
	this->m_target = target;
}

PresidentialPardonForm::PresidentialPardonForm	(PresidentialPardonForm const & src) :
	AForm(src)
{
	this->m_target = src.m_target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm	(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::UnsignedException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
