/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:51 by afont             #+#    #+#             */
/*   Updated: 2025/04/17 14:42:52 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
	{
        PmergeMe pmm;
        pmm.parseArguments(argc, argv);
        pmm.sortAndMeasure();
        pmm.displayResults();
        return 0;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
