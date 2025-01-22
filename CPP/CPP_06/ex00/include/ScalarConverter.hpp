/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:19 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/22 14:28:14 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOATING_POINT,
	LITERAL,
	NONE
};

class	ScalarConverter
{
	public:
		static void	convert(std::string const & str);

	private:	
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const & rhs);
		~ScalarConverter(void);
};

#endif  /* __SCALARCONVERTER_HPP__ */
