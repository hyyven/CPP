/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 09:55:39 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << "<" << this->_type << "> animal created" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "<" << this->_type << "> animal destructed" << std::endl;
}

Animal::Animal(Animal const &src)
{
	this->_type = src.getType();
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::string tmp = this->getType();
	if (tmp == "Animal")
		std::cout << "*animal noise*" << std::endl;
	else if (tmp == "Cat")
		std::cout << "Miaou" << std::endl;
	else if (tmp == "Dog")
		std::cout << "Waf" << std::endl;
}