/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:24:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/01 18:36:41 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main()
{
	Zombie	*instance1 = newZombie("pedro");
	Zombie	*instance2 = newZombie("Serge");
	
	instance1->announce();
	instance2->announce();
	randomChump("claude");
	randomChump("Marco");
	delete instance1;
	delete instance2;
	return (0);
}
