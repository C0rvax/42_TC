/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:29:53 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/23 19:01:49 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cctype>
#include <string>

void	printSquare(int & value)
{
	std::cout << value * value << std::endl;
}

void	printMaj(char & c)
{
	char	C = std::toupper(c);
	std::cout << C << std::endl;
}

void	printLoud(std::string & str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << static_cast<char>(std::toupper(*it));
	std::cout << std::endl;
}

int	main()
{
	int	intA[] = { 2, 4, 8, 16, 32, 64};
	iter<int>(intA, static_cast<unsigned int>(sizeof(intA) / sizeof(intA[0])), printIt<int>);
	std::cout << std::endl;
	iter<int>(intA, static_cast<unsigned int>(sizeof(intA) / sizeof(intA[0])), printSquare);
	std::cout << std::endl;

	char	charA[] = { 't', 'o', ' ', 'u', 'p', 'p', 'e', 'r'};
	iter<char>(charA, static_cast<unsigned int>(sizeof(charA) / sizeof(charA[0])), printIt<char>);
	std::cout << std::endl;
	iter<char>(charA, static_cast<unsigned int>(sizeof(charA) / sizeof(charA[0])), printMaj);
	std::cout << std::endl;

	std::string	strA[] = { "hello", "world", "!"};
	iter<std::string>(strA, static_cast<unsigned int>(sizeof(strA) / sizeof(strA[0])), printIt<std::string>);
	std::cout << std::endl;
	iter<std::string>(strA, static_cast<unsigned int>(sizeof(strA) / sizeof(strA[0])), printLoud);
}
