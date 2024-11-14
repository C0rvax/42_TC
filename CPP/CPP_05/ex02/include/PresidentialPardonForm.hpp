/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 12:52:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class	PresidentialPardonForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const;

		static int const	signGrade = 25;
		static int const	executeGrade = 5;

	private:
		std::string	m_target;
};
#endif  /* __PRESIDENTIALPARDONFORM_HPP__ */
