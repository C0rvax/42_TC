/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/06 13:07:06 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{

	ScavTrap	a("Serge");
	ScavTrap	b("jon");
	ScavTrap	c( a );
	ClapTrap	d("clap");
	ScavTrap	e;
	
	e.attack("roger");
	a.attack("georges");
	d.attack("Yvan");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(-5);
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	b.takeDamage(5);
	b.beRepaired(10);
	c.takeDamage(10);
	c.takeDamage(80);
	c = b;
	c.guardGate();
	c.takeDamage(1000);
	c.guardGate();

	return 0;
}
