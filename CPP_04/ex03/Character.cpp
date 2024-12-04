/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:54 by afont             #+#    #+#             */
/*   Updated: 2024/12/02 12:10:21 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	int	i = -1;

	while (++i < 4)
		_inventory[i] = NULL;
}

Character::Character(Character const &other) : _name(other._name)
{
	int	i = -1;

	while (++i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	int	i = -1;

	while (++i < 4)
		if (_inventory[i])
			delete _inventory[i];
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	int	i = -1;
	
	if (!m)
	{
		std::cout << "Materia is null" << std::endl;
		return ;
	}
	while (++i < 4)
	{
		if (!_inventory[i])
		{
			std::cout << "?";
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Can't equip more materia" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout << "nothing to use" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

void	Character::showInv(void)
{
	int	i = -1;

	while (++i < 3)
		std::cout << this->_inventory[i] << ", ";
	std::cout << this->_inventory[i] << std::endl;
}