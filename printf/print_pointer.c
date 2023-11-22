/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:48:33 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/22 16:24:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_hexp(size_t n)
{
	char	*base;
	size_t	power;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	power = 1;
	while (power * 16 <= n)
		power *= 16;
	while (power)
		{
			count += print_putchar(base[n / power]);
			n = n % power;
			power /= 16;
		}
	return (count);
}


int	print_pointer(void *ptr)
{
	int	i;

	i = 0;
	i = print_hexp((size_t)ptr);
	return (i);
}
