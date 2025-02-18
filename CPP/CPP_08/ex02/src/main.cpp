/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:09:07 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/18 15:07:26 by aduvilla         ###   ########.fr       */
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

	std::cout << "top element: " << mstack.top() << " (should be 17)\n";

	mstack.pop();

	std::cout << "size after pop: " << mstack.size() << " (should be 1)\n";
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	std::cout << *it << "\n";
	--it;
	std::cout << *it << "\n";
	std::cout << "\nBottom of the stack (should be 5)\n";
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
	std::cout << "Top of the stack (should be 0)\n\n";

	MutantStack<std::string, std::vector<std::string> >	strStack;
	strStack.push("Hello");
	strStack.push("World!");

	std::cout << "Dislplay strStack:\n";
	MutantStack<std::string, std::vector<std::string> >::iterator strit = strStack.begin();
	std::cout << *strit << "\n";
	++strit;
	std::cout << *strit << "\n";

	std::cout << "\nDislplay copy:\n";
	MutantStack<std::string, std::vector<std::string> > strcopy;
	strcopy = strStack;
	for (MutantStack<std::string, std::vector<std::string> >::iterator beg = strcopy.begin(); beg != strcopy.end(); ++beg)
		std::cout << *beg << "\n";
	return 0;
}
