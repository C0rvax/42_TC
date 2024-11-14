/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:23:42 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/13 15:45:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <ostream>

AForm::AForm	(void) : m_name(""), m_signGrade(Bureaucrat::m_minGrade), m_executeGrade(Bureaucrat::m_minGrade)
{
	this->m_signed = false;
}

AForm::AForm	(std::string const name, int const signGrade, int const executeGrade) : m_name(name), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	this->m_signed = false;
	if (signGrade < Bureaucrat::m_maxGrade || executeGrade < Bureaucrat::m_maxGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::m_minGrade || executeGrade > Bureaucrat::m_minGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm	(AForm const & src) : m_name(src.getName()), m_signGrade(src.getSignGrade()), m_executeGrade(src.getExecuteGrade())
{
	this->m_signed = src.getSigned();
}

AForm&	AForm::operator=(AForm const & rhs)
{
	this->m_signed = rhs.getSigned();
	return *this;
}

AForm::~AForm	(void)
{
}

std::string const	AForm::getName(void) const
{
	return this->m_name;
}

bool	AForm::getSigned(void) const
{
	return this->m_signed;
}

int	AForm::getSignGrade(void) const
{
	return this->m_signGrade;
}

int	AForm::getExecuteGrade(void) const
{
	return this->m_executeGrade;
}

void	AForm::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > this->m_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->m_signed = true;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm's grade too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm's grade too low.");
}

std::ostream&	operator<<(std::ostream & o, AForm const & rhs)
{
	o << rhs.getName() << "(" << (rhs.getSigned() ? "signed" : "unsigned");
	o << ") form, grade to sign " << rhs.getSignGrade();
	o << ", grade to execute " << rhs.getExecuteGrade() << ".";
	return o;
}
