/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:41:49 by afont             #+#    #+#             */
/*   Updated: 2024/12/10 12:24:51 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
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