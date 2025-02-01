/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:12 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/01 17:49:45 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>
#include <list>
#include <ctime>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & src) { *this = src; }

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		m_vector = rhs.m_vector;
		m_list = rhs.m_list;	
	}
	return *this;
}

PmergeMe::~PmergeMe	(void) {}

void	PmergeMe::displayVec() const
{
	for (size_t i = 0; i < m_vector.size(); ++i)
		std::cout << m_vector[i] << (i < m_vector.size() - 1 ? " " : "");
	std::cout << std::endl;
}

void	printVec(const std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
	std::cout << std::endl;
}

void	PmergeMe::displayList() const
{
	for (std::list<int>::const_iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		if (it != m_list.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::initParam(const int& ac, char** av)
{
	if (ac < 2)
		throw std::runtime_error("Error: Usage: ./PmergeMe {list of positive integer}");
	int	i = 1;
	for (; i < ac; ++i)
	{
		long	number = std::atol(av[i]);
		if (number < 0)
			throw std::runtime_error("Error: negative number");
		if (number > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: too big number");
		if (std::find(m_vector.begin(), m_vector.end(), static_cast<int>(number)) != m_vector.end())
			throw std::runtime_error("Error: duplicate numbers");
		m_vector.push_back(number);
		m_list.push_back(number);
	}
	m_isOdd = --i % 2;
}

// Fonction personnalisée upper_bound_step
std::vector<int>::iterator upper_bound_step(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, size_t step)
{
    std::vector<int>::iterator it;
    std::iterator_traits<std::vector<int>::iterator>::difference_type count, half;
    count = std::distance(first, last) + 1;

    while (count > 0)
	{
		it = first;
		half = count / (2 * step);
		std::advance(it, half * step);
		if (*it <= value)
		{
			first = it;
			std::advance(first, step);
			count -= (half * step) + step;
		}
		else
			count = half * step;
	}
	if (*first < value)
//	if (*first < value && first != last)
		first++;
	return first - step + 1;
}

long	getJacob(int n)
{
//	return round((pow(2, n + 1) + pow(-1, n)) / 3);
	return round((pow(2, n) - pow(-1, n)) / 3);
}
/*
size_t	getJacob(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacob(n - 1) + 2 * getJacob(n - 2);
}
*/

void	PmergeMe::mergePendVec(std::vector<int>& main, std::vector<int>& pend, size_t& pairSize)
{
	if (pend.size() / pairSize < 2)
		main.insert(upper_bound_step(main.begin() + pairSize - 1, main.end() - 1, *(pend.begin() + pairSize - 1), pairSize), pend.begin(), pend.end());
		//		main.insert(upper_bound_step(main.begin() + pairSize - 1, main.end(), *(pend.begin() + pairSize - 1), pairSize) - pairSize + 1, pend.begin(), pend.end());
	else
	{
		int	jacob = 3;
		int	level = 0;
		while (!pend.empty())
		{
			long nbElement = getJacob(jacob) - getJacob(jacob - 1);
			nbElement = std::min(nbElement, static_cast<long>(pend.size()) / static_cast<long>(pairSize));
			for (long i = 0; i < nbElement; ++i)
			{
				std::vector<int>::iterator bound;
//				if (10000 <= main.size())
				if (((getJacob(jacob + level + 20) - i) * pairSize + pairSize - 1) <= main.size())
					bound = main.begin() + ((getJacob(jacob + level + 3) - i) * pairSize + pairSize - 1);
				else
					bound = main.end() - 1;
//				size_t	limit = (getJacob(jacob + level + pairSize) + pairSize + 100) * pairSize;
//				std::vector<int>::iterator	bound = limit <= main.size() ? main.begin() + limit - 1 : main.end() - 1;
//				std::vector<int>::iterator bound = main.end() -1;
				std::vector<int>::iterator	element = pend.begin() + ((nbElement - i) * pairSize) - 1;
				std::vector<int>::iterator insertPoint = upper_bound_step(main.begin() + pairSize - 1, bound, *element, pairSize);
//				if (*(insertPoint + pairSize - 1) < *element)
//					insertPoint = main.end();
				//				main.insert(stop, *element);
				main.insert(insertPoint, element - pairSize + 1, element + 1);
				for (size_t i = 0; i < pairSize; ++i)
					pend.erase(element - i);
				level++;
			}
			jacob++;
		}
	}
}
/*
		size_t jc = 3; // Start with the 3rd Jacobsthal number
		size_t count = 0;
		size_t idx;
		size_t decrease;

		// Sort 'pend' into 'main' using binary search 'upper_bound' with Jacobsthal as optimization.
		while (!pend.empty()) {
			idx = getJacob(jc) - getJacob(jc - 1);
			if (idx > pend.size())
				idx = pend.size();

			decrease = 0;
			while (idx) {
				// Determine the insertion point based on the Jacobsthal index and insert the element.
				std::vector<int>::iterator end = main.begin();
				if (getJacob(jc + count) - decrease <= main.size())
					end = main.begin() + getJacob(jc + count) - decrease;
				else
					end = main.end();
				// Binary sort
				end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
				main.insert(end, *(pend.begin() + idx - 1));
				pend.erase(pend.begin() + idx - 1);

				idx--;
				decrease++;
				count++;
			}
			jc++;
		}
	}
		int	jacob = 3;
		int	level = 0;
		while (!pend.empty())
		{
			size_t nbElement = getJacob(jacob) - getJacob(jacob - 1);
			nbElement = std::min(nbElement, pend.size());
			for (size_t i = 0; i < nbElement; ++i)
			{
				size_t	limit = getJacob(jacob + level) - i;
				std::vector<int>::iterator	stop = limit <= main.size() ? main.begin() + limit : main.end();
				stop = std::upper_bound(main.begin(), stop, *(pend.begin() + nbElement - i - 1));
				main.insert(stop, *(pend.begin() + nbElement - i - 1));
				pend.erase(pend.begin() + nbElement - i - 1);
				level++;
			}
			jacob++;
		}
	}
	*/

void	PmergeMe::mergeVec(size_t& pairSize)
{
	std::cout << "pair s = " << pairSize << std::endl;
	if (pairSize < 1)
		return;
	std::vector<int>	main, pend, odd, ignored;
	std::vector<int>::iterator	oddit = m_vector.end() - (m_vector.size() % (pairSize * 2));
	std::vector<int>::iterator	ignorit = m_vector.end() - (m_vector.size() % pairSize);
	for (std::vector<int>::iterator it = m_vector.begin(); it < oddit; it += pairSize)
	{
		if (it == m_vector.begin())
			for (size_t i = 0; i < pairSize; ++i)
				main.push_back(*(it + i));
		else
			for (size_t i = 0; i < pairSize; ++i)
			pend.push_back(*(it + i));
		it += pairSize;
		for (size_t i = 0; i < pairSize; ++i)
			main.push_back(*(it + i));
	}
	for (;oddit < ignorit; oddit++)
		odd.push_back(*oddit);
	for (; ignorit < m_vector.end(); ignorit++)
		ignored.push_back(*ignorit);
	std::cout << "pend = ";
	printVec(pend);
	if (!pend.empty())
		mergePendVec(main, pend, pairSize);
	if (!odd.empty())
	{
		printVec(main);
		std::vector<int>::iterator stop = upper_bound_step(main.begin() + pairSize - 1, main.end() - 1, *(odd.begin() + pairSize - 1), pairSize);
		if (*(stop + pairSize - 1) < *(odd.begin() + pairSize - 1))
			stop = main.end();
		main.insert(stop, odd.begin(), odd.end());
//		main.insert(upper_bound_step(main.begin() + pairSize - 1, main.end(), *(odd.begin() + pairSize - 1), pairSize), odd.begin(), odd.end());
	}
	if (!ignored.empty())
		main.insert(main.end(), ignored.begin(), ignored.end());
	m_vector = main;
	pairSize /= 2;
	//	if (pairSize > 0)
	mergeVec(pairSize);
}
void	PmergeMe::swapVec(size_t& pairSize)
{
	if (m_vector.size() < pairSize * 2)
		return;
	size_t	offset = (m_vector.size() % (pairSize * 2)) + pairSize;
	std::vector<int>::iterator	it = m_vector.begin() + pairSize - 1;
	std::vector<int>::iterator	endit = m_vector.end() - offset;
	for (; it < endit; it += (pairSize * 2))
		if (*it > *(it + pairSize))
			for (size_t i = 0; i < pairSize; ++i)
				std::swap(*(it - pairSize + 1 + i), *(it + i + 1));
	pairSize *= 2;
	swapVec(pairSize);
}

void	PmergeMe::sortVec()
{
	size_t	pairSize = 1;
	swapVec(pairSize);
	displayVec();
	pairSize /= 2;
	mergeVec(pairSize);
}

void	PmergeMe::sort()
{
	std::cout << "Before:  ";
	displayList();
	std::clock_t	startVec = std::clock();
	sortVec();
	std::clock_t	endVec = std::clock();
	//	std::clock_t	startList = std::clock();
	//	sortList();
	//	std::clock_t	endList = std::clock();
	std::cout << "After:   ";
	//	displayList();
	displayVec();
	std::cout << "Time to process a range of " << m_vector.size() << " elements with std::vector: ";
	std::cout << 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " µs" << std::endl;
	//	std::cout << "Time to process a range of " << m_list.size() << " elements with std::list: ";
	//	std::cout << 1000000.0 * (endList - startList) / CLOCKS_PER_SEC << " µs" << std::endl;
}
