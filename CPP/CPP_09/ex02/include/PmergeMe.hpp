/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:13 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/30 11:05:19 by aduvilla         ###   ########.fr       */
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
	void	mergePendVec(std::vector<int>& main, std::vector<int>& pend);
	void	sortVec();
	void	swapList(size_t& pairSize);
	void	mergeList();
	void	sortList();
	void	displayVec() const;
	void	displayList() const;
};

void	printVec(const std::vector<int>& vec);
size_t	getJacob(int n);

#endif /* __PMERGEME_HPP__ */
