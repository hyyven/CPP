/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:01:20 by afont             #+#    #+#             */
/*   Updated: 2024/11/21 12:30:47 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"
// #include <cstdint>
#include <iostream>

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(Serializer const &other);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};