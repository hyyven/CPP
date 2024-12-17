/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:06:59 by afont             #+#    #+#             */
/*   Updated: 2024/12/13 14:13:09 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();
	
	std::cout << meta->getType() << "!" << std::endl;
	std::cout << j->getType() << "!" << std::endl;
	std::cout << i->getType() << "!" << std::endl;
	
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "////////////////////////////////////////////////////" << std::endl;

	const WrongAnimal	*wrongMeta = new WrongAnimal();
	const WrongAnimal	*wrongI = new WrongCat();

	std::cout << wrongMeta->getType() << "!" << std::endl;
	std::cout << wrongI->getType() << "!" << std::endl;

	wrongMeta->makeSound();
	wrongI->makeSound();

	delete wrongMeta;
	delete wrongI;
	std::cout << "////////////////////////////////////////////////////" << std::endl;

	const Dog *deep_cp1 = new Dog();
	const Dog *deep_cp2 = new Dog(*deep_cp1);
	std::cout << deep_cp1->getType() << std::endl;
	delete deep_cp1;
	std::cout << deep_cp2->getType() << std::endl;
}