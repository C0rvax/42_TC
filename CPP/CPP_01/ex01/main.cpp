/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:24:11 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 18:24:44 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	Zombie	instance0("DiDiEr");
	Zombie*	horde1;
	Zombie*	horde2;
	Zombie*	horde3;
	
	horde1 = zombieHorde(42, "xavier");
	if (!horde1)
		return (1);
	horde2 = zombieHorde(8, "bernard");
	if (!horde2)
		return (delete [] horde1, 1);
	for (int i = 0; i < 42; i++)
	{
		std::cout << "horde1[" << i << "]: ";
		horde1[i].announce();
	}
	for (int j = 0; j < 8; j++)
	{
		std::cout << "horde2[" << j << "]: ";
		horde2[j].announce();
	}
	instance0.announce();
	horde3 = zombieHorde(-1, "nope");
	if (!horde3)
	{
		std::cout << "pas de horde 3" << std::endl;
		delete [] horde1;
		delete [] horde2;
		return 1;
	}
	delete [] horde1;
	delete [] horde2;
	return 0;
}
