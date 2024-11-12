/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:14:05 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:06:42 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		Ice &operator=(Ice const & rhs);
		~Ice(void);

		AMateria*	clone() const;
		void		use(ICharacter & target);
	private:
		
};

#endif  /* __ICE_HPP__ */
