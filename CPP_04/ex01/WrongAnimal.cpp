/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:29:16 by afont             #+#    #+#             */
/*   Updated: 2024/04/25 10:59:40 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "<" << this->_type << "> wrong animal created" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "<" << this->_type << "> wrong animal destructed" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::string	tmp = this->getType();
	if (tmp == "WrongAnimal")
		std::cout << "*wrong animal noise*" << std::endl;
	else if (tmp == "WrongCat")
		std::cout << "wsh" << std::endl;
}