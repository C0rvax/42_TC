/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:40:57 by aduvilla          #+#    #+#             */
/*   Updated: 2024/09/30 19:53:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const
{
	return (this->m_firstName);
}

std::string Contact::getLastName() const
{
	return (this->m_lastName);
}

std::string Contact::getNickName() const
{
	return (this->m_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (this->m_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->m_darkestSecret);
}

void Contact::setFirstName(std::string t_firstName)
{
	this->m_firstName = t_firstName;
}

void Contact::setLastName(std::string t_lastName)
{
	this->m_lastName = t_lastName;
}

void Contact::setNickName(std::string t_nickName)
{
	this->m_nickName = t_nickName;
}

void Contact::setPhoneNumber(std::string t_phoneNumber)
{
	this->m_phoneNumber = t_phoneNumber;
}

void Contact::setDarkestSecret(std::string t_darkestSecret)
{
	this->m_darkestSecret = t_darkestSecret;
}

