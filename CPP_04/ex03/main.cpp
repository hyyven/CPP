/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:18:00 by afont             #+#    #+#             */
/*   Updated: 2024/12/17 11:32:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "--test basic--" << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	

	// std::cout << "--test learn--" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// Ice *tmp = new Ice();
	// src->learnMateria(tmp);
	// Cure *tmp2 = new Cure();
	// src->learnMateria(tmp2);
	// delete tmp;
	// delete tmp2;
	// delete src;
	

	// std::cout << "--test equip, use--" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// ICharacter* me = new Character("me");
	// ICharacter* bob = new Character("bob");
	// AMateria* tmp;
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// // me->showInv();
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// // me->showInv();
	// tmp = src->createMateria("test1");
	// me->equip(tmp);
	// // me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// // me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// // me->showInv();
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// // me->showInv();
	// me->use(0, *bob);
	// me->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	// delete src;
	// delete bob;
	// delete tmp;
	// delete me;


	// std::cout << "--test unequip--" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// ICharacter* me = new Character("me");
	// ICharacter* bob = new Character("bob");
	// src->learnMateria(new Ice());
	// AMateria *tmp = src->createMateria("ice");
	// AMateria *unequiped = tmp;
	// me->equip(tmp);
	// me->unequip(0);
	// me->use(0, *bob);
	// me->equip(unequiped);
	// me->use(0, *bob);
	// delete src;
	// delete bob;
	// delete me;


	// std::cout << "--test deep copy--" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// AMateria *tmp = src->createMateria("ice");
	// Character *c = new Character("c");
	// c->equip(tmp);
	// Character *c2 = new Character(*c);
	// c->use(0, *c2);
	// c2->use(0, *c2);
	// delete c;
	// c2->use(0, *c2);
	// delete c2;
	// delete src;
	
	return 0;
}