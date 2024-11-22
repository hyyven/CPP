/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:27:55 by afont             #+#    #+#             */
/*   Updated: 2024/11/18 09:57:00 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_HitPoint = 10;
	this->_EnergyPoint = 10;
	this->_AttackDamage = 0;
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_HitPoint = other._HitPoint;
	this->_EnergyPoint = other._EnergyPoint;
	this->_AttackDamage = other._AttackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint == 0 || this->_HitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack" << std::endl;
		return ;
	}
	this->_EnergyPoint--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	amount_save = amount;
	
	if (this->_HitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	while (amount-- && this->_HitPoint != 0)
		this->_HitPoint--;
	if (this->_HitPoint == 0)
		std::cout << "ClapTrap " << this->_name << " is dead by taking " << amount_save << " hit points" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " took " << amount_save << " points of damage and now has " << this->_HitPoint << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	amount_save = amount;
	
	if (this->_EnergyPoint == 0 || this->_HitPoint == UINT_MAX || amount == 0)
	{
		std::cout << this->_name << " can't be repaired" << std::endl;
		return ;
	}
	this->_EnergyPoint--;
	while (amount-- && this->_HitPoint != UINT_MAX)
		this->_HitPoint++;
	std::cout << "ClapTrap " << this->_name << " has been repaired by " << amount_save << " and now has " << this->_HitPoint << " hit points" << std::endl;
}