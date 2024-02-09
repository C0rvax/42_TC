/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:03:14 by aduvilla          #+#    #+#             */
/*   Updated: 2024/02/09 18:01:00 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	init_data(void)
{
	t_data	data;

	data.a.stack = NULL;
	data.a.size = 0;
	data.a.max = 0;
	data.b.stack = NULL;
	data.b.size = 0;
	data.b.max = 0;
	return (data);
}

static int	init_stack(t_data *data, int ac, char **av)
{
	char	**charlist;

	if (ac == 2)
	{
		charlist = ft_split(av[1], ' ');
		if (!charlist)
			return (ft_printf("Error\n"), 0);
	}
	else
		charlist = av + 1;
	data->a.size = 0;
	while (charlist[data->a.size])
		data->a.size++;
	data->a.stack = check_list(charlist, data->a.size);
	if (ac == 2)
		ft_freetab(charlist);
	if (!data->a.stack)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	if (ac < 2)
		return (0);
	data = init_data();
	if (!init_stack(&data, ac, av))
		return (1);
	i = 0;
	while (i < data.a.size)
	{
		ft_printf("a[%d] = %d\n", i, data.a.stack[i]);
		i++;
	}
	return (0);
}
