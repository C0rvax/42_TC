/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:03:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/07 22:13:32 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		*a;
	int		size_list;
	char	**tab;

	tab = NULL;
	if (ac < 2)
		return (0);
	size_list = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (0);
		while (tab[size_list])
			size_list++;
	}
	else
	{
		av++;
		tab = av;
		size_list = ac - 1;
	}
	a = check_list(tab, size_list);
	if (!a)
		return (1);
	i = 0;
	while (i < size_list)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	return (0);
}
