/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:36 by afont             #+#    #+#             */
/*   Updated: 2024/12/10 10:20:17 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const & src) : std::stack<T>(src) {}
		virtual ~MutantStack() {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};