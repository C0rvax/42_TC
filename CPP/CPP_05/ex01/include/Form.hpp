/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:53:45 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 18:40:02 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[33m"
# define YELLOWB "\033[1;4;33m"
# define RESET "\033[0m"

# include <string>

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string& name, const int& signGrade, const int& executeGrade);
		Form(const Form& src);
		Form&	operator=(const Form& rhs);
		~Form();

		const std::string& 	getName() const;
		const bool&			getSigned() const;
		const int& 			getSignGrade() const;
		const int&			getExecuteGrade() const;
		void				beSigned(const Bureaucrat & b);
		
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
		const std::string	m_name;
		bool				m_signed;
		int	const			m_signGrade;
		int const			m_executeGrade;
		
};

std::ostream&	operator<<(std::ostream & o, Form const & rhs);

#endif  /* __FORM_HPP__ */
