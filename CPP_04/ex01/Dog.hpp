/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:13:13 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:17:41 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &rhs);
};

#endif