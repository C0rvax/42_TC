/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:00:48 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/16 11:59:50 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // no leaks when adding too much materia

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	Character* t1 = new Character("arnold");
	Character*	t2 = new Character(*t1);

	tmp = src->createMateria("cure");
	t1->equip(tmp);
	tmp = src->createMateria("ice");
	t1->equip(tmp);
	tmp = src->createMateria("ice");
	t1->equip(tmp);
	tmp = src->createMateria("ice");
	t1->equip(tmp);
	tmp = src->createMateria("cure"); // no leaks when adding too much materia
	t1->equip(tmp);
	std::cout << "t1 use materia in slot 0: ";
	t1->use(0, *bob);
	std::cout << std::endl;
	std::cout << "t2 use materia in slot 0: ";
	t2->use(0, *bob); // should display nothing
	std::cout << std::endl;
	std::cout << std::endl;

	Character*	t3 = new Character(*t1);

	std::cout << "t3 use materia in slot 0: ";
	t3->use(0, *bob); // should display the same materia in t1 slot 0
	std::cout << "t3 use materia in slot 1: ";
	t3->use(1, *bob); // should display the same materia in t1 slot 1
	t3->unequip(0);
	std::cout << "t3 use materia in slot 0: ";
	t3->use(0, *bob); // should display nothing (slot 0 unequiped)
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	delete t1;
	delete t2;
	delete t3;
	Character::deleteFloor();

	return 0;
}
