/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:53:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/13 14:33:51 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm	(void);
		AForm	(std::string const name, int signGrade, int executeGrade);
		AForm	(AForm const & src);
		AForm&	operator=(AForm const & rhs);
		~AForm	(void);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int 				getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		void				beSigned(Bureaucrat & b);
		
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

	private:
		std::string const	m_name;
		bool				m_signed;
		int	const			m_signGrade;
		int const			m_executeGrade;
		
};

std::ostream&	operator<<(std::ostream & o, AForm const & rhs);

#endif  /* __FORM_HPP__ */
