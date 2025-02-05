/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:52:35 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 17:23:47 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>

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

	private:
		std::string const	m_name;
		int					m_grade;
		static const int	m_maxGrade = 1;
		static const int	m_minGrade = 150;
};

std::ostream&	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif  /* __BUREAUCRAT_HPP__ */
