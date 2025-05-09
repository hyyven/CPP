/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:42 by afont             #+#    #+#             */
/*   Updated: 2025/04/17 14:42:43 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& src) 
{
    *this = src;
}

PmergeMe::~PmergeMe() 
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs) 
    {
        _deque = rhs._deque;
        _list = rhs._list;
        _original = rhs._original;
        _dequeStart = rhs._dequeStart;
        _dequeEnd = rhs._dequeEnd;
        _listStart = rhs._listStart;
        _listEnd = rhs._listEnd;
    }
    return *this;
}

void PmergeMe::parseArguments(int argc, char **argv) 
{
    int i = 1;
    int num;
    std::string arg;
    std::istringstream iss;

    if (argc < 2) 
    {
        throw std::runtime_error("Error: No arguments provided.");
    }
    
    while (i < argc) 
    {
        arg = argv[i];
        std::istringstream iss(arg);
        
        if (!(iss >> num) || !iss.eof() || num <= 0) 
        {
            throw std::runtime_error("Error: Invalid argument: " + arg);
        }
        
        if (num > INT_MAX) 
        {
            throw std::runtime_error("Error: Number too large: " + arg);
        }
        _original.push_back(num);
        i++;
    }
}

void PmergeMe::sortAndMeasure() 
{
    _deque.assign(_original.begin(), _original.end());
    _list.assign(_original.begin(), _original.end());
    
    gettimeofday(&_dequeStart, NULL);
    fordJohnsonSortDeque(_deque, 0, _deque.size() - 1);
    gettimeofday(&_dequeEnd, NULL);

    gettimeofday(&_listStart, NULL);
    fordJohnsonSortList(_list);
    gettimeofday(&_listEnd, NULL);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr, int left, int right) 
{
    int mid;

    if (right - left <= 10) 
    {
        insertionSortDeque(arr, left, right);
    } 
    else 
    {
        mid = left + (right - left) / 2;
        fordJohnsonSortDeque(arr, left, mid);
        fordJohnsonSortDeque(arr, mid + 1, right);
        mergeDeque(arr, left, mid, right);
    }
}

void PmergeMe::mergeSortDeque(std::deque<int>& arr, int left, int right) 
{
    int mid;

    if (left < right) 
    {
        mid = left + (right - left) / 2;
        mergeSortDeque(arr, left, mid);
        mergeSortDeque(arr, mid + 1, right);
        mergeDeque(arr, left, mid, right);
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<int> L(n1), R(n2);
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1)
    {
        L[i] = arr[left + i];
        i++;
    }
    
    while (j < n2)
    {
        R[j] = arr[mid + 1 + j];
        j++;
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) 
{
    int i = left + 1;
    int key;
    int j;

    while (i <= right) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst) 
{
    std::list<int> left, right;
    std::list<int>::iterator it;
    int i;
    int mid;

    if (lst.size() <= 10) 
    {
        insertionSortList(lst);
    } 
    else 
    {
        it = lst.begin();
        mid = lst.size() / 2;
        i = 0;
        
        while (i < mid)
        {
            left.push_back(*it++);
            i++;
        }
        
        while (it != lst.end())
            right.push_back(*it++);
            
        fordJohnsonSortList(left);
        fordJohnsonSortList(right);
        lst = mergeList(left, right);
    }
}

void PmergeMe::mergeSortList(std::list<int>& lst) 
{
    std::list<int> left, right;
    std::list<int>::iterator it;
    int i;
    int mid;

    if (lst.size() <= 1)
        return;
        
    it = lst.begin();
    mid = lst.size() / 2;
    i = 0;
    
    while (i < mid)
    {
        left.push_back(*it++);
        i++;
    }
    
    while (it != lst.end())
        right.push_back(*it++);
        
    mergeSortList(left);
    mergeSortList(right);
    lst = mergeList(left, right);
}

std::list<int> PmergeMe::mergeList(std::list<int>& left, std::list<int>& right) 
{
    std::list<int> result;
    
    while (!left.empty() && !right.empty()) 
    {
        if (left.front() <= right.front()) 
        {
            result.push_back(left.front());
            left.pop_front();
        } 
        else 
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) 
    {
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) 
    {
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

void PmergeMe::insertionSortList(std::list<int>& lst) 
{
    std::list<int> sorted;

    if (lst.size() <= 1)
        return;
    while (!lst.empty()) 
    {
        int val = lst.front();
        lst.pop_front();
        std::list<int>::iterator it = sorted.begin();
        while (it != sorted.end() && *it < val)
            ++it;
        sorted.insert(it, val);
    }
    lst = sorted;
}

void PmergeMe::displaySequence(const std::deque<int>& arr) const 
{
    std::deque<int>::const_iterator it = arr.begin();
    
    while (it != arr.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::list<int>& lst) const 
{
    std::list<int>::const_iterator it = lst.begin();
    
    while (it != lst.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void PmergeMe::displayResults() const 
{
    std::cout << "Before: ";
    displaySequence(_original);
    std::cout << "After:  ";
    displaySequence(_deque);
    
    long dequeTime = ((_dequeEnd.tv_sec - _dequeStart.tv_sec) * 1000000) + (_dequeEnd.tv_usec - _dequeStart.tv_usec);
    long listTime = ((_listEnd.tv_sec - _listStart.tv_sec) * 1000000) + (_listEnd.tv_usec - _listStart.tv_usec);
    
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << static_cast<double>(dequeTime) << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << static_cast<double>(listTime) << " us" << std::endl;
}