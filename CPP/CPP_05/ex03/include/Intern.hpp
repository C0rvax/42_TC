/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:41 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:41:22 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern &operator=(Intern const & rhs);
		~Intern(void);

		AForm*	makeForm(const std::string& name, const std::string& target);
//		AForm*	createShrubbery(std::string target);
//		AForm*	createRobotomy(std::string target);
//		AForm*	createPresidential(std::string target);
};

#endif  /* __INTERN_HPP__ */
