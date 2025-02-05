/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:10:47 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 16:30:10 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class	Span
{
	public:
	Span();
	Span(const unsigned int& N);
	Span(const Span& src);
	Span &operator=(const Span& rhs);
	~Span();

	void			addNumber(const int& value);
	void			addManyNumbers(const unsigned int& number, const int& value, const unsigned int& offset = 1);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	private:
	unsigned int		m_size;
	std::vector<int>	m_vector;
		
};
#endif
