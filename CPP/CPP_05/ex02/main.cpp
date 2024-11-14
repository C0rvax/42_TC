/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/13 15:49:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int	main()
{
	try
	{
		AForm	cerfa0("cerfa0", 0, 1);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm	cerfa0("cerfa0", 1, 0);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm	japd("japd", 151, 140);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm	japd("japd", 140, 151);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	boss("xavier", 1);
	Bureaucrat	slave("bob", 150);
	AForm		cerfa80("cerfa80", 80, 80);
	AForm		cerfa1("cerfa1", 1, 1);
	AForm		cerfa150("cerfa150", 150, 150);

	std::cout << cerfa80 << std::endl;
	slave.signAForm(cerfa80);
	std::cout << cerfa80 << std::endl;
	slave.signAForm(cerfa1);
	std::cout << cerfa1 << std::endl;
	slave.signAForm(cerfa150);
	std::cout << cerfa150 << std::endl;
	boss.signAForm(cerfa80);
	std::cout << cerfa80 << std::endl;
	boss.signAForm(cerfa1);
	std::cout << cerfa1 << std::endl;
	
	return 0;
}
