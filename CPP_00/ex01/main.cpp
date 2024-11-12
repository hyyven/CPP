/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:50:22 by afont             #+#    #+#             */
/*   Updated: 2024/08/07 14:40:03 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string line = "";
	
	std::cout << "> ";
	while (std::getline(std::cin, line))
	{
		if (line.compare("EXIT") == 0)
			return (0);
		else if (line.compare("ADD") == 0)
			phonebook.AddContact();
		else if (line.compare("SEARCH") == 0)
		{
			phonebook.DisplayAll();
			phonebook.SearchContact();
		}
		if (!std::cin.eof())
			std::cout << "> ";
	}
	return (0);
}
