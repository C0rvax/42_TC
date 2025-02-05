/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:23:42 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:26:40 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

AForm::AForm	(void) : m_name(""), m_signGrade(Bureaucrat::minGrade), m_executeGrade(Bureaucrat::minGrade)
{
	this->m_signed = false;
}

AForm::AForm	(const std::string& name, const int signGrade, const int executeGrade) : m_name(name), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	this->m_signed = false;
	if (signGrade < Bureaucrat::maxGrade || executeGrade < Bureaucrat::maxGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::minGrade || executeGrade > Bureaucrat::minGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm	(const AForm& src) : m_name(src.getName()), m_signGrade(src.getSignGrade()), m_executeGrade(src.getExecuteGrade())
{
	this->m_signed = src.getSigned();
}

AForm&	AForm::operator=(const AForm& rhs)
{
	this->m_signed = rhs.getSigned();
	return *this;
}

AForm::~AForm	(void)
{
}

const std::string&	AForm::getName(void) const { return this->m_name; }

const bool&	AForm::getSigned(void) const { return this->m_signed; }

const int&	AForm::getSignGrade(void) const { return this->m_signGrade; }

const int&	AForm::getExecuteGrade(void) const { return this->m_executeGrade; }

void	AForm::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > this->m_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->m_signed = true;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade too low.");
}

const char*	AForm::UnsignedException::what(void) const throw()
{
	return ("Unsigned Form.");
}

std::ostream&	operator<<(std::ostream & o, AForm const & rhs)
{
	o << YELLOWB << rhs.getName() << RESET << (rhs.getSigned() ? GREEN : RED);
	o << "[" << (rhs.getSigned() ? "SIGNED]" : "UNSIGNED]") << YELLOW;
	o << " form, grade to sign " << rhs.getSignGrade();
	o << ", grade to execute " << rhs.getExecuteGrade() << "." << RESET;
	return o;
}
