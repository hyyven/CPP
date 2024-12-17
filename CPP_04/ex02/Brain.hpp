/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:37:09 by afont             #+#    #+#             */
/*   Updated: 2024/12/11 13:22:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &src);
		Brain	&operator=(const Brain &rhs);
		void	getIdeas(int i) const;
};

#endif