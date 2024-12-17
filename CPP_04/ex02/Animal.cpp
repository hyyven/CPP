/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:22:38 by afont            ###   ########.fr       */
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

Animal::Animal(const Animal &src)
{
	*this = src;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*animal noise*" << std::endl;
}