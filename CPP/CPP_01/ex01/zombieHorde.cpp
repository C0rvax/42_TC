/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:20:59 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 15:18:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie*	horde;

	if (N < 0)
		return NULL;
	horde = new(std::nothrow) Zombie[N];
	if (!horde)
		return NULL;
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
