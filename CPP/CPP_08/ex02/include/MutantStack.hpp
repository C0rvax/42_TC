/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:21 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/18 15:04:14 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template< typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(MutantStack const & src) : std::stack<T, Container>(src) {}
	MutantStack &operator=(MutantStack const & rhs)
	{
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename Container::iterator iterator;
	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }
};

#endif
