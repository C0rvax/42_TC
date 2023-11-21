/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:21:29 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/21 18:30:43 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	i;

	i = 0;
	i = ft_printf("le code marche avec que du texte !\n");
	printf("taille : %i\n", i);
	i = ft_printf("avec %d decimal et %i int\n", 256, 381);
	printf("taille : %i\n", i);
	i = printf("avec %d decimal et %i int\n", 256, 381);
	printf("taille : %i\n", i);
	i = ft_printf("avec %x hex min %X hex max\n", 256, -4281);
	printf("taille : %i\n", i);
	i = printf("avec %x hex min %X hex max\n", 256, -4281);
	printf("taille : %i\n", i);
	i = ft_printf("avec %s string\n", "toute les");
	printf("taille : %i\n", i);
	i = ft_printf("avec %s string\n", "toute les");
	printf("taille : %i\n", i);
}
