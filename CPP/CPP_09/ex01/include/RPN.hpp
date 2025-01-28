/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:10:54 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/29 00:01:30 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class	RPN
{
	public:
	RPN(void);
	RPN(RPN const & src);
	RPN &operator=(RPN const & rhs);
	~RPN(void);
	int	calculate(const std::string& input);
	void	doTheMath(const char& token);

	private:
	std::stack<int>	m_stack;
};

#endif
