/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:21 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/04 09:40:16 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main (void)
{
	Point	a;
	Point	d(5, 18.5f);
	Point	c(-2.4f, 18.5f);
	Point	b( d );
	Point	in(4, 15.2f);
	Point	out(-0.1f, 115.3f);
	Point	justIn(1, 3.71f);
	Point	justOut(1, 3.7f);
	Point	above(0, 18.51f);

	std::cout << "in is inside abc: " << (bsp(a, b, c, in) ? "true" : "false") << std::endl;
	std::cout << "out is inside abc: " << (bsp(a, b, c, out) ? "true" : "false") << std::endl;
	std::cout << "justIn is inside abc: " << (bsp(a, b, c, justIn) ? "true" : "false") << std::endl;
	std::cout << "justOut is inside abc: " << (bsp(a, b, c, justOut) ? "true" : "false") << std::endl;
	std::cout << "above is inside abc: " << (bsp(a, b, c, above) ? "true" : "false") << std::endl;
	return 0;
}
