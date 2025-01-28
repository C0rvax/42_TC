/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:10:47 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 13:30:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class	Span
{
	public:
	Span(void);
	Span(const unsigned int& N);
	Span(Span const & src);
	Span &operator=(Span const & rhs);
	~Span(void);

	void			addNumber(const int& value);
	void			addManyNumbers(const unsigned int& number, const int& value);
	void			addOffsetNumbers(const unsigned int& number, const int& value, const unsigned int& offset);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	private:
	unsigned int		m_size;
	std::vector<int>	m_vector;
		
};
#endif
