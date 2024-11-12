/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:56:11 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 11:12:28 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int			i = -1;
	int			N = 1;
	std::string	name = "Ui";
	Zombie*	horde = zombieHorde(N, name);
	
	while (++i < N)
		horde[i].announce();
	delete[] horde;
}
