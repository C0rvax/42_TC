/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sedpp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 18:37:11 by aduvilla         ###   ########.fr       */
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
	std::ifstream	input;
	std::ofstream	Output;

	input.open(m_filename, std::ifstream::in);
	if (!input.good())
	{
		std::cout << "Sedpp: " << m_filename << ERR_FILE << std::endl;
		return (1);
	}
	Output.open(m_filename + ".replace", std::ifstream::out);
	if (!Output.good())
	{
		std::cout << "Sedpp: " << m_filename + ".replace";
		std::cout << ERR_FILE << std::endl;
		input.close();
		return (1);
	}
	while (std::getline(input, buff).good())
	{
		Output << m_replace(buff);
		if (!input.eof())
			Output << std::endl;
	}
	input.close();
	Output.close();
	return (0);
}
