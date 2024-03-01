/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/01 14:31:24 by aduvilla         ###   ########.fr       */
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
		{
			j++;
			if (!av[i][j])
				return (0);
		}
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

static int	check_max(char **tab)
{
	int		i;
	char	*max;
	size_t	len;

	i = 0;
	len = 10;
	max = "+2147483647";
	while (tab[i])
	{
		if (tab[i][0] != '-')
		{
			if (tab[i][0] == '+')
				len++;
			if (ft_strlen(tab[i]) > len)
				return (ft_putstr_fd("Error\n", 2), 0);
			else if (ft_strlen(tab[i]) == len)
			{
				if ((len == 10 && ft_strncmp(tab[i], "2147483647", 10) > 0)
					|| (len == 11 && ft_strncmp(tab[i], max, 11) > 0))
					return (ft_putstr_fd("Error\n", 2), 0);
			}
		}
		i++;
	}
	return (1);
}

static int	check_min(char **tab)
{
	int		i;
	char	*min;

	i = 0;
	min = "-2147483648";
	while (tab[i])
	{
		if (tab[i][0] == '-')
		{
			if (ft_strlen(tab[i]) > 11)
				return (ft_putstr_fd("Error\n", 2), 0);
			else if (ft_strlen(tab[i]) == 11)
			{
				if (ft_strncmp(tab[i], min, 11) > 0)
					return (ft_putstr_fd("Error\n", 2), 0);
			}
		}
		i++;
	}
	return (1);
}

int	*check_list(char **args, int size)
{
	int		i;
	int		*a;

	if (!check_int(args, size))
		return (ft_putstr_fd("Error\n", 2), NULL);
	if (!check_min(args) || !check_max(args))
		return (NULL);
	a = malloc(sizeof(int) * size);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		a[i] = ft_atoi(args[i]);
		i++;
	}
	if (!check_dup(a, size))
		return (ft_putstr_fd("Error\n", 2), free(a), NULL);
	return (a);
}
