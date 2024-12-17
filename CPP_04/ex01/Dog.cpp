/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/13 14:17:09 by afont            ###   ########.fr       */
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
	*this = src;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}