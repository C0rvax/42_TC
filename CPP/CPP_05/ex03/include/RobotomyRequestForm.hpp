/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:09:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 13:57:58 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);

		void	execute(Bureaucrat const & executor) const;

		static int const	signGrade = 72;
		static int const	executeGrade = 45;

	private:
		std::string	m_target;
};

#endif  /* __ROBOTOMYREQUESTFORM_HPP__ */
