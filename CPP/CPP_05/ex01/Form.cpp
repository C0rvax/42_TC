/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:23:42 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:30:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form	(void) : m_name(""), m_signGrade(Bureaucrat::minGrade), m_executeGrade(Bureaucrat::minGrade)
{
	this->m_signed = false;
}

Form::Form	(std::string const name, int const signGrade, int const executeGrade) : m_name(name), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	this->m_signed = false;
	if (signGrade < Bureaucrat::maxGrade || executeGrade < Bureaucrat::maxGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::minGrade || executeGrade > Bureaucrat::minGrade)
		throw Form::GradeTooLowException();
}

Form::Form	(Form const & src) : m_name(src.getName()), m_signGrade(src.getSignGrade()), m_executeGrade(src.getExecuteGrade())
{
	this->m_signed = src.getSigned();
}

Form&	Form::operator=(Form const & rhs)
{
	this->m_signed = rhs.getSigned();
	return *this;
}

Form::~Form	(void)
{
}

std::string const	Form::getName(void) const
{
	return this->m_name;
}

bool	Form::getSigned(void) const
{
	return this->m_signed;
}

int	Form::getSignGrade(void) const
{
	return this->m_signGrade;
}

int	Form::getExecuteGrade(void) const
{
	return this->m_executeGrade;
}

void	Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > this->m_signGrade)
		throw Form::GradeTooLowException();
	else
		this->m_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade too high.");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade too low.");
}

std::ostream&	operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << "(" << (rhs.getSigned() ? "signed" : "unsigned");
	o << ") form, grade to sign " << rhs.getSignGrade();
	o << ", grade to execute " << rhs.getExecuteGrade() << ".";
	return o;
}
