/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:05:52 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:07:43 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal*	animal = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << " is a dog" << std::endl;
	std::cout << cat->getType() << " is a cat" << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();

	delete dog;
	delete cat;
	delete animal;
	
	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrong = new WrongCat();

	std::cout << wrong->getType() << " is a wrong cat" << std::endl;
	wrong->makeSound();
	wrongAnimal->makeSound();

	delete wrong;
	delete wrongAnimal;
}
