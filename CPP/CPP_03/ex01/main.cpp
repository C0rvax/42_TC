/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:47:45 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/30 23:24:53 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap	a("Serge");
	ScavTrap	b("jon");
	ScavTrap	c( a );
	
	a.attack("georges");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(5);
	for (int i = 0; i < 11; i++)
	{
		b.attack("Yvan");
	}
	b.takeDamage(5);
	b.beRepaired(10);
	c.takeDamage(10);
	c.takeDamage(80);
	c = b;
	c.takeDamage(80);
	c.takeDamage(80);

	return 0;
}
