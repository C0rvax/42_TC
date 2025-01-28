/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:31:50 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 22:27:50 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char** av)
{
	try
	{
		if (ac != 2)
			std::cout << "Error: Usage: ./btc [input_file]" << std::endl;
		BitcoinExchange	btcE;
		btcE.HowRichIAm(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
