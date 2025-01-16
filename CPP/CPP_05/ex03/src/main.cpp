/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 13:39:31 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Intern.hpp"

int	main()
{
	Intern		intern;
	Bureaucrat	boss("xavier", 1);
	Bureaucrat	slave("bob", 150);
	Bureaucrat	promoted("rich", 46);

	AForm*		shrub = intern.makeForm("shrubbery creation", "ascii");
	AForm*		robo = intern.makeForm("robotomy request", "bob");
	AForm*		pres = intern.makeForm("presidential pardon", "bob");
/*
	try
	{
		AForm*		wrongForm = intern.makeForm("none", "ascii");
		(void)wrongForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	try
	{
		AForm*		wrongForm = intern.makeForm("shrubbery creat", "ascii");
		(void)wrongForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
*/
	slave.signForm(*shrub);	
	slave.signForm(*robo);	
	slave.signForm(*pres);	
	promoted.executeForm(*shrub);
	promoted.executeForm(*robo);
	promoted.executeForm(*pres);
	promoted.signForm(*shrub);
	promoted.signForm(*robo);
	promoted.signForm(*pres);
	promoted.executeForm(*shrub);
	promoted.executeForm(*robo);
	promoted.executeForm(*pres);
	std::cout << "promotion of " << promoted++ <<std::endl;
	promoted.executeForm(*robo);
	std::cout << std::endl;
	std::cout << *shrub << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pres << std::endl;
	boss.executeForm(*pres);
	boss.signForm(*pres);
	boss.executeForm(*pres);

	delete shrub;
	delete robo;
	delete pres;
	return 0;
}
