/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:36:12 by afont             #+#    #+#             */
/*   Updated: 2024/12/10 12:25:37 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "<" << this->_type << "> cat created" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "<" << this->_type << "> cat destructed" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}