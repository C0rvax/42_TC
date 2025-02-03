/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:13 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/03 23:54:53 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstddef>
# include <vector>
# include <list>

class	PmergeMe
{
	public:
	PmergeMe(void);
	PmergeMe(PmergeMe const & src);
	PmergeMe &operator=(PmergeMe const & rhs);
	~PmergeMe(void);

	void	initParam(const int& ac, char** av);
	void	sort();

	private:
	std::vector<int>	m_vector;
	std::list<int>		m_list;

	void	sortVec();
	void	swapVec(size_t& pairSize);
	void	mergeVec(size_t& pairSize);
	void	mergePendVec(std::vector<int>& main, std::vector<int>& pend, const size_t& pairSize);
	void	displayVec() const;

	void	sortList();
	void	swapList(size_t& pairSize);
	void	mergeList(size_t& pairSize);
	void	mergePendList(std::list<int>& main, std::list<int>& pend, const size_t& pairSize);
	void	mergeOddList(std::list<int>& main, std::list<int>& odd, const size_t& pairSize);
	void	displayList() const;
};

void	printList(const std::list<int>& list);
void	printVec(const std::vector<int>& vec);
long	getJacob(int n);
std::vector<int>::iterator	upperBoundStep(std::vector<int>& vec, size_t size, int value, size_t step);
std::list<int>::iterator	upperBoundStep(std::list<int>& list, size_t size, int value, size_t step);

#endif /* __PMERGEME_HPP__ */
