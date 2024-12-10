/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:14:28 by afont             #+#    #+#             */
/*   Updated: 2024/12/10 12:14:36 by afont            ###   ########.fr       */
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
	this->_type = src.getType();
}