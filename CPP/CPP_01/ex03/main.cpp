/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:47:56 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/02 14:14:56 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string 	hello = "HI THIS IS BRAIN";
	std::string*	stringPTR = &hello;
	std::string&	stringREF = hello;

	std::cout << "Adress of:" << std::endl;
	std::cout << "-string: " << &hello << std::endl;
	std::cout << "-stringPTR: " << stringPTR << std::endl;
	std::cout << "-stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of:" << std::endl;
	std::cout << "-string: " << hello << std::endl;
	std::cout << "-stringPTR: " << *stringPTR << std::endl;
	std::cout << "-stringREF: " << stringREF << std::endl;
	return (0);
}
