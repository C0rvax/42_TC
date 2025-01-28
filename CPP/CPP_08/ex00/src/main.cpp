/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:39:03 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 11:49:03 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <list>

int	main()
{
	std::vector<int>	vec;
	std::list<int>		list;
	int value = 2;
	try
	{
		std::cout << "distance between begin and " << value << " in vector = " << easyfind(vec, value) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "distance between begin and " << value << " in list = " << easyfind(list, value) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(8);
		vec.push_back(16);
		list.push_back(2);
		list.push_back(4);
		list.push_back(8);
		list.push_back(16);
		std::cout << std::endl;
		std::cout << "distance between begin and " << value << " in vector = " << easyfind(vec, value) << std::endl;
		std::cout << "distance between begin and " << value << " in list = " << easyfind(list, value) << std::endl;
		value = 8;
		std::cout << std::endl;
		std::cout << "distance between begin and " << value << " in vector = " << easyfind(vec, value) << std::endl;
		std::cout << "distance between begin and " << value << " in list = " << easyfind(list, value) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
