/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:41:49 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 09:44:21 by afont            ###   ########.fr       */
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
	int	i = -1;

	while (++i < 100)
		this->_ideas[i] = src._ideas[i];
}

void	Brain::getIdeas(int i) const
{
	std::cout << this->_ideas[i] << std::endl;
}