/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:06:59 by afont             #+#    #+#             */
/*   Updated: 2024/12/17 09:41:35 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();
	
	std::cout << j->getType() << "!" << std::endl;
	std::cout << i->getType() << "!" << std::endl;
	
	i->makeSound();
	j->makeSound();
	
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
	const WrongAnimal	*wrong = new WrongAnimal();
	wrong->makeSound();
	delete wrong;
	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	const WrongAnimal *wrong2 = new WrongCat();
	wrong2->makeSound();
	delete wrong2;
	std::cout << "////////////////////////////////////////////////////////////" << std::endl;
	Dog *deep_cp1 = new Dog();
	Dog *deep_cp2 = new Dog(*deep_cp1);
	deep_cp2->getIdeas(0);
	Dog *deep_cp3 = new Dog(*deep_cp2);
	deep_cp3->getIdeas(0);
	delete deep_cp1;
	deep_cp2->getIdeas(0);
	delete deep_cp2;
	deep_cp3->getIdeas(0);
	delete deep_cp3;
}