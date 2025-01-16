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
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		Form	cerfa0("cerfa0", 0, 1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	cerfa0("cerfa0", 1, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	japd("japd", 151, 140);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	japd("japd", 140, 151);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	boss("xavier", 1);
	Bureaucrat	slave("bob", 150);
	Form		cerfa80("cerfa80", 80, 80);
	Form		cerfa1("cerfa1", 1, 1);
	Form		cerfa150("cerfa150", 150, 150);

	std::cout << cerfa80 << std::endl;
	slave.signForm(cerfa80);
	std::cout << cerfa80 << std::endl;
	slave.signForm(cerfa1);
	std::cout << cerfa1 << std::endl;
	slave.signForm(cerfa150);
	std::cout << cerfa150 << std::endl;
	boss.signForm(cerfa80);
	std::cout << cerfa80 << std::endl;
	boss.signForm(cerfa1);
	std::cout << cerfa1 << std::endl;
	
	return 0;
}
