/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:07:55 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:13 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
#define __IMATERIASOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual			~IMateriaSource(void) {}
		virtual void	learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif  /* __IMATERIASOURCE_HPP__ */
