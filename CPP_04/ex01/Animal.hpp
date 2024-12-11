/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:58:05 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 09:55:05 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		virtual	~Animal(void);
		Animal(Animal const & src);
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif