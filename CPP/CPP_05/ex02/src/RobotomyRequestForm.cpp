/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:18:18 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 14:00:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm	(void) :
	AForm("Robotomy Request",
	   RobotomyRequestForm::signGrade,
	   RobotomyRequestForm::executeGrade)
{
	this->m_target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("Robotomy Request",
	   RobotomyRequestForm::signGrade,
	   RobotomyRequestForm::executeGrade)
{
	this->m_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm(src)
{
	this->m_target = src.m_target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm	(void)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(0));
	if (!this->getSigned())
		throw AForm::UnsignedException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "ZZZzzzziiiiiiizzziouuuuuUU.... ZzzziiiiiiiizzZZZiiiiouuu" <<	std::endl;
	if (std::rand() % 2)
		std::cout << this->m_target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed on " << this->m_target << "." << std::endl;
}
