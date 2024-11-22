/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:40 by afont             #+#    #+#             */
/*   Updated: 2024/11/22 11:30:01 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_array = 0;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(Array const &other)
{
	int	i = -1;

	_array = new T[other._size];
	_size = other.size;
	while (++i < other._size)
		_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	int	i = -1;

	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		_size = other.size;
		while (++i < other._size)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfRangeException();
	else
		return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}