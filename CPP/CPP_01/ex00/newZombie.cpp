/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:15:23 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 15:13:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*newZ;

	newZ = new(std::nothrow) Zombie(name);
	return (newZ);
}
//	newZ = new(std::nothrow) Zombie(name);
//	if (!newZ)
//		return (NULL);
//
//	try
//		newZ = new Zombie(name);
//	catch (const std::bad_alloc& err)
//		std::cerr << "Allocation failed: " << err.what() << std::endl;
