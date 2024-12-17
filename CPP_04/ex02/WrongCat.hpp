/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:31:56 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:22:27 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private:
		
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &rhs);
		void	makeSound(void) const;
};

#endif