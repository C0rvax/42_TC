/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:26:51 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 16:29:22 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base*	generte()
{
	int random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		case 2:
			return (new C);
			break;
	}
	return NULL;
}

void	identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentified" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	}
	catch (const std::exception & e)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
	}
	catch (const std::exception & e)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
	}
	catch (const std::exception & e)
	{
	}
}
