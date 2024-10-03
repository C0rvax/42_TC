/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:15:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/03 18:53:19 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sedpp.hpp"

int	main(int ac, char **av)
{

	if (ac < 4)
	{
		std::cout << "Sedpp: Too few arguments:" << FORM << std::endl;
		return (1);
	}
	if (ac > 4)
	{
		std::cout << "Sedpp: Too many arguments:" << FORM << std::endl;
		return (1);
	}
	if (*av[1] == 0 || *av[2] == 0)
	{
		std::cout << "Sedpp: file name and s1 cannot by empty" << std::endl;
		return (1);
	}
	Sedpp	instance(av[1], av[2], av[3]);
	if (instance.sedReplace())
		return (1);
	return (0);
}
/*
std::string	sedReplace(std::string buff, std::string s1, std::string s2)
{
	std::string	lineChanged;
	size_t	pos = 0;
	size_t	last = 0;

	while(pos != std::string::npos)
	{
		pos = buff.find(s1, last);
		lineChanged.append(buff, last, pos - last);
		if (pos != std::string::npos)
		{
			last = pos + s1.size();
			lineChanged += s2;
		}
	}
	return (lineChanged);
}

int	sedpp(std::string fileName, std::string s1, std::string s2)
{
	std::string		buff;
	std::ifstream	inputStream;
	std::ofstream	outputStream;

	inputStream.open(fileName, std::ifstream::in);
	if (!inputStream.good())
	{
		std::cout << "Sedpp: " << fileName << ": cannot open file" << std::endl;
		return (1);
	}
	outputStream.open(fileName + ".replace", std::ifstream::out);
	if (!outputStream.good())
	{
		std::cout << "Sedpp: " << fileName + ".replace";
		std::cout << ": cannot open file" << std::endl;
		inputStream.close();
		return (1);
	}
	while (std::getline(inputStream, buff).good())
	{
		outputStream << sedReplace(buff, s1, s2);
		if (!inputStream.eof())
			outputStream << std::endl;
	}
	inputStream.close();
	outputStream.close();
	return (0);
}
*/
