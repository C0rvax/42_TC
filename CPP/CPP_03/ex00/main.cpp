/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/26 12:18:50 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main (void)
{
	ClapTrap	a;
	std::cout << std::endl;
	ClapTrap	b("jon");
	std::cout << std::endl;
	ClapTrap	c = b;
	std::cout << std::endl;
	
	a.printTrap();
	std::cout << std::endl;
	b.printTrap();
	std::cout << std::endl;
	c.printTrap();
	std::cout << std::endl;
	a.attack("georges");
	std::cout << std::endl;
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(5);
	std::cout << std::endl;
	a.printTrap();
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	std::cout << std::endl;
	c.attack("bob");
	std::cout << std::endl;
	c.takeDamage(10);
	std::cout << std::endl;
	c.beRepaired(5);
	std::cout << std::endl;
	a.printTrap();
	std::cout << std::endl;
	b.printTrap();
	std::cout << std::endl;
	c.printTrap();
	std::cout << std::endl;

	return 0;
}
