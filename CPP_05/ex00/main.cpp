/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:17:25 by afont             #+#    #+#             */
/*   Updated: 2024/08/30 08:49:17 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bob("bob", 150);
		std::cout << bob;
		while (bob.getGrade() > 1)
		{
			bob.incrementGrade();
			std::cout << bob;
		}
		bob.incrementGrade();
		std::cout << bob;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}