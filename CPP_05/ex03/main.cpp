/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:17:25 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 14:20:51 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RRF.hpp"
#include "SCF.hpp"
#include "PPF.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern  someRandomIntern;
		AForm*   rrf;

		rrf = someRandomIntern.makeForm("PPF", "Bender");
		// rrf = someRandomIntern.makeForm("RRF", "Bender");
		// rrf = someRandomIntern.makeForm("SCF", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("asdasd", "Bender");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}