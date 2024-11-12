/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:09:12 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 11:30:42 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "SCF.hpp"
#include "RRF.hpp"
#include "PPF.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm		*forms[3] = {new SCF(target), new RRF(target), new PPF(target)};
	std::string	formsNames[3] = {"SCF", "RRF", "PPF"};
	int			i = -1;

	while (++i < 3)
	{
		if (formsNames[i] == name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (forms[i]);
		}
		delete forms[i];
	}
	std::cout << "Form " << name << " doesn't exist" << std::endl;
	return (NULL);
}
