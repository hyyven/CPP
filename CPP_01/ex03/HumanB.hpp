/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:33:04 by afont             #+#    #+#             */
/*   Updated: 2024/04/11 11:47:52 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weaponB;
	public:
		HumanB(std::string humanName);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weaponName);
};