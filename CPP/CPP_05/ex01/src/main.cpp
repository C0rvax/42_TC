/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 18:05:18 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		std::cout << "Try Form signGrade 0:" << std::endl;
		Form	cerfa0("cerfa0", 0, 1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Try Form executeGrade 0:" << std::endl;
		Form	cerfa0("cerfa0", 1, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Try Form signGrade 151:" << std::endl;
		Form	japd("japd", 151, 140);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Try Form executeGrade 151:" << std::endl;
		Form	japd("japd", 140, 151);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	boss("xavier", 1);
		Bureaucrat	slave("bob", 81);
		Form		cerfa80("cerfa80", 80, 80);
		Form		cerfa1("cerfa1", 1, 1);
		Form		cerfa150("cerfa150", 150, 150);

		std::cout << std::endl;
		std::cout << slave << " try to sign: " << cerfa150 << std::endl;
		slave.signForm(cerfa150);
		std::cout << "New Form: " << cerfa150 << std::endl;

		std::cout << std::endl;
		std::cout << slave << " try to sign: " << cerfa80 << std::endl;
		slave.signForm(cerfa80);
		std::cout << "New Form: " << cerfa80 << std::endl;

		std::cout << std::endl;
		std::cout << "New promotion: " << slave++ << " is now " << slave << std::endl;
		std::cout << slave << " try to sign: " << cerfa80 << std::endl;
		slave.signForm(cerfa80);
		std::cout << "New Form: " << cerfa80 << std::endl;

		std::cout << std::endl;
		std::cout << slave << " try to sign: " << cerfa1 << std::endl;
		slave.signForm(cerfa1);
		std::cout << "New Form: " << cerfa1 << std::endl;

		std::cout << std::endl;
		std::cout << boss << " try to sign: " << cerfa1 << std::endl;
		boss.signForm(cerfa1);
		std::cout << "New Form: " << cerfa1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
