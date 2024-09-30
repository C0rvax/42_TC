/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:40:24 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/01 00:35:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->m_contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	int	index;

	index = m_contactCount % 8;
	std::cout << std::endl;
	std::cout << "|           Adding new contact              |" << std::endl;
	this->m_list[index].setFirstName(m_addInput("| First name: "));
	this->m_list[index].setLastName(m_addInput("| Last name: "));
	this->m_list[index].setNickName(m_addInput("| Nick name: "));
	this->m_list[index].setPhoneNumber(m_addInput("| Phone number: "));
	this->m_list[index].setDarkestSecret(m_addInput("| Darkest secret: "));
	std::cout << "|             Contact added                 |" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	m_contactCount++;
}

void	PhoneBook::search()
{
	std::string	input;
	int			index;

	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|           My Awesome PhoneBook            |" << std::endl;
	std::cout << "|                Search Menu                |" << std::endl;
	if (m_contactCount > 0)
	{
		m_printIndex();
		std::cout << "| Type Index number to see more informations|" << std::endl;
		std::cout << std::endl;
		getline(std::cin, input);
		index = m_getIndex(input);
		while(index > std::min(8, m_contactCount) || index <= 0)
		{
			std::cout << "|Wrong input: chose a number between 1 and ";
			std::cout << std::min(8, m_contactCount) << " |" << std::endl;
			getline(std::cin, input);
			index = m_getIndex(input);
		}
		m_printContact(index);
	}
	else
	{
		std::cout << "| Nothing to display: the PhoneBook is empty|" << std::endl;
		std::cout << "|            Back to Main Menu              |" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void	PhoneBook::m_printIndex() const
{
	int	index;

	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < 8 && i < this->m_contactCount; i++)
	{
		index = i + 1;
		std::cout << "|         " << index << "|";
		m_printTen(m_list[i].getFirstName());
		std::cout << "|";
		m_printTen(m_list[i].getLastName());
		std::cout << "|";
		m_printTen(m_list[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

int	PhoneBook::m_getIndex(std::string input) const
{
	int	index;

	if (input.length() > 1 || input.length() < 1)
		return (0);
	index = input[0] - 48;
	return (index);
}

void	PhoneBook::m_printContact(int index) const
{
	std::cout << "| Index: " << index << std::endl;
	std::cout << "| First name: ";
	std::cout << m_list[index - 1].getFirstName() << std::endl;
	std::cout << "| Last name: ";
	std::cout << m_list[index - 1].getLastName() << std::endl;
	std::cout << "| Nick name: ";
	std::cout << m_list[index - 1].getNickName() << std::endl;
	std::cout << "| Phone number: ";
	std::cout << m_list[index - 1].getPhoneNumber() << std::endl;
	std::cout << "| Darkest secret: ";
	std::cout << m_list[index - 1].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::m_printTen(std::string info) const
{
	if (info.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << info[i];
		std::cout << ".";
	}
	else
	{
		for (int i = info.length(); i < 10; i++)
			std::cout << " ";
		std::cout << info;
	}
}

std::string	PhoneBook::m_addInput(std::string attribute) const
{
	std::string input;

	std::cout << attribute;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Invalid Input: No empty string" << std::endl;
		std::cout << attribute;
		getline(std::cin, input);
	}
	return (input);
}

//	std::cout << "|-------------------------------------------|" << std::endl;
