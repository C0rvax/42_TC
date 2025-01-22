/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:28:58 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 18:52:42 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
template <typename T>
class	Array
{
	private:
	T*				m_array;
	size_t	m_size;

	public:
	Array() : m_array(NULL), m_size(0) {}

	~Array() { delete [] m_array; }

	Array(unsigned int n) : m_array(new T[n]), m_size(static_cast<size_t>(n)) {}

	size_t	size() const { return m_size; }

	Array(const Array& src)
	{
		m_array = new T[src.size()];
		m_size = src.size();
		for (size_t i = 0; i < m_size; i++)
			m_array[i] = src.m_array[i];
	}

	Array&	operator=(const Array& rhs)
	{
		if (this != &rhs)
		{
			delete [] m_array;
			m_array = new T[rhs.size()];
			m_size = rhs.size();
			for (size_t i = 0; i < m_size; i++)
				m_array[i] = rhs.m_array[i];
		}
	}

	T&	operator[](size_t index)
	{
		if (index >= m_size)
			throw std::runtime_error("Out of Bound");
		return m_array[index];
	}

};
#endif
