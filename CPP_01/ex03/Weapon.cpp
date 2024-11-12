/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:43:07 by afont             #+#    #+#             */
/*   Updated: 2024/04/11 11:58:28 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName)
{
	this->setType(weaponName);
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string weaponName)
{
	this->type = weaponName;
}