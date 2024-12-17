/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:36:12 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:16:10 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "<" << this->_type << "> cat created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "<" << this->_type << "> cat destructed" << std::endl;
}

Cat::Cat(Cat const &src) : Animal()
{
	*this = src;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}