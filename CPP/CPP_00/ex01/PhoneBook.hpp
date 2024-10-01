/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:03:52 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/01 10:03:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
	
	private:
		int		m_contactCount;
		Contact	m_list[8];
		void	m_printIndex() const;
		int		m_getIndex(std::string input) const;
		void	m_printContact(int index) const;
		void	m_printTen(std::string info) const;
		std::string	m_addInput(std::string attribute) const;
};
#endif
