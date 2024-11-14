/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:02:44 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 13:10:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;

		static int const	signGrade = 145;
		static int const	executeGrade = 137;

	private:
		std::string	m_target;
};
#endif  /* __SHRUBBERYCREATIONFORM_HPP__ */
