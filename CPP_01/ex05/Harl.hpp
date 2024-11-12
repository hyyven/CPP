/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:57:14 by afont             #+#    #+#             */
/*   Updated: 2024/04/16 10:56:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>
#include <string>

class	harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		std::map<std::string, void (harl::*)()> complaintFunctions;
	public:
		harl();
		~harl();
		void	complain(std::string level);
};

#endif