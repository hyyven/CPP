/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:36:01 by afont             #+#    #+#             */
/*   Updated: 2024/04/11 11:58:49 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
{
	this->name = humanName;
	this->weaponB = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (this->weaponB != NULL && this->weaponB->getType() != "")
		std::cout << this->name << " attack with their " << this->weaponB->getType() << std::endl;
	else
		std::cout << this->name << " attack with *nothing* " << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponName)
{
	this->weaponB = &weaponName;
}