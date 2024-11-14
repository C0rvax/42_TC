/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:02:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/13 15:36:46 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat	(void) : m_name("")
{
	this->m_grade = m_minGrade;
}

Bureaucrat::Bureaucrat	(std::string name, int grade) : m_name(name)
{
	this->m_grade = 150;
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

std::string	const	Bureaucrat::getName(void) const
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

std::ostream&	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}

void	Bureaucrat::signAForm(AForm & f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cout << this->m_name << " couldn't sign " << f.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}
