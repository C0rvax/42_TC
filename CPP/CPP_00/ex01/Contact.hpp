/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:49:32 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/01 09:45:08 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string
				nickName, std::string phoneNumber, std::string darkestSecret);
		~Contact();

		std::string	getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void	setFirstName(std::string t_firstName);
		void	setLastName(std::string t_lastName);
		void	setNickName(std::string t_nickName);
		void	setPhoneNumber(std::string t_phoneNumber);
		void	setDarkestSecret(std::string t_darkestSecret);

	private:
		std::string	m_firstName;
		std::string m_lastName;
		std::string m_nickName;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
};
#endif
