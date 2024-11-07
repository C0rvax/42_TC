/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:23 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:00:21 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include "ICharacter.hpp"

class	AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria &operator=(AMateria const & rhs);
		virtual	~AMateria(void);

		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter & target);

	protected:
		std::string	m_type;
};

#endif  /* __AMATERIA_HPP__ */
