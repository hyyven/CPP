/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:26 by afont             #+#    #+#             */
/*   Updated: 2024/04/08 12:10:25 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string	Name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie  *newZombie( std::string name );
void	randomChump(std::string name);

#endif