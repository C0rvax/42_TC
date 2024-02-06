/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:13:55 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 16:54:35 by aduvilla         ###   ########.fr       */
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
	t_lst	*list;
	t_lst	*new;
	time_t	sec;
	time_t	sec2;

	i = 0;
	maxi = 100000000;
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
	while (list)
	{
		if (list->content == 9999)
			ft_printf("i : %d\n", list->content);
		list = list->next;
	}
	time(&sec2);
	ft_printf("parcours liste : %d\n", sec2 - sec);
	time(&sec);
	j = 1;
	while (tab[j])
	{
		if (tab[j] == 9999)
			ft_printf("j : %d\n", tab[j]);
		j++;
	}
	time(&sec2);
	ft_printf("parcours tableau : %d\n", sec2 - sec);
	return (0);
}
