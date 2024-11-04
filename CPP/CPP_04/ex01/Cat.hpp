/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:33 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 17:11:04 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		Cat &operator=(Cat const & rhs);
		~Cat(void);

		void	makeSound(void) const;
};

#endif  /* __CAT_HPP__ */
