/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/04/25 12:02:38 by afont            ###   ########.fr       */
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

void	Dog::makeSound(void) const
{
	std::cout << "Waf" << std::endl;
}