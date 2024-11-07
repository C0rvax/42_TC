/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:51:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:00:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_HPP__
#define __ICHARACTER_HPP__

//#include "AMateria.hpp"
#include <iostream>
#include <string>


class	AMateria;

class	ICharacter
{
	public:
		virtual						~ICharacter(void) {};
		virtual const std::string&	getName() const = 0;
		virtual void				equip(AMateria * m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter & target) = 0;
};

#endif  /* __ICHARACTER_HPP__ */
