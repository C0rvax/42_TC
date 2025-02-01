/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:13 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/01 17:43:19 by aduvilla         ###   ########.fr       */
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
	int					m_isOdd;

	void	swapVec(size_t& pairSize);
	void	mergeVec(size_t& pairSize);
	void	mergePendVec(std::vector<int>& main, std::vector<int>& pend, size_t& pairSize);
	void	sortVec();
	void	swapList(size_t& pairSize);
	void	mergeList(size_t& pairSize);
	void	mergePendList(std::list<int>& main, std::list<int>& pend);
	void	sortList();
	void	displayVec() const;
	void	displayList() const;
};

void	printVec(const std::vector<int>& vec);
long	getJacob(int n);
std::vector<int>::iterator upper_bound_step(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, size_t step);

#endif /* __PMERGEME_HPP__ */
