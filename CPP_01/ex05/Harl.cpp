/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:57:36 by afont             #+#    #+#             */
/*   Updated: 2024/08/06 15:22:01 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

harl::harl()
{
	complaintFunctions["debug"] = &harl::debug;
	complaintFunctions["info"] = &harl::info;
	complaintFunctions["warning"] = &harl::warning;
	complaintFunctions["error"] = &harl::error;
}

harl::~harl()
{
}

void	harl::debug()
{
	std::cout << "debug !" << std::endl;
}

void	harl::info()
{
	std::cout << "info !" << std::endl;
}

void	harl::warning()
{
	std::cout << "warning !" << std::endl;
}

void	harl::error()
{
	std::cout << "error !" << std::endl;
}

void harl::complain(std::string level)
{
	if (complaintFunctions.find(level) != complaintFunctions.end())
		(this->*complaintFunctions[level])();
	else
		std::cout << "Error: Invalid complaint level!" << std::endl;
}