/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:03:15 by afont             #+#    #+#             */
/*   Updated: 2024/12/04 10:29:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int		main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(-1);
		l.push_back(i);
		d.push_back(i);
	}
	try
	{
		easyFind(v, -1);
		easyFind(l, 2);
		easyFind(d, 2);
		easyFind(v, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Value not found in container" << std::endl;
	}
}