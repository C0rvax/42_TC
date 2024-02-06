/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 20:29:34 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
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
	ft_printf("ac : %d\n", ac);
	a = malloc(sizeof(int) * ac);
	if (!a)
		return (NULL);
	i = 0;
	ft_printf("ac = %d\n", ac);
	while (i < ac)
	{
		ft_printf("av : %s\n", av[i]);
		a[i] = ft_atoi(av[i]);
		i++;
	}
	return (a);
}
