/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/10 12:27:02 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "<" << this->_type << "> dog created" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "<" << this->_type << "> dog destructed" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf" << std::endl;
}