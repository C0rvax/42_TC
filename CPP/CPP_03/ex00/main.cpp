/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 12:45:27 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap	a;
	ClapTrap	b("jon");
	ClapTrap	c = b;
	
	a.printTrap();
	b.printTrap();
	c.printTrap();
	a.attack("georges");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(5);
	a.printTrap();
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	c.attack("bob");
	c.takeDamage(10);
	c.beRepaired(5);
	a.printTrap();
	b.printTrap();
	c.printTrap();

	return 0;
}
