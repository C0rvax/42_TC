/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:03:35 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/21 13:06:24 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_unsigned(unsigned int n)
{
	int i;

	i = 0;
	if (n > 9)
	{
		i++;
		print_unsigned(n / 10);
	}
	i = i + print_putchar(n % 10 + '0');
	return (i);
}
