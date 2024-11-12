/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:39 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 14:43:40 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		Cure &operator=(Cure const & rhs);
		~Cure(void);

		AMateria*	clone(void) const;
		void		use(ICharacter & target);
};

#endif  /* __CURE_HPP__ */
