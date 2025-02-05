/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:25 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 11:47:29 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits.h>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

Span::Span	(void)
{
	m_size = 0;
}

Span::Span(const unsigned int& N) : m_size(N)
{
	m_vector.reserve(m_size);
}

Span::Span	(Span const & src)
{
	*this = src;
}

Span&	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		m_size = rhs.m_size;
		if (!m_vector.empty())
			m_vector.clear();
		m_vector.reserve(m_size);
		m_vector = rhs.m_vector;
	}
	return *this;
}

Span::~Span	(void)
{
}

void	Span::addNumber(const int& value)
{
	if (m_vector.size() + 1 > m_size)
		throw std::overflow_error("Error: Number max of elements reached");
	m_vector.push_back(value);
}

void	Span::addOffsetNumbers(const unsigned int& number, const int& value, const unsigned int& offset)
{
	if (m_vector.size() + number > m_size)
		throw std::overflow_error("Error: Number max of elements reached");
	for (size_t i = 0; i < number; i++)
		m_vector.push_back(value + i * offset);
}

void	Span::addManyNumbers(const unsigned int& number, const int& value)
{
	if (m_vector.size() + number > m_size)
		throw std::overflow_error("Error: Number max of elements reached");
	m_vector.insert(m_vector.end(), value);
}

unsigned int	Span::shortestSpan() const
{
	if (m_vector.size() < 2)
		throw std::logic_error("Error: Not enough values in vector");
	std::vector<int>	sorted(m_vector);
	std::sort(sorted.begin(), sorted.end());
	int	shortSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		shortSpan = std::min(shortSpan, sorted[i] - sorted[i - 1]);
	}
	return static_cast<unsigned int>(shortSpan);
}

unsigned int	Span::longestSpan() const
{
	if (m_vector.size() < 2)
		throw std::logic_error("Error: Not enough values in vector");
	unsigned int minS = *std::min_element(m_vector.begin(), m_vector.end());
	unsigned int maxS = *std::max_element(m_vector.begin(), m_vector.end());

	return maxS - minS;
}
