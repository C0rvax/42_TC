/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

class	ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const & rhs);
		~ScalarConverter(void);

		static void	convert(std::string const & str);

	private:	
};

#endif  /* __SCALARCONVERTER_HPP__ */
