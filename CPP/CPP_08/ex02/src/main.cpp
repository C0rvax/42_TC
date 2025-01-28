/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:09:07 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 15:52:33 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size after pop: " << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	std::cout << "Bottom of the stack (should be 5)" << std::endl;
	while (it != ite)
	{
		if (it == mstack.begin())
			std::cout << "    T     " << *it << std::endl;
		else if (it == mstack.end() - 1)
			std::cout << "    V     " << *it << std::endl;
		else
			std::cout << "    |     " << *it << std::endl;
		++it;
	}
	std::cout << "Top of the stack (should be 0)" << std::endl;
	std::cout << std::endl;

	MutantStack<std::string, std::vector<std::string> >	strStack;
	strStack.push("Hello");
	strStack.push("World!");

	MutantStack<std::string, std::vector<std::string> >::iterator strit = strStack.begin();
	std::cout << *strit << std::endl;
	++strit;
	std::cout << *strit << std::endl;
	return 0;
}
