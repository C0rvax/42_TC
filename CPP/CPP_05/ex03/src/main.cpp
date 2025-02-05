/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 19:53:04 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Intern.hpp"

int	main()
{
	Intern		intern;

	AForm*		shrub = intern.makeForm("shrubbery creation", "ascii");
	AForm*		robo = intern.makeForm("robotomy request", "bob");
	AForm*		pres = intern.makeForm("presidential pardon", "bob");
	if (!shrub || !robo || !pres)
		return 1;
	try
	{
		std::cout << "Try to create a wrong form:" << std::endl;
		AForm*		wrongForm = intern.makeForm("shrubbery creat", "ascii");
		(void)wrongForm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	try
	{
		Bureaucrat	boss("xavier", 1);
		Bureaucrat	promoted("rich", 46);

		std::cout << std::endl;
		std::cout << promoted << ": sign forms:" << std::endl;
		promoted.signForm(*shrub);
		promoted.signForm(*robo);
		promoted.signForm(*pres);

		std::cout << std::endl;
		std::cout << "Display forms status:" << std::endl;
		std::cout << *shrub << std::endl;
		std::cout << *robo << std::endl;
		std::cout << *pres << std::endl;

		std::cout << std::endl;
		std::cout << promoted << ": execute forms:" << std::endl;
		promoted.executeForm(*shrub);
		promoted.executeForm(*robo);
		promoted.executeForm(*pres);

		std::cout << std::endl;
		std::cout << "promotion of " << promoted++ << " and execute robo:"<<std::endl;
		promoted.executeForm(*robo);
		
		std::cout << std::endl;
		std::cout << "Display forms status:" << std::endl;
		std::cout << *shrub << std::endl;
		std::cout << *robo << std::endl;
		std::cout << *pres << std::endl;

		std::cout << std::endl;
		std::cout << boss << ": sign and execute pres:" << std::endl;
		boss.signForm(*pres);
		boss.executeForm(*pres);

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;	
	}
	delete shrub;
	delete robo;
	delete pres;
	return 0;
}
