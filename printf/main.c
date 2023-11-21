/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:21:29 by aduvilla          #+#    #+#             */
/*   Updated: 2023/11/21 16:45:48 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main()
{
	int i;

	i = 0;
	i = ft_printf("le code marche avec que du texte !\n");
	printf("taille : %i\n", i);
	i = ft_printf("avec %d decimal et %i int\n", 1, 1);
	printf("taille : %i\n", i);
}
