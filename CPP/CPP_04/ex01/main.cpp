/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:05:52 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 12:18:49 by aduvilla         ###   ########.fr       */
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
	for (int i = 0; i < 10; i++)
		ark[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete ark[i];

	Cat	a;
	Cat	b;

	a.getBrain()->setIdea("Eat", 0);
	a.getBrain()->setIdea("Sleep", 1);
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;

	b = a;
	std::cout << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;

	a.getBrain()->setIdea("Eat", 1);
	a.getBrain()->setIdea("Sleep", 0);
	std::cout << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
}
