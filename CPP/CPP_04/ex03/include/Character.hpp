/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:02:16 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/12 14:18:15 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		Character &operator=(Character const & rhs);
		~Character(void);

		const std::string&	getName(void) const;
		void				equip(AMateria * m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);
		static void			deleteFloor(void);

	private:
		std::string			m_name;
		static const int	m_inventoryMax = 4;	
		AMateria*			m_inventory[m_inventoryMax];
		static AMateria*	m_floor[100];
		static int			m_floorIdx;
		
};

#endif  /* __CHARACTER_HPP__ */
