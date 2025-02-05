/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:23:42 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 18:39:08 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form	() : m_name(""), m_signed(false), m_signGrade(Bureaucrat::minGrade), m_executeGrade(Bureaucrat::minGrade) {}

Form::Form	(const std::string& name, const int&  signGrade, const int& executeGrade) : m_name(name), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	this->m_signed = false;
	if (signGrade < Bureaucrat::maxGrade || executeGrade < Bureaucrat::maxGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::minGrade || executeGrade > Bureaucrat::minGrade)
		throw Form::GradeTooLowException();
}

Form::Form	(const Form& src) : m_name(src.getName()), m_signed(src.getSigned()), m_signGrade(src.getSignGrade()), m_executeGrade(src.getExecuteGrade()) {}

Form::~Form	() {}

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		this->m_signed = rhs.getSigned();
	return *this;
}

const std::string&	Form::getName() const {	return this->m_name; }

const bool&	Form::getSigned() const { return this->m_signed; }

const int&	Form::getSignGrade() const { return this->m_signGrade; }

const int&	Form::getExecuteGrade() const {	return this->m_executeGrade; }

void	Form::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->m_signGrade)
		throw Form::GradeTooLowException();
	else
		this->m_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form's grade too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form's grade too low.");
}

std::ostream&	operator<<(std::ostream& o, const Form& rhs)
{
	o << YELLOWB << rhs.getName() << RESET << (rhs.getSigned() ? GREEN : RED);
	o << "[" << (rhs.getSigned() ? "SIGNED]" : "UNSIGNED]") << YELLOW;
	o << " form, grade to sign " << rhs.getSignGrade();
	o << ", grade to execute " << rhs.getExecuteGrade() << "." << RESET;
	return o;
}
