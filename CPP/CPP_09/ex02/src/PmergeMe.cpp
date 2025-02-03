/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:12 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/03 23:58:57 by aduvilla         ###   ########.fr       */
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

void	printList(const std::list<int>& list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		if (it != list.begin())
			std::cout << " ";
		std::cout << *it;
	}
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

long	getJacob(int n)
{
	return round((pow(2, n) - pow(-1, n)) / 3);
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
		m_vector.push_back(static_cast<int>(number));
		m_list.push_back(static_cast<int>(number));
	}
}

std::list<int>::iterator	upperBoundStep(std::list<int>& list, size_t size, int value, size_t step)
{
	std::list<int>::iterator first = list.begin();
	std::advance(first, step - 1);
	std::list<int>::iterator last = list.begin();
	std::advance(last, size);
	while (first != last)
	{
		std::list<int>::iterator mid = first;
		std::advance(mid, ((std::distance(first, last) / (2 * step)) * step));
		if (*mid > value)
			last = mid;
		else
		{
			first = mid;
			std::advance(first, step);
		}
	}
	std::advance(first, 1 - step);
	return first;
}

void	PmergeMe::mergePendList(std::list<int>& main, std::list<int>& pend, const size_t& pairSize)
{
	if (pend.size() / pairSize < 2)
	{
		std::list<int>::iterator element = pend.begin();
		std::advance(element, pairSize - 1);
		std::list<int>::iterator insertPoint = upperBoundStep(main, main.size(), *element, pairSize);
		main.insert(insertPoint, pend.begin(), pend.end());
	}
	else
	{
		int	jacob = 3;
		int	inserted = 0;
		while (!pend.empty())
		{
			long nbElement = getJacob(jacob) - getJacob(jacob - 1);
			nbElement = std::min(nbElement, static_cast<long>(pend.size()) / static_cast<long>(pairSize));
			for (long i = 0; i < nbElement; ++i)
			{
				size_t limit = std::min(((getJacob(jacob) + inserted - i + 1) * pairSize - 1), main.size());
				std::list<int>::iterator	element = pend.begin();
				std::advance(element, ((nbElement - i) * pairSize) - 1);
				std::list<int>::iterator insertPoint = upperBoundStep(main, limit, *element, pairSize);
				std::list<int>::iterator rangeStart = element;
				std::advance(element, 1);
				std::advance(rangeStart, 1 - pairSize);
				main.insert(insertPoint, rangeStart, element);
				pend.erase(rangeStart, element);
				inserted++;
			}
			jacob++;
		}
	}
}

void	PmergeMe::mergeOddList(std::list<int>& main, std::list<int>& odd, const size_t& pairSize)
{
	std::list<int>::iterator element = odd.begin();
	std::advance(element, pairSize - 1);
	std::list<int>::iterator stop = upperBoundStep(main, main.size() - 1, *element, pairSize);
	std::list<int>::iterator stopElement = stop;
	std::advance(stopElement, pairSize - 1);
	if (*stopElement < *element)
		stop = main.end();
	main.insert(stop, odd.begin(), odd.end());
}

void	PmergeMe::mergeList(size_t& pairSize)
{
	if (pairSize < 1)
		return;
	std::list<int>	main, pend, odd, ignored;
	std::list<int>::iterator	oddit = m_list.end();
	std::advance(oddit, -(m_list.size() % (pairSize * 2)));
	std::list<int>::iterator	ignorit = m_list.end();
	std::advance(ignorit, -(m_list.size() % pairSize));
	for (std::list<int>::iterator it = m_list.begin(); it != oddit; std::advance(it, 1))
	{
		if (it == m_list.begin())
			for (size_t i = 0; i < pairSize; ++i, std::advance(it, 1))
				main.push_back(*it);
		else
			for (size_t i = 0; i < pairSize; ++i, std::advance(it, 1))
				pend.push_back(*it);
		for (size_t i = 0; i < pairSize; ++i, std::advance(it, 1))
			main.push_back(*(it));
		if (static_cast<size_t>(std::distance(--it, oddit)) < pairSize * 2)
			break;
	}
	for (;oddit != ignorit; ++oddit)
		odd.push_back(*oddit);
	for (; ignorit != m_list.end(); ++ignorit)
		ignored.push_back(*ignorit);
	if (!pend.empty())
		mergePendList(main, pend, pairSize);
	if (!odd.empty())
		mergeOddList(main, odd, pairSize);
	if (!ignored.empty())
		main.insert(main.end(), ignored.begin(), ignored.end());
	m_list = main;
	pairSize /= 2;
	mergeList(pairSize);
}

