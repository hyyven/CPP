/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:46:24 by afont             #+#    #+#             */
/*   Updated: 2024/08/07 15:20:13 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::DisplayAll(void)
{
	int i = -1;

	while (++i < 8 && !contacts[i].IsEmpty())
		contacts[i].Glimpse(i);
}

void	PhoneBook::SearchContact(void)
{
	int index = 0;
	std::string index_str;

	if (!std::cin.eof())
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, index_str);
	}
	if (index_str.length() == 1 && index_str[0] >= '0' && index_str[0] <= '7')
	{
		index = index_str[0] - '0';
		if (!contacts[index].IsEmpty())
			contacts[index].DisplayOne(index);
		else
			std::cout << "Contact not found\n";
	}
	else if (!index_str.empty())
		std::cout << "Invalid index\n";
}

void	PhoneBook::AddContact(void)
{
	static int	i;

	if (this->contacts[i % 8].Init())
		i++;
}