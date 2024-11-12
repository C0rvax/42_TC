/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:02:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/12 16:56:58 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat	(void) : m_name("")
{
	this->m_grade = m_minGrade;
}

Bureaucrat::Bureaucrat	(std::string name, int grade) : m_name(name)
{
	if (grade < m_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > m_minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade = grade;
}

Bureaucrat::Bureaucrat	(Bureaucrat const & src) : m_name(src.getName())
{
	this->m_grade = src.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->m_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat	(void)
{
}

std::string	Bureaucrat::getName(void) const
{
	return (this->m_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->m_grade);
}

Bureaucrat& Bureaucrat::operator++(void)
{
	if (this->getGrade() - 1 < m_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade -= 1;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp(*this);
	if (this->getGrade() - 1 < m_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade -= 1;
	return tmp;
}

Bureaucrat& Bureaucrat::operator--(void)
{
	if (this->getGrade() + 1 > m_minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade += 1;
	return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp(*this);
	if (this->getGrade() + 1 > m_minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade += 1;
	return tmp;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Cannot increment: Bureaucrat have already the highest grade");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Cannot decrement: Bureaucrat have already the lowest grade");
}
