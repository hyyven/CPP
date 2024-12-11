/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:32:41 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 09:58:05 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "<" << this->_type << "> wrong cat created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "<" << this->_type << "> wrong cat destructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	this->_type = src._type;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*Wrong cat noise*" << std::endl;
}