/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sedpp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/03 18:53:35 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sedpp.hpp"
#include <fstream>
#include <iostream>

Sedpp::Sedpp(std::string filename, std::string s1, std::string s2) :
	m_filename(filename), m_s1(s1), m_s2(s2)
{
}

Sedpp::~Sedpp()
{
}

std::string	Sedpp::m_replace(std::string buff)
{
	std::string	lineChanged;
	size_t	pos = 0;
	size_t	last = 0;

	while(pos != std::string::npos)
	{
		pos = buff.find(m_s1, last);
		lineChanged.append(buff, last, pos - last);
		if (pos != std::string::npos)
		{
			last = pos + m_s1.size();
			lineChanged += m_s2;
		}
	}
	return (lineChanged);

}

int	Sedpp::sedReplace()
{
	std::string		buff;
	std::ifstream	inputStream;
	std::ofstream	outputStream;

	inputStream.open(m_filename, std::ifstream::in);
	if (!inputStream.good())
	{
		std::cout << "Sedpp: " << m_filename << ERR_FILE << std::endl;
		return (1);
	}
	outputStream.open(m_filename + ".replace", std::ifstream::out);
	if (!outputStream.good())
	{
		std::cout << "Sedpp: " << m_filename + ".replace";
		std::cout << ERR_FILE << std::endl;
		inputStream.close();
		return (1);
	}
	while (std::getline(inputStream, buff).good())
	{
		outputStream << m_replace(buff);
		if (!inputStream.eof())
			outputStream << std::endl;
	}
	inputStream.close();
	outputStream.close();
	return (0);
}
