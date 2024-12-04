/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:56 by afont             #+#    #+#             */
/*   Updated: 2024/12/04 09:48:51 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array();
		T &operator[](unsigned int i);
		unsigned int size() const;
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Error: Out of range"; };
		};
};

#include "Array.tpp"