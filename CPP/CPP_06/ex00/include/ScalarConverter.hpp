/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/17 17:38:21 by aduvilla         ###   ########.fr       */
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
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const & rhs);
		~ScalarConverter(void);

		static void	convert(std::string const & str);

	private:	
		ScalarConverter(void);
};

#endif  /* __SCALARCONVERTER_HPP__ */
