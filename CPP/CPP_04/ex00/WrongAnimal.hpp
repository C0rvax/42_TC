/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:18:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 16:24:44 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const & type);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal &operator=(WrongAnimal const & rhs);
		virtual ~WrongAnimal(void);

		void	makeSound(void) const;
		std::string		getType(void) const;
	protected:
		std::string	m_type;
};

#endif  /* __WRONGANIMAL_HPP__ */
