/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:21:15 by afont             #+#    #+#             */
/*   Updated: 2024/11/21 12:34:47 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new(Data);
	data->x = 1;
	data->y = 3;
	std::cout << &data << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	std::cout << ptr << std::endl;

	data = Serializer::deserialize(ptr);
	std::cout << &data << std::endl;
	delete (data);
}