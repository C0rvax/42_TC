/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:02:19 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 18:33:13 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name(""), m_grade(minGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : m_name(name)
{
	this->m_grade = 150;
	if (grade < maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : m_name(src.getName()), m_grade(src.getGrade()) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->m_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const { return (this->m_name); }

const int&	Bureaucrat::getGrade() const { return (this->m_grade); }

Bureaucrat& Bureaucrat::operator++()
{
	if (this->getGrade() - 1 < maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade -= 1;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp(*this);
	if (this->getGrade() - 1 < maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade -= 1;
	return tmp;
}

Bureaucrat& Bureaucrat::operator--(void)
{
	if (this->getGrade() + 1 > minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade += 1;
	return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp(*this);
	if (this->getGrade() + 1 > minGrade)
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

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << CYAN << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET;
	return o;
}
void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << this->m_name << " couldn't sign " << f.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}
