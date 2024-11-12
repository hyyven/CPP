/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:04:50 by afont             #+#    #+#             */
/*   Updated: 2024/04/08 12:11:11 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}
	
Zombie::~Zombie()
{
	std::cout << this->Name << "> no BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->Name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->Name = name;
}
