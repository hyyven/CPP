/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/13 14:13:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "<" << this->_type << "> dog created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "<" << this->_type << "> dog destructed" << std::endl;
}

Dog::Dog(Dog const &src) : Animal()
{
	*this = src;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}