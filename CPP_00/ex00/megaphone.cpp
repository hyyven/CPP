/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:55:36 by afont             #+#    #+#             */
/*   Updated: 2024/04/06 09:55:36 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i = 0;
	size_t	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while (++i < argc)
		{
			std::string str = std::string(argv[i]);
			j = -1;
			while (++j < str.length())
				std::cout << (char)toupper(str[j]);
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << "\n";
	}
	return (0);
}
