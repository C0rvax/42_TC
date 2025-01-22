/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:59:20 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 17:04:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& x, T& y)
{
	T	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
const T&	max(const T& x, const T& y)
{
	if (x > y)
		return x;
	return y;
}

template <typename T>
const T&	min(const T& x, const T& y)
{
	if (x < y)
		return x;
	return y;
}

#endif
