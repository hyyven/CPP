/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:49 by afont             #+#    #+#             */
/*   Updated: 2025/04/17 14:42:50 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <deque>
# include <list>
# include <string>
# include <sstream>
# include <iomanip>
# include <climits>
# include <sys/time.h>

class PmergeMe 
{
	private:
		std::deque<int> _deque;
		std::list<int> _list;
		std::deque<int> _original; 
		struct timeval _dequeStart, _dequeEnd;
		struct timeval _listStart, _listEnd;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& rhs);
		void mergeSortDeque(std::deque<int>& arr, int left, int right);
		void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
		void insertionSortDeque(std::deque<int>& arr, int left, int right);
		void fordJohnsonSortDeque(std::deque<int>& arr, int left, int right);
		void mergeSortList(std::list<int>& lst);
		void insertionSortList(std::list<int>& lst);
		void fordJohnsonSortList(std::list<int>& lst);
		void displaySequence(const std::deque<int>& arr) const;
		void displaySequence(const std::list<int>& lst) const;
		void parseArguments(int argc, char **argv);
		void sortAndMeasure();
		void displayResults() const;
		std::list<int> mergeList(std::list<int>& left, std::list<int>& right);
};

#endif