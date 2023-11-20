/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:34:42 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/20 17:54:14 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int	i;
	int	count;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 's' || s[i + 1] == 'd' || s[i + 1])
				count = count + ifforest(s[i + 1], arg);
			else if (s[i + 1] == '%')
			{
				print_putchar('%');
				count++;
			}
			else
			{
				print_putchar(s[i]);
				print_putchar(s[i + 1]);
				count = count + 2;
			}
			i = i + 2;
		}
		else
		{
			print_putchar(s[i]);
			count++;
			i++;
		}
	}
	va_end(arg);
	return (count);
}
