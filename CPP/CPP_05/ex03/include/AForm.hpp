/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:53:45 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:26:02 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[33m"
# define YELLOWB "\033[1;4;33m"
# define RESET "\033[0m"

#include <string>

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(const std::string&  name, const int signGrade, const int executeGrade);
		AForm(const AForm& src);
		AForm&	operator=(const AForm& rhs);
		virtual ~AForm();

		const std::string&	getName(void) const;
		const bool&			getSigned(void) const;
		const int& 			getSignGrade(void) const;
		const int&			getExecuteGrade(void) const;
		void				beSigned(Bureaucrat & b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
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

		class	UnsignedException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		const std::string	m_name;
		bool				m_signed;
		const int			m_signGrade;
		const int			m_executeGrade;
		
};

std::ostream&	operator<<(std::ostream & o, const AForm& rhs);

#endif  /* __AFORM_HPP__ */
