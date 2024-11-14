/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:52:35 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 12:54:49 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat	(void);
		Bureaucrat	(std::string name, int grade);
		Bureaucrat	(Bureaucrat const & src);
		Bureaucrat&	operator=(Bureaucrat const & rhs);
		~Bureaucrat	(void);

		std::string const	getName(void) const;
		int					getGrade(void) const;
		Bureaucrat&			operator++(void);
		Bureaucrat			operator++(int);
		Bureaucrat&			operator--(void);
		Bureaucrat			operator--(int);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

		void	signAForm(AForm & f);
		void	executeForm(AForm const & form);

		static const int	maxGrade = 1;
		static const int	minGrade = 150;

	private:
		std::string const	m_name;
		int					m_grade;
};

std::ostream&	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif  /* __BUREAUCRAT_HPP__ */
