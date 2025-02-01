
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
		std::list<int>::iterator next_it = it;
		std::advance(next_it, pairSize);
		if (*it > *next_it)
			for (size_t i = 0; i < pairSize; ++i)
			{
				std::list<int>::iterator previt = it;
				std::advance(previt, -(pairSize - 1 - i));
				std::list<int>::iterator nextit = it;
				std::advance(nextit, i + 1);
				std::swap(*previt, *nextit);
			}
		if (static_cast<size_t>(std::distance(it, endit)) < pairSize * 2)
			break;
	}
	pairSize *= 2;
	swapList(pairSize);
}


void	PmergeMe::mergePendList(std::list<int>& main, std::list<int>& pend)
{
	if (pend.size() < 2)
		main.insert(std::upper_bound(main.begin(), main.end(), *pend.begin()), pend.begin(), pend.end());
	else
	{
		int	jacob = 3;
		int	nbInserted = 0;
		while (!pend.empty())
		{
			size_t nbElement = getJacob(jacob) - getJacob(jacob - 1);
			nbElement = std::min(nbElement, pend.size());
			for (size_t i = 0; i < nbElement; ++i)
			{
				size_t	limit = getJacob(jacob + nbInserted) - i;
				std::list<int>::iterator	stop = main.begin();
				if (limit <= main.size())
					std::advance(stop, limit);
				else
					stop = main.end();
				std::list<int>::iterator pendit = pend.begin();
				std::advance(pendit, nbElement - i - 1);
				stop = std::upper_bound(main.begin(), stop, *pendit);
				main.insert(stop, *(pendit));
				pend.erase(pendit);
				nbInserted++;
			}
			jacob++;
		}
	}
}

void	PmergeMe::mergeList(size_t& pairSize)
{
	if (pairSize == 0)
		return;
	std::list<int>	main, pend, odd, ignored;
	std::list<int>::iterator	oddit = m_list.end();
	std::advance(oddit, -(m_list.size() % (pairSize * 2)));
	std::list<int>::iterator	ignorit = m_list.end();
	std::advance(ignorit,  -(m_list.size() % pairSize));
	for (std::list<int>::iterator it = m_list.begin(); it != oddit; std::advance(it, pairSize))
	{
		if (it == m_list.begin())
			for (size_t i = 0; i < pairSize; ++i)
				main.push_back(*(it++));
		else
			for (size_t i = 0; i < pairSize; ++i)
				pend.push_back(*(it++));
//		std::advance(it, pairSize);
		for (size_t i = 0; i < pairSize; ++i)
			main.push_back(*(it++));
		if (static_cast<size_t>(std::distance(--it, oddit)) < pairSize * 2)
			break;
	}
	for (;oddit != ignorit; oddit++)
		odd.push_back(*oddit);
	for (; ignorit != m_list.end(); ignorit++)
		ignored.push_back(*ignorit);
	if (!pend.empty())
		mergePendList(main, pend);
	if (!odd.empty())
		main.insert(std::upper_bound(main.begin(), main.end(), *odd.begin()), odd.begin(), odd.end());
	if (!ignored.empty())
		main.insert(main.end(), ignored.begin(), ignored.end());
	m_list = main;
	pairSize /= 2;
	mergeVec(pairSize);
}

void	PmergeMe::sortList()
{
	size_t	pairSize = 1;
	swapList(pairSize);
	pairSize /= 2;
	mergeList(pairSize);
}
