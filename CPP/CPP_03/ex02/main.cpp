/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 23:55:49 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	FragTrap	a("Serge");
	ScavTrap	b("jon");
	
	a.attack("georges");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(5);
	a.attack("robert");
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	b.takeDamage(5);
	b.beRepaired(10);
	a.highFivesGuys();
	a.takeDamage(1000);
	a.highFivesGuys();
	a.attack("nobody");

	return 0;
}
