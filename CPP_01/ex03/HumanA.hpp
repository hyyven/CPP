/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:57:59 by afont             #+#    #+#             */
/*   Updated: 2024/04/11 10:40:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weaponA;
	public:
		HumanA(std::string humanName, Weapon& weaponName);
		~HumanA();
		void	attack();
};