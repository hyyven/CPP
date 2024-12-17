/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:06:59 by afont             #+#    #+#             */
/*   Updated: 2024/12/13 14:17:28 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();
	
	delete i;
	delete j;

	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	int				k = 4;
	int				l = -1;
	const Animal	*animal_list[k];
	while (++l < k/2)
		animal_list[l] = new Cat();
	l--;
	while (++l < k)
		animal_list[l] = new Dog();
	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	l = -1;
	while (++l < k)
		delete animal_list[l];
	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	const WrongAnimal	*wrong_j = new WrongAnimal();
	const WrongAnimal	*wrong_i = new WrongCat();
	wrong_i->makeSound();
	wrong_j->makeSound();
	delete wrong_i;
	delete wrong_j;
	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	const Dog *deep_cp1 = new Dog();
	const Dog *deep_cp2 = new Dog(*deep_cp1);
	std::cout << deep_cp1->getType() << std::endl;
	delete deep_cp1;
	std::cout << deep_cp2->getType() << std::endl;
}