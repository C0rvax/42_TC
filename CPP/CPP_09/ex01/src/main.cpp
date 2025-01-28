/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:14:08 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/29 00:00:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

int	main(int ac, char** av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Error: Usage: ./RPN 'Inverted Polish math expression'");
		RPN		r;
		std::string	expression(av[1]);
		std::cout << r.calculate(expression) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
/*
		std::string	expression(av[1]);
		std::string expression("8 9 * 9 - 9 - 9 - 4 - 1 +"); (void)av; // -> 42
		std::string	expression("1 2 * 2 / 2 * 2 4 - +"); (void)av; // -> 0
		std::string	expression("1 2 * 2 / 2 * 2 4 - + 8 + 1 * 9 8 1 + /"); (void)av; // too many operand
		std::string	expression("1 2 * 2 / 2 * 2 4 - + 8 + 1 * 9 8 1 + / -"); (void)av; // -> 7
		std::string expression("(1 + 1)"); (void)av; // token too big
		std::string expression("2 1 + 3 ( 1 + 1 )"); (void)av; // Unsup operand
*/
