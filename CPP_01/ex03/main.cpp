/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:54:36 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 11:21:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon uee = Weapon("la rue hein");
	HumanA bob("bob", uee);
	bob.attack();
	uee.setType("");
	bob.attack();

	Weapon nono = Weapon("no jose no");
	HumanB jim("jim");
	jim.attack();
	jim.setWeapon(nono);
	jim.attack();
	nono.setType("a");
	jim.attack();
}