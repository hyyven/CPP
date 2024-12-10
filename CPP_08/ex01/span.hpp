/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:49:55 by afont             #+#    #+#             */
/*   Updated: 2024/12/04 13:18:00 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits.h>
#include <cstdlib>

class Span
{
	private:
		unsigned int _n;
		int *_array;
		unsigned int _size;
	public:
		Span(unsigned int n);
		Span(Span const &other);
		Span(unsigned int min, unsigned  int max, unsigned int n);
		~Span();
		void	printArray();
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
};