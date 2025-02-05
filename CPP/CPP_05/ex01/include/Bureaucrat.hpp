/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:52:35 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 18:47:19 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
# define CYAN "\033[1;36m"

#include <string>

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat&	operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string&	getName() const;
		const int&			getGrade() const;
		Bureaucrat&			operator++();
		Bureaucrat			operator++(int);
		Bureaucrat&			operator--();
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

		void	signForm(Form& f);

		static const int	maxGrade = 1;
		static const int	minGrade = 150;
	private:
		const std::string	m_name;
		int					m_grade;
};

std::ostream&	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif  /* __BUREAUCRAT_HPP__ */
