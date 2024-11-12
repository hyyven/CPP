/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:06:59 by afont             #+#    #+#             */
/*   Updated: 2024/04/25 11:51:19 by afont            ###   ########.fr       */
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
	int				k = 40;
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
}