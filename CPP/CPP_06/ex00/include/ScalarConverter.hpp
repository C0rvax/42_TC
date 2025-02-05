/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:19 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 20:42:12 by aduvilla         ###   ########.fr       */
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
		static void	convert(const std::string& str);

	private:	
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter &operator=(const ScalarConverter& rhs);
		~ScalarConverter();
};

#endif  /* __SCALARCONVERTER_HPP__ */
