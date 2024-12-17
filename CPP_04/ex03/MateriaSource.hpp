/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:34 by afont             #+#    #+#             */
/*   Updated: 2024/12/17 09:45:26 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	IMateriaSource;

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_source[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);
		~MateriaSource(void);
		void		learnMateria(AMateria *m);
		AMateria	*getMateria(std::string const &type);
		AMateria	*createMateria(std::string const &type);
};
