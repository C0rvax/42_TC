/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:04:09 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 16:32:35 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main()
{
	Base*	b[10];
	for (size_t i = 0; i < 10; i++)
	{
		b[i] = generte();
		std::cout << "no: " << i << " is type: ";
		if (i % 2 == 0)
			identify(b[i]);
		else
			identify(*b[i]);
	}
	return 0;
}
