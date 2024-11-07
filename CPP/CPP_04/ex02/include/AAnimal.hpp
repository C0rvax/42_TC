/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:15 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 10:34:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <iostream>

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string const & type);
		AAnimal(AAnimal const & src);
		AAnimal &operator=(AAnimal const & rhs);
		virtual ~AAnimal(void);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
	protected:
		std::string	m_type;
};

#endif  /* __AANIMAL_HPP__ */
