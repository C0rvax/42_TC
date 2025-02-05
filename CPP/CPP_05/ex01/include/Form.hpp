/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:53:45 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 13:31:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string& name, const int& signGrade, const int& executeGrade);
		Form(const Form& src);
		Form&	operator=(const Form& rhs);
		~Form();

		const std::string 	getName(void) const;
		const bool&			getSigned(void) const;
		const int& 			getSignGrade(void) const;
		const int&			getExecuteGrade(void) const;
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

std::ostream&	operator<<(std::ostream & o, Form const & rhs);

#endif  /* __FORM_HPP__ */
