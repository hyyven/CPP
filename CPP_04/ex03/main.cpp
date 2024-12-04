/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:18:00 by afont             #+#    #+#             */
/*   Updated: 2024/12/04 09:34:40 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);


	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// me->showInv();
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// me->showInv();
	// tmp = src->createMateria("test1");
	// me->equip(tmp);
	// me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// me->showInv();

	// me->use(0, *bob);
	// me->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	// me->unequip(0);
	// me->use(0, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}