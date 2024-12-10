/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:50:00 by afont             #+#    #+#             */
/*   Updated: 2024/12/04 13:19:50 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : _n(n), _array(new int[n]), _size(0)
{
}

Span::Span(Span const &other) : _n(other._n), _array(new int[other._n]), _size(other._size)
{
	unsigned int	i = 0;

	while (i < _n)
	{
		_array[i] = other._array[i];
		i++;
	}
}

Span::Span(unsigned int min, unsigned int max, unsigned int n) : _n(n), _array(new int[n]), _size(0)
{
	unsigned int	i = 0;

	srand (time(NULL));
	if (min > max || min == max)
		throw std::runtime_error("min must be less than max");
	while (i < _n)
	{
		_array[i++] = rand() % (max - min + 1) + min;
		_size++;
	}
}

Span::~Span()
{
	delete[] _array;
}

void	Span::addNumber(int number)
{
	static unsigned int	i = 0;

	if (i >= _n)
		throw std::runtime_error("array is full");
	_array[i++] = number;
	_size++;
}

int	Span::shortestSpan()
{
	int				span = INT_MAX;
	unsigned int	i = 0;
	unsigned int	j;
	
	if (_size < 2)
		throw std::runtime_error("array is too small");
	while (i < _n)
	{
		j = i + 1;
		while (j < _n)
		{
			if (abs(_array[i] - _array[j]) < span)
				span = abs(_array[i] - _array[j]);
			j++;
		}
		i++;
	}
	return (span);
}

int	Span::longestSpan()
{
	int				span = 0;
	unsigned int	i = 0;
	unsigned int	j;

	if (_size < 2)
		throw std::runtime_error("Array is too small");
	while (i < _n)
	{
		j = i + 1;
		while (j < _n)
		{
			if (abs(_array[i] - _array[j]) > span)
				span = abs(_array[i] - _array[j]);
			j++;
		}
		i++;
	}
	return (span);
}

void	Span::printArray(void)
{
	unsigned int	i = 0;

	while (i < _n)
		std::cout << _array[i++] << " ";
	std::cout << std::endl;
}
