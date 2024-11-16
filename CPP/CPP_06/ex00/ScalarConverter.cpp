/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:37 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/16 16:44:01 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>
#include <iostream>

ScalarConverter::ScalarConverter	(void)
{
}

ScalarConverter::ScalarConverter	(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter	(void)
{
}

static e_type	getType(std::string const & str)
{
	std::string	type[] = {"inf", "+inf", "inff", "+inff", "-inf", "-inff", "nan", "nanf"};
	for (int i = 0; i < 8; i++)
		if (str == type[i])
			return LITERAL;
	if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]))
		return CHAR;
	int	coma = 0;
	size_t	len = str.length();
	size_t	start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	for (size_t i = start; i < len - 1; i++)
	{
		if (str[i] == '.')	
			coma++;
		if ((!std::isdigit(str[i]) && str[i] != '.') || coma == 2)
			return NONE;
	}
	if (str[len - 1] == 'f' && coma == 1 && str[len - 2] != '.')
		return FLOAT;
	if (std::isdigit(str[len - 1]))
	{
		if (coma == 0)
			return INT;
		return DOUBLE;
	}
	return NONE;
}

static void	printChar(std::string const & str)
{
	char	value = str[0];
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

static void	printInt(std::string const & str)
{
	int	value = std::atoi(str.c_str());
	std::cout << "char: " << ((value >= 32 && value <= 126) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << value << ".0f" << std::endl;
	std::cout << "double: " << value << ".0" << std::endl;
}

static void	printFloat(std::string const & str)
{
	float	value = std::atof(str.c_str());
//	bool	outLimit = value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min();
	std::cout << "char: " << ((value >= 32 && value <= 126) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (std::floor(value) == value)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
	else
	{
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
//	std::cout << "int: " << (outLimit ? "impossible" : std::to_string(static_cast<int>(value))) << std::endl;
}

static void	printDouble(std::string const & str)
{
	double	value = std::atof(str.c_str());
	std::cout << "char: " << ((value >= 32 && value <= 126) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	else if (std::floor(value) == value)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
}

static void	printPseudoLiteral(std::string const & str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << 'f' << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (str == "nan" || str == "nanf")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << 'f' << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
	else
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << 'f' << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
}

static void	printNone(std::string const & str)
{
	std::cout << str << " is a wrong input" << std::endl;
}

void	ScalarConverter::convert(std::string const & str)
{
	e_type	type = getType(str);
	void	(*funcions[])(std::string const &) = {&printChar, &printInt, &printFloat, &printDouble, &printPseudoLiteral, &printNone};

	funcions[type](str);
}
