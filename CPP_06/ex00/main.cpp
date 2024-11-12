/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:31 by afont             #+#    #+#             */
/*   Updated: 2024/09/04 16:05:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		ScalarConverter converter = ScalarConverter::create(argv[1]);
		converter.convert();
	}
}
