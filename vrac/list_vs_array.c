/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_vs_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:13:55 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/09 09:16:43 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

/*
int	main()
{
	int		i;
	t_lst	*list;
	t_lst	*new;

	i = 0;
	list = NULL;
	new = NULL;
	while (i < 100000)
	{
		new = ft_listnew(i);
		ft_listadd_back(&list, new);
		i++;
	}
	int	j;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * 100000);
	if (!tab)
		return (1);
	while (j < 100000)
	{
		tab[j] = j;
		j++;
	}
	tab[j] = 0;
	ft_printf("ici \n");
	j = 1;
	while (tab[j])
	{
		if (tab[j] == 9999)
			ft_printf("j : %d\n", tab[j]);
		j++;
	}
	return (0);
}
*/
int	main()
{
	int i;
	int	maxi;
	int	rounds;
	t_lst	*list;
	t_lst	*new;
	t_lst	*copy;
	time_t	sec;
	time_t	sec2;

	i = 0;
	rounds = 1000000;
	maxi = 100000;
	list = NULL;
	new = NULL;
	time(&sec);
	while (i < maxi)
	{
		new = ft_listnew(i);
//		ft_listadd_back(&list, new);
		ft_listadd_front(&list, new);
		i++;
	}
	time(&sec2);
	ft_printf("creation liste : %d\n", sec2 - sec);
	ft_printf("i max : %d\n", list->content);
	int	j;
	int	*tab;

	time(&sec);
	j = 0;
	tab = malloc(sizeof(int) * maxi + 1);
	if (!tab)
		return (1);
	while (j < maxi)
	{
		tab[j] = j;
		j++;
	}
	tab[j] = 0;
	time(&sec2);
	ft_printf("creation tableau : %d\n", sec2 - sec);
	ft_printf("ici \n");
	time(&sec);
	i = 0;
	while (i < rounds)
	{
		copy = list;
		while (copy)
		{
			if (i == 9999 && copy->content == 9999)
				ft_printf("i : %d\n", copy->content);
			copy = copy->next;
		}
		i++;
	}
	time(&sec2);
	ft_printf("parcours liste : %d\n", sec2 - sec);
	time(&sec);
	i = 0;
	while (i < rounds)
	{
		j = 1;
		while (tab[j])
		{
			if (i == 9999 && tab[j] == 9999)
				ft_printf("j : %d\n", tab[j]);
			j++;
		}
		i++;
	}
	time(&sec2);
	ft_printf("parcours tableau : %d\n", sec2 - sec);
	return (0);
}
