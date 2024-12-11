/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 09:53:47 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "<" << this->_type << "> dog created" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
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

void	Dog::getIdeas(int i) const
{
	this->_brain->getIdeas(i);
}