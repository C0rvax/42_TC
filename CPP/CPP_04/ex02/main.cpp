/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:05:52 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:13 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Cat*		a = new Cat();
	AAnimal*	b = new Dog();
//	AAnimal*	c = new AAnimal();
//	AAnimal		d;

	std::cout << std::endl;
	b->makeSound();
	a->makeSound();
	delete a;
	delete b;
}
