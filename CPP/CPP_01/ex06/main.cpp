/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:39:38 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 16:40:44 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl	harl;

    harl.complain("DEBUG");
	std::cout << std::endl;
    harl.complain("INFO");
	std::cout << std::endl;
    harl.complain("WARNING");
	std::cout << std::endl;
    harl.complain("ERROR");
	std::cout << std::endl;
    harl.complain("DEBUGI");
	std::cout << std::endl;
    harl.complain("INFOA");
	std::cout << std::endl;
    harl.complain("WARNINGU");
	std::cout << std::endl;
    harl.complain("ERRORO");

    return 0;
}
