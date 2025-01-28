/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:01:23 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 13:48:07 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	try
	{
		Span	emptyS(0);
		emptyS.addNumber(2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		Span	small(100);
		small.addNumber(2);
		small.shortestSpan();
		small.addNumber(4);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		Span	large(10000);
		large.addManyNumbers(99999999, 88);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		Span	veryLarge(10000000);
		veryLarge.addManyNumbers(99, 88);
		veryLarge.addOffsetNumbers(500, -500, 40);
		std::cout << "shorterstSpan: " << veryLarge.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << veryLarge.longestSpan() << std::endl;
		std::cout << "499 x 40 = " << 499 * 40 << std::endl;
		veryLarge.addOffsetNumbers(0, -500, 40);
		veryLarge.addOffsetNumbers(99999990, 500, 40);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		Span	negative(10000);
		negative.addOffsetNumbers(500, -500000, 40);
		std::cout << "shorterstSpan: " << negative.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << negative.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
