/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:11:45 by afont             #+#    #+#             */
/*   Updated: 2024/10/14 11:24:38 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileData.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		file	_file = file(argv[1], argv[2], argv[3]);
		_file.replace();
	}
	std::cout << "invalid param : <filename> <str_to_replace> <str_replacing>" << std::endl;
	return (0);
}