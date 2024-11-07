/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:33:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 16:36:55 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		MateriaSource &operator=(MateriaSource const & rhs);
		~MateriaSource(void);

		void	learnMateria(AMateria * m);
		AMateria*	createMateria(std::string const & type);
		
	private:
		static const int	m_recipesMax = 4;
		AMateria*			m_recipes[m_recipesMax];
};

#endif  /* __MATERIASOURCE_HPP__ */
