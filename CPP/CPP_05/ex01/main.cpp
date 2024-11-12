/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/12 17:39:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	god("Jesus", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
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
		boss++;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		slave--; 
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << boss << std::endl;
	std::cout << slave << std::endl;

	std::cout << std::endl;
	std::cout << --boss << std::endl;
	std::cout << ++slave << std::endl;
	std::cout << std::endl;
	std::cout << boss-- << std::endl;
	std::cout << slave++ << std::endl;
	std::cout << std::endl;
	std::cout << boss << std::endl;
	std::cout << slave << std::endl;
	
	return 0;
}
