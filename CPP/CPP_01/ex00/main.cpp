/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:24:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	instance0("DiDiEr");
	Zombie	*instance1 = newZombie("pedro");
	Zombie	*instance2 = newZombie("Serge");
	
	instance0.announce();
	instance1->announce();
	instance2->announce();
	randomChump("claude");
	randomChump("Marco");
	delete instance1;
	delete instance2;
	return (0);
}
