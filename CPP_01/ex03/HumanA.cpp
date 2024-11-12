/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:04:33 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 11:20:09 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& weaponName) : weaponA(weaponName)
{
	this->name = humanName;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	if (this->weaponA.getType() != "")
		std::cout << this->name << " attack with their " << this->weaponA.getType() << std::endl;
	else
		std::cout << this->name << " attack with *nothing*" << std::endl;
}