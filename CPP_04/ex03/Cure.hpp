/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:02:18 by afont             #+#    #+#             */
/*   Updated: 2024/12/17 09:44:51 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &other);
		Cure	&operator=(Cure const &other);
		~Cure(void);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);	
};