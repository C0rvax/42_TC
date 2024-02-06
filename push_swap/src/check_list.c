/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/06 23:02:54 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char **av, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_dup(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*check_list(char **av, int size)
{
	int		i;
	int		*a;

	if (!check_int(av, size))
		return (ft_printf("Error\nint!\n"), NULL);
	a = malloc(sizeof(int) * size);
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		a[i] = ft_atoi(av[i]);
		i++;
	}
	if (!check_dup(a, size))
		return (ft_printf("Error\ndup!\n"), NULL);
	return (a);
}
