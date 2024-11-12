/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:17:25 by afont             #+#    #+#             */
/*   Updated: 2024/08/30 12:09:31 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bob("bob", 2);
		std::cout << bob;
		Form		mia("mia", 1, 149);
		std::cout << mia;
		bob.incrementGrade();
		bob.signForm(mia);
		std::cout << mia;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}