/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:53:46 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 10:54:55 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		Brain &operator=(Brain const & rhs);
		~Brain();

		void		setIdea(std::string const & idea, int index);
		std::string	getIdea(int index) const;
	private:
		std::string	ideas[100];
};

#endif  /* __BRAIN_HPP__ */
