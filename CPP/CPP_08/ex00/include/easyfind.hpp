/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:23:26 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:15 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename T>
int	easyfind(const T& c, const int& i)
{
	typename T::const_iterator it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw std::runtime_error("Element not found");
	int result = std::distance(c.begin(), it);
	return result;
}

#endif
