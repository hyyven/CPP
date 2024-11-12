/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:57:07 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 11:04:36 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// Zombie 1
	Zombie	*wsh = newZombie("LaRueLaVrai");
	wsh->announce();
	delete wsh;

	// Zombie 2
	Zombie	Ue("Ue");
	Ue.announce();

	// Zombie 3
	randomChump("random");
}