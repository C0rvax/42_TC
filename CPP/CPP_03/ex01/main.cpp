/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/26 12:17:47 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main (void)
{

	ScavTrap	a("Serge");
	std::cout << std::endl;
	ScavTrap	b("jon");
	std::cout << std::endl;
	ScavTrap	c( a );
	std::cout << std::endl;
	ClapTrap	d("clap");
	std::cout << std::endl;
	ScavTrap	e;
	std::cout << std::endl;
	
	e.attack("roger");
	std::cout << std::endl;
	a.attack("georges");
	std::cout << std::endl;
	d.attack("Yvan");
	std::cout << std::endl;
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(-5);
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	std::cout << std::endl;
	b.takeDamage(5);
	std::cout << std::endl;
	b.beRepaired(10);
	std::cout << std::endl;
	c.takeDamage(10);
	std::cout << std::endl;
	c.takeDamage(80);
	std::cout << std::endl;
	c = b;
	std::cout << std::endl;
	c.guardGate();
	std::cout << std::endl;
	c.takeDamage(1000);
	std::cout << std::endl;
	c.guardGate();
	std::cout << std::endl;

	return 0;
}
