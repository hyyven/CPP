/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:41:49 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:19:14 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int	i = -1;

	while (++i < 100)
		this->_ideas[i] = "empty";
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	int	i = -1;

	if (this != &rhs)
		while (++i < 100)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}
