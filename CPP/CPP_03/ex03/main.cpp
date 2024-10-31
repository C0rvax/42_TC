/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/31 11:35:55 by aduvilla         ###   ########.fr       */
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
	a.printTrap();
	a.attack("robert");
	a.beRepaired(20);
	a.takeDamage(30);
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
	return 0;
}
