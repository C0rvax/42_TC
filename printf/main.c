/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:21:29 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/23 13:03:17 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	int	i;
	char *ptr = "hello";

	i = 0;
	i = ft_printf(0);
	printf("taille : %i\n", i);
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
	i = ft_printf(" NULL %s NULL ", NULL);
	printf("taille : %i\n", i);
//	i = printf(" NULL %s NULL ", (char *)NULL);
	printf("taille : %i\n", i);
	i = ft_printf("avec les unsigned %u\n", -25);
	printf("taille : %i\n", i);
	i = printf("avec les unsigned %u\n", -25);
	printf("taille : %i\n", i);
	i = ft_printf("avec les adresses de pointeurs : %p\n", ptr);
	printf("taille : %i\n", i);
	i = printf("avec les adresses de pointeurs : %p\n", ptr);
	printf("taille : %i\n", i);
	i = ft_printf("avec les adresses de pointeurs : %p\n", 0);
	printf("taille : %i\n", i);
	i = printf("avec les adresses de pointeurs : %p\n", (void *)0);
	printf("taille : %i\n", i);
	i = printf("avec les adresses de pointeurs : %p\n", (void *)LONG_MAX);
	printf("taille : %i\n", i);
	i = ft_printf("avec les adresses de pointeurs : %p\n", LONG_MAX);
	printf("taille : %i\n", i);
}
