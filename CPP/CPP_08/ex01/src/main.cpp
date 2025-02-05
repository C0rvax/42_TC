/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:01:23 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 16:30:06 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	try
	{
		std::cout << "Add to empty:" << std::endl;
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
		std::cout << "try to span between 1 number" << std::endl;
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
		std::cout << "try to add too many numbers" << std::endl;
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
		std::cout << "Add 99 numbers with offset 1 starting at 88:" << std::endl;
		std::cout << "shorterstSpan: " << veryLarge.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << veryLarge.longestSpan() << std::endl;
		veryLarge.addManyNumbers(500, -500, 40);
		std::cout << "Add 500 numbers with offset 40 starting at -500:" << std::endl;
		std::cout << "shorterstSpan: " << veryLarge.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << veryLarge.longestSpan() << std::endl;
		std::cout << "499 x 40 = " << 499 * 40 << std::endl;
		veryLarge.addManyNumbers(0, -500, 40);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		Span	negative(10000);
		negative.addManyNumbers(500, -500000, 40);
		std::cout << "Add 500 numbers with offset 40 starting at -500000:" << std::endl;
		std::cout << "shorterstSpan: " << negative.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << negative.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
