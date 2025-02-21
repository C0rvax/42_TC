/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:15:43 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/21 11:41:09 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (i = 1; i < ac; i++)
		{
			for (j = 0; av[i][j]; j++)
				std::cout << (char)std::toupper(av[i][j]);
			std::cout << ' ';
		}
		std::cout << "\n";
	}
	return 0;
}
