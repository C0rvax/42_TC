/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 10:38:12 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		Cat&	operator=(Cat const & rhs);
		~Cat(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	private:
		Brain*	m_brain;
};

#endif  /* __CAT_HPP__ */
