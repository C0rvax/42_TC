/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:24:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/02 13:46:14 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	Zombie	instance0("DiDiEr");
	Zombie*	horde1;
	Zombie*	horde2;
	
	horde1 = zombieHorde(42, "xavier");
	if (!horde1)
		return (1);
	horde2 = zombieHorde(8, "bernard");
	if (!horde2)
		return (delete [] horde1, 1);
	for (int i = 0; i < 42; i++)
		horde1[i].announce();
	for (int j = 0; j < 8; j++)
		horde2[j].announce();
	instance0.announce();
	delete [] horde1;
	delete [] horde2;
	return (0);
}
