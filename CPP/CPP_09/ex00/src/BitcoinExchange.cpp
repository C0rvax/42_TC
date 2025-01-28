/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:24:00 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 22:45:19 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange	(void)
{
	m_dateMin = std::numeric_limits<int>::max();
	m_dateMax = std::numeric_limits<int>::min();
	mapDataCsv();
}

BitcoinExchange::BitcoinExchange	(BitcoinExchange const & src) {	*this = src; }

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
		m_map = rhs.m_map;
	return *this;
}

BitcoinExchange::~BitcoinExchange	(void) {}

void	BitcoinExchange::setMap(std::string& date, std::string& value)
{
	int intDate = getIntDate(date);
	if (intDate < m_dateMin)
		m_dateMin = intDate;
	if (intDate > m_dateMax)
		m_dateMax = intDate;
	m_map[intDate] = stodouble(value);
}

void	BitcoinExchange::mapDataCsv()
{
	std::ifstream	file(DATACSV);
	if (!file.is_open())
		throw std::runtime_error("Error: Cannot open file");
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string	date, value;
		if (std::getline(ss, date, ',') && std::getline(ss, value))
			setMap(date, value);
		else
			throw std::runtime_error("Error: Wrong file line");
	}
	file.close();
}

void	BitcoinExchange::HowRichIAm(char* input)
{
	std::ifstream	file(input);
	if (!file.is_open())
		throw std::runtime_error("Error: Cannot open file");
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			std::stringstream	ss(line);
			std::string	date, value;
			if (std::getline(ss, date, '|') && std::getline(ss, value))
			{
				int	inputDate = getIntDate(date);
				if (inputDate < m_dateMin)
					throw std::runtime_error("Error: Bitcoin was not created");
				if (inputDate > m_dateMax)
					inputDate = m_dateMax;
				double	inputValue = stodouble(value);
				if (inputValue > 1000)
					throw std::runtime_error("Error: too large a number");
				std::map<int, double>::iterator	it = m_map.find(inputDate);
				while (it  == m_map.end() && inputDate > m_dateMin)
				{
					decrementDay(inputDate);
					it = m_map.find(inputDate);
				}
				std::cout << date << "=>" << value << " = " << it->second * inputValue << std::endl;
			}
			else
				throw std::runtime_error("Error: not enough parameters");
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() < 10 || date.length() > 11)
		return false;
	for (size_t i = 0; i < 10; ++i)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
			return false;
		else if (!std::isdigit(date[i]) && date[i] != '-')
			return false;
	}
	return true;
}

int	BitcoinExchange::getIntDate(std::string& date)
{
	if (date.empty())
		throw std::runtime_error("Error: no date");
	if (!isValidDate(date))
		throw std::runtime_error("Error: wrong date format");
	int	year, month, day;
	std::istringstream	yearStream(date.substr(0, 4));
	std::istringstream	monthStream(date.substr(5, 2));
	std::istringstream	dayStream(date.substr(8, 2));
	yearStream >> year;
	monthStream >> month;
	dayStream >> day;
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw std::runtime_error("Error: wrong date format");
	return year * 10000 + month * 100 + day;
}

double	stodouble(const std::string& str)
{
	if (str.empty())
		throw std::runtime_error("Error: value is empty");
	if (str.find_first_not_of("0123456789.-", 1) != std::string::npos)
		throw std::runtime_error("Error: value is neither an int nor a double");
	if (str.find("-") != std::string::npos)
		throw std::runtime_error("Error: not a positive number");
	std::stringstream	ss(str);
	double result;
	ss >> result;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("Invalid double format");
	return result;
}

void	decrementDay(int& date)
{
	if (date % 100 > 1)
		date--;
	else
	{
		if ((date / 100) % 100 > 1)
			date -= 89;
		else
			date -= 6989;
	};
}
