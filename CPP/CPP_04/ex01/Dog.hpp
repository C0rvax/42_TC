/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 17:11:20 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		Dog &operator=(Dog const & rhs);
		~Dog(void);

		void	makeSound(void) const;
};

#endif  /* __DOG_HPP__ */
