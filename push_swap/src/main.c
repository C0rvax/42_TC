/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:13:55 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 12:09:23 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
int	main()
{
	int i;
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
	while (list)
	{
		if (list->content == 9999)
			ft_printf("i : %d\n", list->content);
		list = list->next;
	}
	return (0);
}
*/
