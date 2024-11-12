/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:17:25 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:41:28 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RRF.hpp"
#include "SCF.hpp"
#include "PPF.hpp"

int main()
{
	try
	{
		Bureaucrat	bob("bob", 145);
		std::cout << bob;
		SCF ueee("ueee");
		std::cout << ueee;
		ueee.beSigned(bob);
		std::cout << ueee;
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		std::cout << bob;
		ueee.execute(bob);
		std::cout << ueee;

		std::cout << std::endl;
		std::cout << std::endl;

		Bureaucrat	jim("jim", 45);
		std::cout << jim;
		RRF oui("oui");
		std::cout << oui;
		oui.beSigned(jim);
		std::cout << oui;
		oui.execute(jim);
		
		std::cout << std::endl;
		std::cout << std::endl;

		Bureaucrat	jack("jack", 4);
		std::cout << jack;
		PPF non("non");
		std::cout << non;
		non.beSigned(jack);
		std::cout << non;
		non.execute(jack);
		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}