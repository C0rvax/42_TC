/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:21 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 18:17:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main (void)
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ));
	Fixed	c;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << "max entre a et b: ";
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "min entre a et b: ";
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << std::endl;
	std::cout << "a vaut " << a << " et b vaut " << b << std::endl;
	if (a <= b)
		std::cout << "a est inferieur ou égal à b" << std::endl;
	if (c == 0)
	{
		std::cout << "c vaut 0" << std::endl;
		std::cout << c << std::endl;
		std::cout << ++c << std::endl;
		std::cout << c << std::endl;
		std::cout << c++ << std::endl;
		std::cout << c << std::endl;
		std::cout << "a vaut " << a << " et c vaut " << c << std::endl;
		if (c <= a)
		{
			std::cout << "c est inferieur ou égal à a" << std::endl;
			if (c < a)
				std::cout << "error" << std::endl;
			else
				std::cout << "c n'est pas strictement inferieur à a" << std::endl;
		}
		if (c != a)
			std::cout << "error" << std::endl;
		else
			std::cout << "a + c = " << a + c << std::endl;
		std::cout << "a + c - b = " << a + c - b << std::endl;
	}
	return 0;
}
