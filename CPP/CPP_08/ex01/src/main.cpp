/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:01:23 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/18 14:26:26 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	try
	{
		std::cout << "Add to empty:" << "\n";
		Span	emptyS(0);
		emptyS.addNumber(2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\ntry to span between 1 number\n";
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
		std::cout << "\ntry to add too many numbers\n";
		Span	large(10000);
		large.addManyNumbers(99999999, 88);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	veryLarge(10000000);
		veryLarge.addManyNumbers(99, 88);
		std::cout << "\nAdd 99 numbers with offset 1 starting at 88:\n";
		std::cout << "shorterstSpan: " << veryLarge.shortestSpan() << "\n";
		std::cout << "longestSpan: " << veryLarge.longestSpan() << "\n";
		veryLarge.addManyNumbers(500, -500, 40);
		std::cout << "Add 500 numbers with offset 40 starting at -500:\n";
		std::cout << "shorterstSpan: " << veryLarge.shortestSpan() << "\n";
		std::cout << "longestSpan: " << veryLarge.longestSpan() << "\n";
		std::cout << "499 x 40 = " << 499 * 40 << "\n";
		veryLarge.addManyNumbers(0, -500, 40);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	negative(10000);
		negative.addManyNumbers(500, -500000, 40);
		std::cout << "\nAdd 500 numbers with offset 40 starting at -500000:\n";
		std::cout << "shorterstSpan: " << negative.shortestSpan() << "\n";
		std::cout << "longestSpan: " << negative.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
