/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 17:31:58 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		std::cout << "Try Bureaucrat level 0:" << std::endl;
		Bureaucrat	god("Jesus", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Try Bureaucrat level 151:" << std::endl;
		Bureaucrat	intern("serge", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	boss("xavier", 1);
	Bureaucrat	slave("bob", 150);
	try
	{
		std::cout << std::endl;
		std::cout << "Try level 1 ++:" << std::endl;
		boss++;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Try level 151 --:" << std::endl;
		slave--; 
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "Display xavier and bob:" << std::endl;
		std::cout << boss << std::endl;
		std::cout << slave << std::endl;

		std::cout << std::endl;
		std::cout << "Pre-increment xavier, Pre-decrement bob:" << std::endl;
		std::cout << --boss << std::endl;
		std::cout << ++slave << std::endl;
		std::cout << std::endl;
		std::cout << "Post-increment xavier, Post-decrement bob:" << std::endl;
		std::cout << boss-- << std::endl;
		std::cout << slave++ << std::endl;
		std::cout << std::endl;
		std::cout << "Display xavier and bob:" << std::endl;
		std::cout << boss << std::endl;
		std::cout << slave << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
