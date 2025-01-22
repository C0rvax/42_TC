/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:14:53 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 17:29:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename Array, typename Function>
void	iter(Array* a, size_t l, Function f)
{
	for (size_t i = 0; i < l; i++)
		f(a[i]);
}

template <typename T>
void	printIt(T& value)
{
	std::cout << value << std::endl;
}

#endif
