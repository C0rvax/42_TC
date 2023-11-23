/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:48:33 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/23 18:13:36 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_hexp(unsigned long n)
{
	char	*base;
	unsigned long	power;
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

int	print_pointer(unsigned long ptr)
{
	int	i;

	if (!ptr)
		return (print_putstr("(nil)"));
	i = print_putstr("0x");
	i += print_hexp(ptr);
	return (i);
}