void	PmergeMe::swapList(size_t& pairSize)
{
	if (m_list.size() < pairSize * 2)
		return;
	size_t	offset = (m_list.size() % (pairSize * 2)) + pairSize;
	std::list<int>::iterator	it = m_list.begin();
	std::advance(it, pairSize - 1);
	std::list<int>::iterator	endit = m_list.end();
	std::advance(endit, -offset);
	for (; it != endit; std::advance(it, pairSize * 2))
	{
	  std::list<int>::iterator nextIt = it;
	  std::advance(nextIt, pairSize);
		if (*it > *(nextIt))
		{
			for (size_t i = 0; i < pairSize; ++i)
			{
				std::list<int>::iterator first = it;
				std::advance(first, -pairSize + 1 + i);
				std::list<int>::iterator second = it;
				std::advance(second, i + 1);
				std::swap(*first, *second);
			}
		}
		if (static_cast<size_t>(std::distance(it, endit)) < pairSize * 2)
			break;
	}
	pairSize *= 2;
	swapList(pairSize);
}

void	PmergeMe::sortList()
{
	size_t	pairSize = 1;
	swapList(pairSize);
	pairSize /= 2;
	mergeList(pairSize);
}

std::vector<int>::iterator	upperBoundStep(std::vector<int>& vec, size_t size, int value, size_t step)
{
	std::vector<int>::iterator first = vec.begin() + step - 1;
	std::vector<int>::iterator last = vec.begin() + size;
	while (first != last)
	{
		std::vector<int>::iterator mid = first + ((last - first) / (2 * step)) * step;
		if (*mid > value)
			last = mid;
		else
		 first = mid + step;
	}
	return first - step + 1;
}

void	PmergeMe::mergePendVec(std::vector<int>& main, std::vector<int>& pend, const size_t& pairSize)
{
	if (pend.size() / pairSize < 2)
		main.insert(upperBoundStep(main, main.size(), *(pend.begin() + pairSize - 1), pairSize), pend.begin(), pend.end());
	else
	{
		int	jacob = 3;
		int	inserted = 0;
		while (!pend.empty())
		{
			long nbElement = getJacob(jacob) - getJacob(jacob - 1);
			nbElement = std::min(nbElement, static_cast<long>(pend.size()) / static_cast<long>(pairSize));
			for (long i = 0; i < nbElement; ++i)
			{
				size_t limit = std::min(((getJacob(jacob) + inserted - i + 1) * pairSize - 1), main.size());
				std::vector<int>::iterator	element = pend.begin() + ((nbElement - i) * pairSize) - 1;
				std::vector<int>::iterator insertPoint = upperBoundStep(main, limit, *element, pairSize);
				main.insert(insertPoint, element - pairSize + 1, element + 1);
				for (size_t i = 0; i < pairSize; ++i)
					pend.erase(element - i);
				inserted++;
			}
			jacob++;
		}
	}
}

void	PmergeMe::mergeVec(size_t& pairSize)
{
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
	if (!pend.empty())
		mergePendVec(main, pend, pairSize);
	if (!odd.empty())
	{
		std::vector<int>::iterator stop = upperBoundStep(main, main.size() - 1, *(odd.begin() + pairSize - 1), pairSize);
		if (*(stop + pairSize - 1) < *(odd.begin() + pairSize - 1))
			stop = main.end();
		main.insert(stop, odd.begin(), odd.end());
	}
	if (!ignored.empty())
		main.insert(main.end(), ignored.begin(), ignored.end());
	m_vector = main;
	pairSize /= 2;
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
	std::clock_t	startList = std::clock();
	sortList();
	std::clock_t	endList = std::clock();
	std::cout << "After:   ";
//	displayList();
	displayVec();
	std::cout << "Time to process a range of " << m_vector.size() << " elements with std::vector: ";
	std::cout << 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " µs" << std::endl;
	std::cout << "Time to process a range of " << m_list.size() << " elements with std::list: ";
	std::cout << 1000000.0 * (endList - startList) / CLOCKS_PER_SEC << " µs" << std::endl;
}
