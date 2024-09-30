/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:42:51 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/01 00:35:16 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void	mainMenu()
{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|           My Awesome PhoneBook            |" << std::endl;
		std::cout << "|                 Main Menu                 |" << std::endl;
		std::cout << "| Type 'ADD' to add a new contact           |" << std::endl;
		std::cout << "| Type 'SEARCH' to find an exitsting contact|" << std::endl;
		std::cout << "| Type 'EXIT' to exit My Awesome PhoneBook  |" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << std::endl;
}

int	main()
{
	PhoneBook	myAwesomePhoneBook;
	std::string	input;

	mainMenu();
	while(1)
	{
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
			myAwesomePhoneBook.add();
		else if (input.compare("SEARCH") == 0)
			myAwesomePhoneBook.search();
		else if (input.compare("EXIT") == 0)
			return (0);
		else
		{
			std::cout << std::endl;
			std::cout << "|              Command not found            |" << std::endl;
			std::cout << "|       Type 'ADD', 'SEARCH' or 'EXIT'      |" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}
