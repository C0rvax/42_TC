/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 10:37:51 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		Dog&	operator=(Dog const & rhs);
		~Dog(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	private:
		Brain*	m_brain;
};

#endif  /* __DOG_HPP__ */
