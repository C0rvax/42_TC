/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:27:58 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/04 11:27:55 by aduvilla         ###   ########.fr       */
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

static int	check_min_max(char **tab)
{
	int		i;
	char	*cpy;
	int		diff;

	i = 0;
	while (tab[i])
	{
		cpy = tab[i];
		if (*cpy == '-' || *cpy == '+')
			cpy++;
		while (*cpy == '0')
			cpy++;
		if (tab[i][0] == '-')
			diff = ft_strncmp(cpy, "2147483648", 10);
		else
			diff = ft_strncmp(cpy, "2147483647", 10);
		if (ft_strlen(cpy) > 10 || (ft_strlen(cpy) == 10 && diff > 0))
			return (ft_putstr_fd("Error\n", 2), 0);
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
	if (!check_min_max(args))
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
