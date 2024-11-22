/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:45:04 by afont             #+#    #+#             */
/*   Updated: 2024/11/21 13:46:38 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
}

Base	*generate(void)
{
	srand(time(0));
	int	ran = rand() % 3;
	// std::cout << ran << std::endl;
	if (ran == 0)
		return (new A);
	if (ran == 1)
		return (new B);
	if (ran == 2)
		return (new C);
	std::cout << "random fail" << std::endl;
	return (new Base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	identify(&p);	
}