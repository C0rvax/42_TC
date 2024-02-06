/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 19:20:59 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!av)
		return (0);
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ft_printf("ici\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*check_list(char **av, int ac)
{
	int		i;
	int		*a;

	if (!check_int(av, ac))
	{
		ft_printf("error\n");
		return (NULL);
	}
	a = malloc(sizeof(int) * (ac - 1));
	if (!a)
		return (NULL);
	i = 0;
	ft_printf("ac = %d\n", ac);
	while (i < ac - 1)
	{
		ft_printf("av : %s\n", av[i + 1]);
		a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (a);
}
