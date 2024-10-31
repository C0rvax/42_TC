/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 13:19:18 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main (void)
{
	DiamondTrap a("Yves");
	std::cout << std::endl;
	DiamondTrap	b( a );

	std::cout << std::endl;
	b.printTrap();
	std::cout << std::endl;
	a.printTrap();
	std::cout << std::endl;
	a.attack("robert");
	a.beRepaired(20);
	a.takeDamage(30);
	std::cout << std::endl;
	a.guardGate();
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;
	return 0;
}
