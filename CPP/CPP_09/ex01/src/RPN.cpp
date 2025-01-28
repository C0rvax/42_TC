/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:05:53 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 23:42:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <string>

RPN::RPN	(void)
{
}

RPN::RPN	(RPN const & src)
{
	*this = src;
}

RPN&	RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
		m_stack = rhs.m_stack;
	return *this;
}

RPN::~RPN	(void)
{
}

void	RPN::doTheMath(const char& token)
{
	if (m_stack.size() < 2)
		throw std::runtime_error("Error: not enough operands");
	int	b = m_stack.top();
	m_stack.pop();
	int	a = m_stack.top();
	m_stack.pop();
	switch (token)
	{
		case '+':
			m_stack.push(a + b);
			break;
		case '-':
			m_stack.push(a - b);
			break;
		case '*':
			m_stack.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by 0");
			m_stack.push(a / b);
			break;
		default:
			throw std::runtime_error("Error: Unsupported operator");
	}
}

int		RPN::calculate(const std::string& input)
{
	std::istringstream	iss(input);
	std::string			token;
	while (iss >> token)
	{
		if (token.size() > 1)
			throw std::runtime_error("Error: too big token (1max)");
		if (isdigit(token[0]))
			m_stack.push(std::atoi(token.c_str()));
		else
			doTheMath(token[0]);
	}
	if (m_stack.size() != 1)
		throw std::runtime_error("Error: too many operands left");
	return m_stack.top();
}
