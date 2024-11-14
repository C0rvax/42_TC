/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 18:14:52 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	boss("xavier", 1);
	Bureaucrat	slave("bob", 150);
	Bureaucrat	promoted("rich", 46);

	ShrubberyCreationForm	shrub("ascii");
	RobotomyRequestForm		robo("bob");
	PresidentialPardonForm	pres("bob");

	slave.signForm(shrub);	
	slave.signForm(robo);	
	slave.signForm(pres);	
	promoted.executeForm(shrub);
	promoted.executeForm(robo);
	promoted.executeForm(pres);
	promoted.signForm(shrub);
	promoted.signForm(robo);
	promoted.signForm(pres);
	promoted.executeForm(shrub);
	promoted.executeForm(robo);
	promoted.executeForm(pres);
	std::cout << "promotion of " << promoted++ <<std::endl;
	std::cout << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robo << std::endl;
	std::cout << pres << std::endl;
	promoted.executeForm(robo);
	boss.executeForm(pres);
	boss.signForm(pres);
	boss.executeForm(pres);
	return 0;
}
