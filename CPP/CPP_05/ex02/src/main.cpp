/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:28:27 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{

	try
	{
		Bureaucrat	boss("BOSS", 1);
		Bureaucrat	slave("SLAVE", 150);
		Bureaucrat	promoted("PROMOTED", 46);

		ShrubberyCreationForm	shrub("ascii");
		RobotomyRequestForm		robo("bob");
		PresidentialPardonForm	pres("bob");

		std::cout << slave << " try to sign:" << std::endl;
		slave.signForm(shrub);	
		slave.signForm(robo);	
		slave.signForm(pres);	

		std::cout << std::endl;
		std::cout << promoted << " try to execute:" << std::endl;
		promoted.executeForm(shrub);
		promoted.executeForm(robo);
		promoted.executeForm(pres);

		std::cout << std::endl;
		std::cout << promoted << " try to sign:" << std::endl;
		promoted.signForm(shrub);
		promoted.signForm(robo);
		promoted.signForm(pres);

		std::cout << std::endl;
		std::cout << "Forms status:" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pres << std::endl;

		std::cout << std::endl;
		std::cout << promoted << " try to execute:" << std::endl;
		promoted.executeForm(shrub);
		promoted.executeForm(robo);
		promoted.executeForm(pres);

		std::cout << std::endl;
		std::cout << "promotion of " << promoted++ <<std::endl;
		promoted.executeForm(robo);

		std::cout << std::endl;
		std::cout << "Forms status:" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pres << std::endl;

		std::cout << std::endl;
		std::cout << boss << " try to execute-sign-execute:" << std::endl;
		boss.executeForm(pres);
		boss.signForm(pres);
		boss.executeForm(pres);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
