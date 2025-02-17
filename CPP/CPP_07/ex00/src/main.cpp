/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:48:32 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/17 10:30:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main()
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
	std::cout << "max( a, b ) = " << ::max( a, b ) << "\n";
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap( c, d );
	std::cout << "\nc = " << c << ", d = " << d << "\n";
	std::cout << "min( c, d ) = " << ::min( c, d ) << "\n";
	std::cout << "max( c, d ) = " << ::max( c, d ) << "\n";

	float	e = 42.2;
	float	f = 41.8;

	::swap(e, f);
	std::cout << "\ne = " << e << ", f = " << f << "\n";
	std::cout << "min( e, f ) = " << ::min( e, f ) << "\n";
	std::cout << "max( e, f ) = " << ::max( e, f ) << "\n";
	return 0;
}
