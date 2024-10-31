/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 16:20:23 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(std::string const & type);
		Animal(Animal const & src);
		Animal &operator=(Animal const & rhs);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
	protected:
		std::string	m_type;
};

#endif  /* __ANIMAL_HPP__ */
