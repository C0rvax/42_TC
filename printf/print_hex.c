/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:50:54 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/21 15:04:35 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hex(int nbr, int mode)
{
	char	*basel;
	char	*baseu;
	int		i;

	i = 0;
	basel = "0123456789abcdef";
	baseu = "0123456789ABCDEF";
	if (nbr < 0)
	{
		i = i + print_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 16)
	{
		print_hex((nbr / 16), mode);
		if (mode == 1)
			i = i + print_putchar(baseu[nbr % 16]);
		else
			i = i + print_putchar(basel[nbr % 16]);
	}
	else
	{
		if (mode == 1)
			i = i + print_putchar(baseu[nbr]);
		else
			i = i + print_putchar(basel[nbr]);
	}
	return (i);
}
