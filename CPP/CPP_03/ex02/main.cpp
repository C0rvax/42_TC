/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/12/26 12:16:05 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main (void)
{
	FragTrap	a("Serge");
	std::cout << std::endl;
	ScavTrap	b("jon");
	std::cout << std::endl;
	
	a.attack("georges");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(5);
	a.attack("robert");
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
	a.highFivesGuys();
	std::cout << std::endl;
	a.takeDamage(1000);
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
	a.attack("nobody");
	std::cout << std::endl;

	return 0;
}
