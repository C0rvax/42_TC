/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:05:52 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/16 11:42:08 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal*	ark[10];

	for (int i = 0; i < 5; i++)
		ark[i] = new Cat();
	for (int i = 5; i < 10; i++)
		ark[i] = new Dog();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		ark[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete ark[i];

	std::cout << std::endl;
	std::cout << "BRAIN TEST" << std::endl;
	Cat	a;
	Cat	b;

	std::cout << std::endl;
	a.getBrain()->setIdea("Eat", 0);
	a.getBrain()->setIdea("Sleep", 1);
	std::cout << "a 1st idea: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "a 2nd idea: " << a.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << "b 1st idea: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "b 2nd idea: " << b.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	b = a;
	std::cout << std::endl;
	std::cout << "b 1st idea: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "b 2nd idea: " << b.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	a.getBrain()->setIdea("Run", 0);
	a.getBrain()->setIdea("Jump", 1);
	std::cout << "a 1st idea: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "a 2nd idea: " << a.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << "b 1st idea: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "b 2nd idea: " << b.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
}
