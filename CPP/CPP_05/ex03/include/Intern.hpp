/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:41 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 20:22:48 by aduvilla         ###   ########.fr       */
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

		AForm*	makeForm(std::string name, std::string target);
//		AForm*	createShrubbery(std::string target);
//		AForm*	createRobotomy(std::string target);
//		AForm*	createPresidential(std::string target);
};

#endif  /* __INTERN_HPP__ */
