/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:12 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/21 17:13:56 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_number(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = print_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i = i + print_putchar('-');
	}
	if (n > 9)
	{
		//i++;
		print_number(n / 10);
	}
	i = i + print_putchar(n % 10 + '0');
	return (i);
}
