/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:16:07 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 10:48:07 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string &Contact::GetFname(void)
{
	return (this->FirstName);
}

std::string &Contact::GetLname(void)
{
	return(this->LastName);
}

std::string &Contact::GetNname(void)
{
	return (this->NickName);
}

std::string &Contact::GetPnumber(void)
{
	return (this->PhoneNumber);
}

std::string &Contact::GetDsecret(void)
{
	return (this->DarkestSecret);
}

int	Contact::Init(void)
{
	std::string	_Contacts[5];
	
	if (!std::cin.eof())
	{
		std::cout << "First Name     :";
		std::getline(std::cin, _Contacts[0]);
	}
	if (!std::cin.eof())
	{
		std::cout << "Last Name      :";
		std::getline(std::cin, _Contacts[1]);
	}
	if (!std::cin.eof())
	{
		std::cout << "Nick Name      :";
		std::getline(std::cin, _Contacts[2]);
	}
	if (!std::cin.eof())
	{
		std::cout << "Phone Number   :";
		std::getline(std::cin, _Contacts[3]);
	}
	if (!std::cin.eof())
	{
		std::cout << "Darkest Secret :";
		std::getline(std::cin, _Contacts[4]);
	}
	if (!std::cin.eof())
	{
		if (this->OneEmpty(_Contacts))
		{
			std::cout << "Contact not added, empty line\n";
			return (0);
		}
		else
		{
			std::cout << "Contact added\n";
			return (1);
		}
	}
	return (0);
}

void	Contact::DisplayOne(int index)
{
	std::cout << "Index:          " << index << std::endl;
	std::cout << "First Name:     " << this->GetFname() << std::endl;
	std::cout << "Last Name:      " << this->GetLname() << std::endl;
	std::cout << "Nick Name:      " << this->GetNname() << std::endl;
	std::cout << "Phone Number:   " << this->GetPnumber() << std::endl;
	std::cout << "Darkest Secret: " << this->GetDsecret() << std::endl;
}

void	Contact::Glimpse(int index)
{
	std::cout << "|" << std::setw(10) << index;
	if (this->GetFname().length() > 10)
		std::cout << "|" << std::setw(9) << this->GetFname().substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << this->GetFname();
	if (this->GetLname().length() > 10)
		std::cout << "|" << std::setw(9) << this->GetLname().substr(0, 9) << ".";
	else
		std::cout << "|"<< std::setw(10) << this->GetLname();
	if (this->GetNname().length() > 10)
		std::cout << "|" << std::setw(9) << this->GetNname().substr(0, 9) << "." << "|" << std::endl;
	else
		std::cout << "|" << std::setw(10) << this->GetNname() << "|" << std::endl;
}

int	isspace_str(std::string str)
{
	int	i = -1;

	while (str[++i])
		if (!isspace(str[i]))
			return (0);
	return (1);
}

int	Contact::OneEmpty(std::string _Contacts[5])
{
	int	i = -1;

	while (++i < 5)
		if (_Contacts[i].empty() || isspace_str(_Contacts[i]))
			return (1);
	this->FirstName = _Contacts[0];
	this->LastName = _Contacts[1];
	this->NickName = _Contacts[2];
	this->PhoneNumber = _Contacts[3];
	this->DarkestSecret = _Contacts[4];
	return (0);
}

int	Contact::IsEmpty(void)
{
	if (this->GetFname().empty() && this->GetLname().empty() && this->GetNname().empty() && this->GetPnumber().empty() && this->GetDsecret().empty())
		return (1);
	return (0);
}